<?php

/**
 * SoundCloud API wrapper for Drupal CMS.
 *
 * @category  Drupal Modules
 * @package   SoundCloud Sync
 * @author    Vlad Savitsky <vlad.savitsky@gmail.com>
 * @copyright 2015 Vlad Savitsky <vlad.savitsky@gmail.com>
 * @license   http://www.opensource.org/licenses/mit-license.php MIT
 * @link      https://github.com/VladSavitsky
 */
class SoundCloudTrack extends SoundCloudClient {

  // TODO: Store track id in field's instance.
  // TODO: Implement ability to get download link in node.

  /**
   * Stores response at lastest request to SoundCloud service.
   *
   * @var array
   * @access public
   */
  public $lastResponse = array();

  /**
   * Stores Track Id of the latest processed track.
   *
   * @var integer
   * @access public
   */
  public $lastTrackId = null;

  /**
   * Stores File Id of the latest processed file/track.
   *
   * @var integer
   * @access public
   */
  public $lastFid = null;

  /**
   * Stores latest request operation. Could be 'post', 'get', 'delete', 'put'.
   *
   * @var string
   * @access public
   */
  public $lastOperation = '';

  /**
   * Removes all tracks related to given node from SoundCloud.
   *
   * @param object $node
   *   Node object.
   *
   * @access public
   * @return void
   */
  public function deleteAll($node) {
    foreach ($this->fidsList($node) as $fid) {
      $this->delete($fid);
    }
  }

  /**
   * Removes given file from SoundCloud.
   *
   * @param integer $fid
   *   File ID.
   *
   * @access public
   */
  public function delete($fid) {
    $this->lastFid = $fid;
    $this->lastTrackId = $this->getTrackId($this->lastFid);
    if ($this->isTrackExist($this->lastTrackId)) {
      $this->apiCall('delete', 'tracks/' . $this->lastTrackId, array('track[id]' => $this->lastTrackId));
    }
    db_delete('soundcloud_tracks')->condition('fid', $this->lastFid)->execute();
  }

  /**
   * Upload one file to SoundCloud. New track will be created.
   *
   * @param object $node
   *   Node object.
   *
   * @access public
   * @return void
   */
  public function insert($fid, $params) {
    if (!is_array($params) && count($params) < 1) return;
    $this->lastFid = $fid;
    $params['track[asset_data]'] = new CurlFile($this->getAbsoluteFilePath($this->lastFid));
    $this->apiCall('post', 'tracks', $params);
    if ($this->lastTrackId) {
      // If we recieved TrackID we should store it in database.
      db_insert('soundcloud_tracks')
        ->fields(array(
          'fid' => $this->lastFid,
          'track_id' => $this->lastTrackId))
        ->execute();
    }
  }

  /**
   * Upload all tracks related to given node to SoundCloud.
   *
   * @param object $node
   *   Node object.
   *
   * @access public
   */
  public function insertAll($node) {
    foreach ($this->fidsList($node) as $fid) {
      $this->insert($fid, $this->buildParams($node));
    }
  }

  /**
   * Update one file at SoundCloud.com.
   * If track is not exist at SoundCloud.com it will be uploaded.
   *
   * @param integer $fid
   *   File ID.
   * @param array $params
   *   Parameters for SoundCloud API request.
   *
   * @access public
   */
  public function update($fid, $params) {
    if (!is_array($params) && count($params) < 1) return;
    $this->lastFid = $fid;
    // Get track ID from database by fid.
    $this->lastTrackId = $this->getTrackId($this->lastFid);

    if ($this->lastTrackId && $this->isTrackExist($this->lastTrackId)) {
      // If track still exists at SoundCloud.com we should only update it.
      $this->apiCall('put', 'tracks/' . $this->lastTrackId, $params);
      $this->message = t('Updated track');
    }
    else {
      $this->insert($fid, $params);
      $this->message = t('Uploaded track because it was missing.');
    }
  }

