<?php


define('FEEDS_NODE_UNPUBLISH_ORPHANED', 1);
define('FEEDS_NODE_DELETE_ORPHANED', 2);


class FeedsNodeProcessorGC extends FeedsNodeProcessor {
  private $nids_in_feed = array();

  /**
   * Implementation of FeedsProcessor::process().
   *
   * This function has been copied from FeedsNodeProcessor, with a few changes to call
   * garbage collection. (Changes are marked with comments labeled "GC".)
   *
   * @see FeedsProcessor::process().
   */
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {
    $state = $source->state(FEEDS_PROCESS);

    while ($item = $parser_result->shiftItem()) {

      // GC: If there's an existing entity_id, store that.
      $entity_id = $this->existingEntityId($source, $parser_result);
      if (!empty($entity_id)) {
        $this->nids_in_feed[] = $entity_id;
      }

      if (!$entity_id || ($this->config['update_existing'] != FEEDS_SKIP_EXISTING)) {

        // Only proceed if item has actually changed.
        $hash = $this->hash($item);
        if (!empty($entity_id) && $hash == $this->getHash($entity_id)) {
          continue;
        }

        try {
          // Assemble node, map item to it, save.
          if (empty($entity_id)) {
            $entity = $this->newEntity($source);
            $this->newItemInfo($entity, $source->feed_nid, $hash);
          }
          else {
            $entity = $this->entityLoad($source, $entity_id);
            // The feeds_item table is always updated with the info for the most recently processed entity.
            // The only carryover is the entity_id.
            $this->newItemInfo($entity, $source->feed_nid, $hash);
            $entity->feeds_item->entity_id = $entity_id;
          }
          $this->map($source, $parser_result, $entity);
          $this->entityValidate($entity);

          // Allow modules to alter the entity before saving.
          module_invoke_all('feeds_presave', $source, $entity);
          /*if (module_exists('rules')) {
            rules_invoke_event('feeds_import_'. $source->importer()->id, $entity);
          }*/

          // Enable modules to skip saving at all.
          if (empty($entity->feeds_item->skip)) {
            $nid = $this->entitySave($entity);
            // Track progress.
            if (empty($entity_id)) {
              $state->created++;
              // GC: Store any new eids created.
              if (!in_array($entity_id, $this->nids_in_feed)) {
                $this->nids_in_feed[] = $nid;
              }
            }
            else {
              $state->updated++;
            }
          }
        }
        catch (Exception $e) {
          $state->failed++;
          drupal_set_message($e->getMessage(), 'warning');
          $message = $e->getMessage();
          $message .= '<h3>Original item</h3>';
          $message .= '<pre>' . var_export($item, TRUE) . '</pre>';
          $message .= '<h3>Entity</h3>';
          $message .= '<pre>' . var_export($entity, TRUE) . '</pre>';
          $source->log('import', $message, array(), WATCHDOG_ERROR);
        }
      }
    }

    // Set messages if we're done.
    if ($source->progressImporting() != FEEDS_BATCH_COMPLETE) {
      return;
    }

    $info = $this->entityInfo();
    $tokens = array(
      '@entity' => strtolower($info['label']),
      '@entities' => strtolower($info['label plural']),
    );
    $messages = array();
    if ($state->created) {
      $messages[] = array(
       'message' => format_plural(
          $state->created,
          'Created @number @entity.',
          'Created @number @entities.',
          array('@number' => $state->created) + $tokens
        ),
      );
    }
    if ($state->updated) {
      $messages[] = array(
       'message' => format_plural(
          $state->updated,
          'Updated @number @entity.',
          'Updated @number @entities.',
          array('@number' => $state->updated) + $tokens
        ),
      );
    }
    if ($state->failed) {
      $messages[] = array(
       'message' => format_plural(
          $state->failed,
          'Failed importing @number @entity.',
          'Failed importing @number @entities.',
          array('@number' => $state->failed) + $tokens
        ),
        'level' => WATCHDOG_ERROR,
      );
    }
    if (empty($messages)) {
      $messages[] = array(
        'message' => t('There are no new @entities.', array('@entities' =>                strtolower($info['label plural']))),
      );
    }
    foreach ($messages as $message) {
      drupal_set_message($message['message']);
      $source->log('import', $message['message'], array(), isset($message['level']) ?     $message['level'] : WATCHDOG_INFO);
    }

    // GC: Call garbage collector.
    $garbage_counts = $this->garbage($source->id, $source->feed_nid);
    // GC: Output garbage colleciton messages
    if ($garbage_counts['unpublished']) {
      drupal_set_message(t('Unpublished !number !type nodes.', array('!number' => $garbage_counts['unpublished'], '!type' => node_type_get_name($this->config['content_type']))));
    }
    if ($garbage_counts['published']) {
      drupal_set_message(t('Republished !number !type nodes.', array('!number' => $garbage_counts['published'], '!type' => node_type_get_name($this->config['content_type']))));
    }
    if ($garbage_counts['deleted']) {
      drupal_set_message(t('Deleted !number !type nodes.', array('!number' => $garbage_counts['deleted'], '!type' => node_type_get_name($this->config['content_type']))));
    }

  }

