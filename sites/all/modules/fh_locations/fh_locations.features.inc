<?php
/**
 * @file
 * fh_locations.features.inc
 */

/**
 * Implements hook_node_info().
 */
function fh_locations_node_info() {
  $items = array(
    'location' => array(
      'name' => t('Location'),
      'base' => 'node_content',
      'description' => t('Freighthouse locations'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