  /**
   * Update all tracks related to given node to SoundCloud.
   * If there is no track at SoundCloud file will be uploaded.
   *
   * @param object $node
   *   Node object.
   *
   * @access public
   */
  public function updateAll($node) {
    foreach ($this->fidsList($node) as $fid) {
      $this->lastFid = $fid;
      $this->update($fid, $this->buildParams($node));
    }
  }

  /**
   * Checks if track is present at SoundCloud.com
   *
   * @param integer $track_id
   *  SoundCloud Track ID.
   *
   * @access public
   * @return boolean
   *   Returns TRUE if track exists; returns FALSE if there is no track at SoundCloud.com
   */
  public function isTrackExist($track_id) {
    if (empty($track_id)) return FALSE;
    $is_exist = TRUE;
    try {
      $this->lastResponse = $this->service->get('tracks/' . $track_id);
    }
    catch (Services_Soundcloud_Invalid_Http_Response_Code_Exception $e) {
      $code = $e->getHttpCode();
      if ($code == 404 ) {
        watchdog('soundcloud', 'Track #' . $track_id . ' does NOT exist.');
        $is_exist = FALSE;
      }
      else {
        // TODO: send this messages to admins and do not disturb user.
        drupal_set_message($e->getMessage(), 'error');
        watchdog('soundcloud', 'Exception while check if track exists. ' . $e->getMessage());
        throw($e);
      }
    }
    // Finally
    if (isset($code) && $code == 404 ) {
      db_delete('soundcloud_tracks')->condition('track_id', $track_id)->execute();
      return $is_exist;
    }
    return $is_exist;
  }

  /**
   * Builds a list of fid for all syncable files in node.
   *
   * @param object $node
   * @access public
   * @return void Returns array of fid.
   */
  public function fidsList($node) {
    if (!is_object($node) || empty($node)) return;
    $fids_list = array();

    $fields = field_info_instances("node", $node->type);
    foreach ($fields as $field_name => $instance) {
      if ($this->isFieldSyncable($instance)) {
        $field_items = field_get_items('node', $node, $field_name);
        foreach ($field_items as $item) {
          $fids_list[] = $item['fid'];
        }
      }
    }

    return $fids_list;
  }

  /**
   * Returns Track Id for given File Id stored in local database.
   *
   * @param integer $fid
   *
   * @return void
   *   Returns SoundCloud's track ID or empty string if there is no record for given fid.
   */
  public function getTrackId($fid) {
    return db_select('soundcloud_tracks', 'sct')->fields('sct', array('track_id'))->condition('fid', $fid)->execute()->fetchField();
  }

  /**
   * Call SoundCloud Service API.
   *
   * @param string $op
   *   Operation on track. Could be 'post', 'get', 'delete', 'put.
   * @param string $path
   *   Resource path at SoundCloud.
   * @param array $params
   *   Required track's parameters.
   *
   * @access public
   * @return void
   */
  public function apiCall($op, $path, $params) {
    if (!$this->isConnected()) return;
    $this->lastOperation = $op;
    $this->lastResponse = '';
    try {
      watchdog('soundcloud_api', $op . ': ' . $path);
      $this->lastResponse = json_decode($this->service->$op($path, $params));
      // TODO: Any request with response code 0 means that service not reachable.
      // We should show message about that problem and use drupal queue to perform request later.
    }
    catch (Services_Soundcloud_Invalid_Http_Response_Code_Exception $e) {
      watchdog('soundcloud', $e->getMessage(), array(), WATCHDOG_ERROR);
      throw($e);
    }
    if ($op == 'post' && isset($this->lastResponse->id)) {
      $this->lastTrackId = $this->lastResponse->id;
    }
  }

