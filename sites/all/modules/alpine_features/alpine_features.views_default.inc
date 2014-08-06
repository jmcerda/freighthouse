<?php
/**
 * @file
 * alpine_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function alpine_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'about_us';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'About Us';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'About Us';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['element_default_classes'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'about_us_thumbnail',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'about_us' => 'about_us',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['about_us'] = $view;

  $view = new view();
  $view->name = 'blog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_bl_category']['id'] = 'field_bl_category';
  $handler->display->display_options['fields']['field_bl_category']['table'] = 'field_data_field_bl_category';
  $handler->display->display_options['fields']['field_bl_category']['field'] = 'field_bl_category';
  $handler->display->display_options['fields']['field_bl_category']['label'] = '';
  $handler->display->display_options['fields']['field_bl_category']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bl_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bl_category']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bl_category']['delta_offset'] = '0';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_bl_description']['id'] = 'field_bl_description';
  $handler->display->display_options['fields']['field_bl_description']['table'] = 'field_data_field_bl_description';
  $handler->display->display_options['fields']['field_bl_description']['field'] = 'field_bl_description';
  $handler->display->display_options['fields']['field_bl_description']['label'] = '';
  $handler->display->display_options['fields']['field_bl_description']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bl_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bl_description']['element_default_classes'] = FALSE;
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_bl_multimedia']['id'] = 'field_bl_multimedia';
  $handler->display->display_options['fields']['field_bl_multimedia']['table'] = 'field_data_field_bl_multimedia';
  $handler->display->display_options['fields']['field_bl_multimedia']['field'] = 'field_bl_multimedia';
  $handler->display->display_options['fields']['field_bl_multimedia']['label'] = '';
  $handler->display->display_options['fields']['field_bl_multimedia']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bl_multimedia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bl_multimedia']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bl_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bl_multimedia']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_bl_multimedia']['delta_offset'] = '0';
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_bl_thumbnail']['id'] = 'field_bl_thumbnail';
  $handler->display->display_options['fields']['field_bl_thumbnail']['table'] = 'field_data_field_bl_thumbnail';
  $handler->display->display_options['fields']['field_bl_thumbnail']['field'] = 'field_bl_thumbnail';
  $handler->display->display_options['fields']['field_bl_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_bl_thumbnail']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bl_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bl_thumbnail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bl_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bl_thumbnail']['settings'] = array(
    'image_style' => 'blog_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_bl_thumbnail']['delta_offset'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F d, Y';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_type'] = '0';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_type'] = 'div';
  $handler->display->display_options['fields']['picture']['element_class'] = 'post-avatar';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'user_avatar';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['blog'] = $view;

  $view = new view();
  $view->name = 'categories_sidebar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Categories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Categories Sidebar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'portfolio_taxonomy' => 'portfolio_taxonomy',
  );

  /* Display: Categories */
  $handler = $view->new_display('block', 'Categories', 'block');
  $export['categories_sidebar'] = $view;

  $view = new view();
  $view->name = 'contact';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contact';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_contact_description']['id'] = 'field_contact_description';
  $handler->display->display_options['fields']['field_contact_description']['table'] = 'field_data_field_contact_description';
  $handler->display->display_options['fields']['field_contact_description']['field'] = 'field_contact_description';
  $handler->display->display_options['fields']['field_contact_description']['label'] = '';
  $handler->display->display_options['fields']['field_contact_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_contact_description']['element_type'] = '0';
  $handler->display->display_options['fields']['field_contact_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_description']['element_default_classes'] = FALSE;
  /* Field: Webform: Webform form body */
  $handler->display->display_options['fields']['webform_form_body']['id'] = 'webform_form_body';
  $handler->display->display_options['fields']['webform_form_body']['table'] = 'node';
  $handler->display->display_options['fields']['webform_form_body']['field'] = 'webform_form_body';
  $handler->display->display_options['fields']['webform_form_body']['label'] = '';
  $handler->display->display_options['fields']['webform_form_body']['element_type'] = '0';
  $handler->display->display_options['fields']['webform_form_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_form_body']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'webform' => 'webform',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['contact'] = $view;

  $view = new view();
  $view->name = 'feedback';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Feedback';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Your Feedback';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Company */
  $handler->display->display_options['fields']['field_fb_company']['id'] = 'field_fb_company';
  $handler->display->display_options['fields']['field_fb_company']['table'] = 'field_data_field_fb_company';
  $handler->display->display_options['fields']['field_fb_company']['field'] = 'field_fb_company';
  $handler->display->display_options['fields']['field_fb_company']['label'] = '';
  $handler->display->display_options['fields']['field_fb_company']['element_type'] = '0';
  $handler->display->display_options['fields']['field_fb_company']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_company']['element_default_classes'] = FALSE;
  /* Field: Content: Detail */
  $handler->display->display_options['fields']['field_fb_detail']['id'] = 'field_fb_detail';
  $handler->display->display_options['fields']['field_fb_detail']['table'] = 'field_data_field_fb_detail';
  $handler->display->display_options['fields']['field_fb_detail']['field'] = 'field_fb_detail';
  $handler->display->display_options['fields']['field_fb_detail']['label'] = '';
  $handler->display->display_options['fields']['field_fb_detail']['element_type'] = '0';
  $handler->display->display_options['fields']['field_fb_detail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_detail']['element_default_classes'] = FALSE;
  /* Field: Content: Thumbail */
  $handler->display->display_options['fields']['field_fb_thumbail']['id'] = 'field_fb_thumbail';
  $handler->display->display_options['fields']['field_fb_thumbail']['table'] = 'field_data_field_fb_thumbail';
  $handler->display->display_options['fields']['field_fb_thumbail']['field'] = 'field_fb_thumbail';
  $handler->display->display_options['fields']['field_fb_thumbail']['label'] = '';
  $handler->display->display_options['fields']['field_fb_thumbail']['element_type'] = '0';
  $handler->display->display_options['fields']['field_fb_thumbail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fb_thumbail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_fb_thumbail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fb_thumbail']['settings'] = array(
    'image_style' => 'feedback_thumbnail',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'feedback' => 'feedback',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['feedback'] = $view;

  $view = new view();
  $view->name = 'portfolio';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Portfolio';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'What we do?';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_po_thumbnail']['id'] = 'field_po_thumbnail';
  $handler->display->display_options['fields']['field_po_thumbnail']['table'] = 'field_data_field_po_thumbnail';
  $handler->display->display_options['fields']['field_po_thumbnail']['field'] = 'field_po_thumbnail';
  $handler->display->display_options['fields']['field_po_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_po_thumbnail']['element_type'] = '0';
  $handler->display->display_options['fields']['field_po_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_po_thumbnail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_po_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_po_thumbnail']['settings'] = array(
    'image_style' => 'portfolio_thumbnails',
    'image_link' => '',
  );
  /* Field: Content: Multimedia */
  $handler->display->display_options['fields']['field_multimedia']['id'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['table'] = 'field_data_field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['field'] = 'field_multimedia';
  $handler->display->display_options['fields']['field_multimedia']['label'] = '';
  $handler->display->display_options['fields']['field_multimedia']['element_type'] = '0';
  $handler->display->display_options['fields']['field_multimedia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_multimedia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_multimedia']['settings'] = array(
    'file_view_mode' => 'teaser',
  );
  $handler->display->display_options['fields']['field_multimedia']['delta_offset'] = '0';
  /* Field: Content: Taxonomy */
  $handler->display->display_options['fields']['field_po_taxonomy']['id'] = 'field_po_taxonomy';
  $handler->display->display_options['fields']['field_po_taxonomy']['table'] = 'field_data_field_po_taxonomy';
  $handler->display->display_options['fields']['field_po_taxonomy']['field'] = 'field_po_taxonomy';
  $handler->display->display_options['fields']['field_po_taxonomy']['label'] = '';
  $handler->display->display_options['fields']['field_po_taxonomy']['element_type'] = '0';
  $handler->display->display_options['fields']['field_po_taxonomy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_po_taxonomy']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_po_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_po_taxonomy']['delta_offset'] = '0';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_po_description']['id'] = 'field_po_description';
  $handler->display->display_options['fields']['field_po_description']['table'] = 'field_data_field_po_description';
  $handler->display->display_options['fields']['field_po_description']['field'] = 'field_po_description';
  $handler->display->display_options['fields']['field_po_description']['label'] = '';
  $handler->display->display_options['fields']['field_po_description']['element_type'] = '0';
  $handler->display->display_options['fields']['field_po_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_po_description']['element_default_classes'] = FALSE;
  /* Field: Content: Button Link */
  $handler->display->display_options['fields']['field_po_button_link']['id'] = 'field_po_button_link';
  $handler->display->display_options['fields']['field_po_button_link']['table'] = 'field_data_field_po_button_link';
  $handler->display->display_options['fields']['field_po_button_link']['field'] = 'field_po_button_link';
  $handler->display->display_options['fields']['field_po_button_link']['label'] = '';
  $handler->display->display_options['fields']['field_po_button_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_po_button_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_po_button_link']['element_default_classes'] = FALSE;
  /* Field: Content: Button Text */
  $handler->display->display_options['fields']['field_po_button_text']['id'] = 'field_po_button_text';
  $handler->display->display_options['fields']['field_po_button_text']['table'] = 'field_data_field_po_button_text';
  $handler->display->display_options['fields']['field_po_button_text']['field'] = 'field_po_button_text';
  $handler->display->display_options['fields']['field_po_button_text']['label'] = '';
  $handler->display->display_options['fields']['field_po_button_text']['element_type'] = '0';
  $handler->display->display_options['fields']['field_po_button_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_po_button_text']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'portfolio' => 'portfolio',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['portfolio'] = $view;

  $view = new view();
  $view->name = 'pricing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Pricing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pricing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Currency */
  $handler->display->display_options['fields']['field_pc_currency']['id'] = 'field_pc_currency';
  $handler->display->display_options['fields']['field_pc_currency']['table'] = 'field_data_field_pc_currency';
  $handler->display->display_options['fields']['field_pc_currency']['field'] = 'field_pc_currency';
  $handler->display->display_options['fields']['field_pc_currency']['label'] = '';
  $handler->display->display_options['fields']['field_pc_currency']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pc_currency']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pc_currency']['element_default_classes'] = FALSE;
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_pc_price']['id'] = 'field_pc_price';
  $handler->display->display_options['fields']['field_pc_price']['table'] = 'field_data_field_pc_price';
  $handler->display->display_options['fields']['field_pc_price']['field'] = 'field_pc_price';
  $handler->display->display_options['fields']['field_pc_price']['label'] = '';
  $handler->display->display_options['fields']['field_pc_price']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pc_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pc_price']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pc_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Time */
  $handler->display->display_options['fields']['field_pc_time']['id'] = 'field_pc_time';
  $handler->display->display_options['fields']['field_pc_time']['table'] = 'field_data_field_pc_time';
  $handler->display->display_options['fields']['field_pc_time']['field'] = 'field_pc_time';
  $handler->display->display_options['fields']['field_pc_time']['label'] = '';
  $handler->display->display_options['fields']['field_pc_time']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pc_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pc_time']['element_default_classes'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_pc_description']['id'] = 'field_pc_description';
  $handler->display->display_options['fields']['field_pc_description']['table'] = 'field_data_field_pc_description';
  $handler->display->display_options['fields']['field_pc_description']['field'] = 'field_pc_description';
  $handler->display->display_options['fields']['field_pc_description']['label'] = '';
  $handler->display->display_options['fields']['field_pc_description']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pc_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pc_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pc_description']['delta_offset'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_pc_link']['id'] = 'field_pc_link';
  $handler->display->display_options['fields']['field_pc_link']['table'] = 'field_data_field_pc_link';
  $handler->display->display_options['fields']['field_pc_link']['field'] = 'field_pc_link';
  $handler->display->display_options['fields']['field_pc_link']['label'] = '';
  $handler->display->display_options['fields']['field_pc_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pc_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pc_link']['element_default_classes'] = FALSE;
  /* Field: Content: Button Text */
  $handler->display->display_options['fields']['field_pc_button_text']['id'] = 'field_pc_button_text';
  $handler->display->display_options['fields']['field_pc_button_text']['table'] = 'field_data_field_pc_button_text';
  $handler->display->display_options['fields']['field_pc_button_text']['field'] = 'field_pc_button_text';
  $handler->display->display_options['fields']['field_pc_button_text']['label'] = '';
  $handler->display->display_options['fields']['field_pc_button_text']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pc_button_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pc_button_text']['element_default_classes'] = FALSE;
  /* Field: Content: Button Text Hover */
  $handler->display->display_options['fields']['field_pc_button_text_hover']['id'] = 'field_pc_button_text_hover';
  $handler->display->display_options['fields']['field_pc_button_text_hover']['table'] = 'field_data_field_pc_button_text_hover';
  $handler->display->display_options['fields']['field_pc_button_text_hover']['field'] = 'field_pc_button_text_hover';
  $handler->display->display_options['fields']['field_pc_button_text_hover']['label'] = '';
  $handler->display->display_options['fields']['field_pc_button_text_hover']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pc_button_text_hover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pc_button_text_hover']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pricing' => 'pricing',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['pricing'] = $view;

  $view = new view();
  $view->name = 'recent_posts_sidebar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recent Posts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent Posts Sidebar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_bl_thumbnail']['id'] = 'field_bl_thumbnail';
  $handler->display->display_options['fields']['field_bl_thumbnail']['table'] = 'field_data_field_bl_thumbnail';
  $handler->display->display_options['fields']['field_bl_thumbnail']['field'] = 'field_bl_thumbnail';
  $handler->display->display_options['fields']['field_bl_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_bl_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bl_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bl_thumbnail']['settings'] = array(
    'image_style' => 'blog_sidebar_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_bl_thumbnail']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['recent_posts_sidebar'] = $view;

  $view = new view();
  $view->name = 'services';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Services';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Our Services';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_sv_thumbnail']['id'] = 'field_sv_thumbnail';
  $handler->display->display_options['fields']['field_sv_thumbnail']['table'] = 'field_data_field_sv_thumbnail';
  $handler->display->display_options['fields']['field_sv_thumbnail']['field'] = 'field_sv_thumbnail';
  $handler->display->display_options['fields']['field_sv_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_sv_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sv_thumbnail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_sv_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sv_thumbnail']['settings'] = array(
    'image_style' => 'services_thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_sv_summary']['id'] = 'field_sv_summary';
  $handler->display->display_options['fields']['field_sv_summary']['table'] = 'field_data_field_sv_summary';
  $handler->display->display_options['fields']['field_sv_summary']['field'] = 'field_sv_summary';
  $handler->display->display_options['fields']['field_sv_summary']['label'] = '';
  $handler->display->display_options['fields']['field_sv_summary']['element_label_colon'] = FALSE;
  /* Field: Content: Button Text */
  $handler->display->display_options['fields']['field_sv_button_text']['id'] = 'field_sv_button_text';
  $handler->display->display_options['fields']['field_sv_button_text']['table'] = 'field_data_field_sv_button_text';
  $handler->display->display_options['fields']['field_sv_button_text']['field'] = 'field_sv_button_text';
  $handler->display->display_options['fields']['field_sv_button_text']['label'] = '';
  $handler->display->display_options['fields']['field_sv_button_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sv_button_text']['element_default_classes'] = FALSE;
  /* Field: Content: Button Link */
  $handler->display->display_options['fields']['field_sv_button_link']['id'] = 'field_sv_button_link';
  $handler->display->display_options['fields']['field_sv_button_link']['table'] = 'field_data_field_sv_button_link';
  $handler->display->display_options['fields']['field_sv_button_link']['field'] = 'field_sv_button_link';
  $handler->display->display_options['fields']['field_sv_button_link']['label'] = '';
  $handler->display->display_options['fields']['field_sv_button_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sv_button_link']['element_default_classes'] = FALSE;
  /* Field: Content: Icon */
  $handler->display->display_options['fields']['field_sv_icon']['id'] = 'field_sv_icon';
  $handler->display->display_options['fields']['field_sv_icon']['table'] = 'field_data_field_sv_icon';
  $handler->display->display_options['fields']['field_sv_icon']['field'] = 'field_sv_icon';
  $handler->display->display_options['fields']['field_sv_icon']['label'] = '';
  $handler->display->display_options['fields']['field_sv_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sv_icon']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_sv_icon']['click_sort_column'] = 'bundle';
  $handler->display->display_options['fields']['field_sv_icon']['settings'] = array(
    'link_to_content' => 0,
  );
  /* Field: Content: Icon Title */
  $handler->display->display_options['fields']['field_sv_icon_title']['id'] = 'field_sv_icon_title';
  $handler->display->display_options['fields']['field_sv_icon_title']['table'] = 'field_data_field_sv_icon_title';
  $handler->display->display_options['fields']['field_sv_icon_title']['field'] = 'field_sv_icon_title';
  $handler->display->display_options['fields']['field_sv_icon_title']['label'] = '';
  $handler->display->display_options['fields']['field_sv_icon_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sv_icon_title']['element_default_classes'] = FALSE;
  /* Field: Content: Icon Link */
  $handler->display->display_options['fields']['field_sv_icon_link']['id'] = 'field_sv_icon_link';
  $handler->display->display_options['fields']['field_sv_icon_link']['table'] = 'field_data_field_sv_icon_link';
  $handler->display->display_options['fields']['field_sv_icon_link']['field'] = 'field_sv_icon_link';
  $handler->display->display_options['fields']['field_sv_icon_link']['label'] = '';
  $handler->display->display_options['fields']['field_sv_icon_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sv_icon_link']['element_default_classes'] = FALSE;
  /* Field: Content: Icon Description */
  $handler->display->display_options['fields']['field_sv_description']['id'] = 'field_sv_description';
  $handler->display->display_options['fields']['field_sv_description']['table'] = 'field_data_field_sv_description';
  $handler->display->display_options['fields']['field_sv_description']['field'] = 'field_sv_description';
  $handler->display->display_options['fields']['field_sv_description']['label'] = '';
  $handler->display->display_options['fields']['field_sv_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sv_description']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'services' => 'services',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['services'] = $view;

  $view = new view();
  $view->name = 'tag_cloud_sidebar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Tag Cloud';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Categories Sidebar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'blog_category' => 'blog_category',
  );

  /* Display: Tag Cloud */
  $handler = $view->new_display('block', 'Tag Cloud', 'block');
  $export['tag_cloud_sidebar'] = $view;

  $view = new view();
  $view->name = 'team';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Team';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Job */
  $handler->display->display_options['fields']['field_team_job']['id'] = 'field_team_job';
  $handler->display->display_options['fields']['field_team_job']['table'] = 'field_data_field_team_job';
  $handler->display->display_options['fields']['field_team_job']['field'] = 'field_team_job';
  $handler->display->display_options['fields']['field_team_job']['label'] = '';
  $handler->display->display_options['fields']['field_team_job']['element_type'] = '0';
  $handler->display->display_options['fields']['field_team_job']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_job']['element_default_classes'] = FALSE;
  /* Field: Content: Socials */
  $handler->display->display_options['fields']['field_team_socials']['id'] = 'field_team_socials';
  $handler->display->display_options['fields']['field_team_socials']['table'] = 'field_data_field_team_socials';
  $handler->display->display_options['fields']['field_team_socials']['field'] = 'field_team_socials';
  $handler->display->display_options['fields']['field_team_socials']['label'] = '';
  $handler->display->display_options['fields']['field_team_socials']['element_type'] = '0';
  $handler->display->display_options['fields']['field_team_socials']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_socials']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_team_socials']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_team_socials']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_team_socials']['delta_offset'] = '0';
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_team_thumbnail']['id'] = 'field_team_thumbnail';
  $handler->display->display_options['fields']['field_team_thumbnail']['table'] = 'field_data_field_team_thumbnail';
  $handler->display->display_options['fields']['field_team_thumbnail']['field'] = 'field_team_thumbnail';
  $handler->display->display_options['fields']['field_team_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_team_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_team_thumbnail']['settings'] = array(
    'image_style' => 'team_thumbnail',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team' => 'team',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['team'] = $view;

  return $export;
}