  /**
   * Collects garbage
   */
  public function garbage($importer_id, $feed_nid) {
    $counts = array(
      'unpublished' => 0,
      'published' => 0,
      'deleted' => 0,
    );

    // Get all published items from this feed that are not in this feed.
    $query = db_select('node', 'n');
    $query->leftJoin('feeds_item', 'fi', 'n.nid = fi.entity_id');
    $query->fields('n', array('nid'))
      ->condition('n.status', 1)
      ->condition('fi.id', $importer_id)
      ->condition('fi.feed_nid', $feed_nid);

    if (!empty($this->nids_in_feed)) {
      $query->condition('n.nid', $this->nids_in_feed, 'NOT IN');
    }

    $result = $query->execute();

    foreach ($result as $node) {
      switch ($this->config['orphaned_action']) {
        case FEEDS_NODE_UNPUBLISH_ORPHANED:
          // Unpublish and save.
          $node = node_load($node->nid);
          node_unpublish_action($node);
          node_save($node);
          $counts['unpublished']++;
          break;
        case FEEDS_NODE_DELETE_ORPHANED:
          // Delete.
          node_delete($node->nid);
          $counts['deleted']++;
          break;
      }
    }

    // Get all unpublished items that may be back in the feed.
    // Check for this only if the user chose to unpublish nodes in the first place.
    if (!empty($this->nids_in_feed) && $this->config['orphaned_action'] == FEEDS_NODE_UNPUBLISH_ORPHANED) {
      $query = db_select('node', 'n');
      $query->leftJoin('feeds_item', 'fi', 'n.nid = fi.entity_id');
      $query->fields('n', array('nid'))
        ->condition('fi.feed_nid', $feed_nid)
        ->condition('n.status', 0)
        ->condition('fi.id', $importer_id)
        ->condition('n.nid', $this->nids_in_feed, 'IN');
      $result = $query->execute();

      foreach ($result as $node) {
        //Republish and save.
        $node = node_load($node->nid);
        node_publish_action($node);
        node_save($node);
        $counts['published']++;
      }
    }

    return $counts;
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'orphaned_action' => FEEDS_NODE_UNPUBLISH_ORPHANED,
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    $form['orphaned_action'] = array(
      '#type' => 'select',
      '#title' => t('Action for orphaned nodes'),
      '#description' => t('<em>Orphaned nodes</em> are nodes which were created for feed items that once existed in the feed, but are no longer there.<br>Choose which action to perform on these nodes. <strong>Note:</strong> Choosing <em>Unpublish</em> means that the feed will try to re-publish the orphaned node, in case its corresponding feed item reappears in the feed.'),
      '#options' => array(
        FEEDS_NODE_UNPUBLISH_ORPHANED => 'Unpublish orphaned nodes',
        FEEDS_NODE_DELETE_ORPHANED => 'Delete orphaned nodes',
      ),
      '#default_value' => $this->config['orphaned_action'],
    );
    return $form;
  }

  /**
   * Save a node.
   */
  public function entitySave($entity) {
    // If nid is set and a node with that id doesn't exist, flag as new.
    if (!empty($entity->nid) && !node_load($entity->nid)) {
      $entity->is_new = TRUE;
    }
    node_save($entity);

    return $entity->nid;
  }
}