  /**
   * Build an array of track's required parameters.
   *
   * @param object $node
   *   Node object.
   *
   * @access protected
   * @return array
   *   Returns a prepared array.
   */
  public function buildParams($node) {
    $list = $this->getFieldValue($node);

    // At least one tag is required
    $tag_list = implode(' ', array_map(
        function ($el) {return '"' . $el . '"';},
        array_merge(
          $list['field_program'],
          (!empty($list['field_author']) ? $list['field_author'] : array()),
          (!empty($list['field_guest']) ? $list['field_guest'] :  array())
          // TODO: 'field_tags,',
        )
      )
    );

    // TODO: Avoid hardcoded field name. Implement mapping at field settings page.
    $params = array(
      'track[title]'          => $node->title,
      'track[created_at]'     => format_date($node->created, 'custom', 'Y-m-d H:i:s'),
      'track[release_day]'    => format_date($node->created, 'custom', 'd'),
      'track[release_month]'  => format_date($node->created, 'custom', 'm'),
      'track[release_year]'   => format_date($node->created, 'custom', 'Y'),

      'track[description]'    => isset($list['body']) ? $list['body'] : '',
      //TODO: (only for uploading)
      'track[artwork_data]'   => $list['field_image'][0],
      'track[tag_list]'       => $tag_list,
      // TODO: Avoid hardcoded values here.
      'track[sharing]'        => 'public',
      'track[genre]'          => 'Podcast',
      'track[track_type]'     => 'spoken',
      'track[downloadable]'   => true,
      'track[license]'        => "all-rights-reserved",
    );

    return $params;
  }

  /**
   * Returns absolute path in local filesystem for given file.
   *
   * @param integer $fid
   *   File Id.
   * @access public
   * @return void
   */
  public function getAbsoluteFilePath($fid = 0) {
    if (!$fid) return;
    $file = file_load($fid);
    $uri = file_stream_wrapper_get_instance_by_uri($file->uri);
    return $uri->realpath();
  }

  /**
   * Obtain field's values of given node.
   *
   * @param object $node
   *   Node object.
   *
   * @access protected
   * @return array
   *   Returns an array of all fields attached to node.
   */
  protected function getFieldValue($node) {
    $list = array();
    $fields = field_info_instances("node", $node->type);

    // Get view mode first.
    $view_mode = 'full';
    foreach ($fields as $name => $instance) {
      if ($this->isFieldSyncable($instance)) {
        if (isset($instance['settings']['soundcloud'])) {
          $view_mode = $instance['settings']['soundcloud']['view_mode'];
          break;
        }
      }
    }

    foreach ($fields as $name => $instance) {
      $field_items = field_get_items('node', $node, $name);
      if (!is_array($field_items)) {
        $list[$name][] = '';
        continue;
      }
      foreach ($field_items as $item) {
        switch ($name) {
          case 'field_image':
            $list[$name][] = new CurlFile($this->getAbsoluteFilePath($item['fid']));
            break;
          case 'title':
            $list[$name] = strip_tags($item);
            break;
          case 'body':
            $output = field_view_field('node', $node, $name, $view_mode);
            $list[$name] = strip_tags(render($output));
            break;
          case 'field_program':
            if ($item['tid']) {
              $term = taxonomy_term_load($item['tid']);
              $list[$name][] = $term->name;
            }
            break;
          case 'field_guest':
            $list[$name][] = $item['name'];
            break;
          case 'field_author':
            $user = user_load($item['target_id']);
            $first_name = field_view_field('user', $user, 'field_first_name', $view_mode);
            $last_name = field_view_field('user', $user, 'field_last_name', $view_mode);
            $list[$name][] = $first_name[0]['#markup'] . ' ' . $last_name[0]['#markup'];
            break;
          default:
            $list[$name][] = $item;
            break;
        }
      }
    }

    if (!isset($list['field_image'])) {
      $list['field_image'][] = new CurlFile($this->getAbsoluteFilePath($fields['field_sound']['settings']['soundcloud']['default_image']));
    }

    return $list;
  }

  /**
   * Check if field was set for sync with SoundCloud.com
   *
   * @param array $instance Field instance.
   * @access public
   * @return void Returns TRUE if field was marked to be synced with SoundCloud.com and FALSE in other case.
   */
  public function isFieldSyncable($instance) {
    return (isset($instance['settings']['soundcloud']) && $instance['settings']['soundcloud']['enable'] == 1);
  }

}
