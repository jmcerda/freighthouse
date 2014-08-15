<?php
/**
 * @file
 * fh_features.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function fh_features_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_links' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_links_2' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'book_navigation' => array(
      'weight' => '4',
      'label' => 'above',
      'format' => 'default',
    ),
  );
  $export['node|article|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function fh_features_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'about_the_author';
  $ds_field->label = 'about the author';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|about_the_author-block',
    'block_render' => '3',
  );
  $export['about_the_author'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'comments';
  $ds_field->label = 'comments';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'disqus|disqus_comments',
    'block_render' => '3',
  );
  $export['comments'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'follow';
  $ds_field->label = 'Follow';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'twitter_follow|twitter-follow-block',
    'block_render' => '3',
  );
  $export['follow'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'social_links';
  $ds_field->label = 'social links';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'service_links|service_links',
    'block_render' => '3',
  );
  $export['social_links'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'social_links_2';
  $ds_field->label = 'social links 2';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'service_links|service_links',
    'block_render' => '1',
  );
  $export['social_links_2'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function fh_features_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'submitted_by',
        1 => 'social_links',
        2 => 'field_image',
        3 => 'body',
        4 => 'book_navigation',
        5 => 'social_links_2',
        6 => 'field_tools',
        7 => 'field_tags',
        8 => 'field_industry',
        9 => 'comments',
      ),
    ),
    'fields' => array(
      'submitted_by' => 'ds_content',
      'social_links' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'book_navigation' => 'ds_content',
      'social_links_2' => 'ds_content',
      'field_tools' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_industry' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image_banner',
        1 => 'title',
        2 => 'workbench_access',
        3 => 'redirect',
        4 => 'path',
        5 => 'body',
      ),
      'hidden' => array(
        6 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_image_banner' => 'ds_content',
      'title' => 'ds_content',
      'workbench_access' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
      'body' => 'ds_content',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|webform|form'] = $ds_layout;

  return $export;
}
