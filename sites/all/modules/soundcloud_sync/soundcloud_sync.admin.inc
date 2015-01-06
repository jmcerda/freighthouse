<?php

/**
 * @file
 * SoundCloud admin settings page.
 */

/**
 * Menu callback; Displays the administration settings for Disqus.
 */
function soundcloud_sync_admin_settings_form() {

  $form = array();

  // Check if site was connected to SoundCloud account.
  $connected = (variable_get('soundcloud_sync_access_token', 0) ? 1 : 0);

  $form['connection_status'] = array(
    '#markup' => '<div class="messages ' . ($connected ? 'status' : 'error') . '">' .
    t('Status: %status', array('%status' => ($connected ? t('Connected') : t('Not connected')))) . '</div>',
  );

  // Build step-by-step instructions for both cases.
  if (!$connected) {
    // TODO: add target="_blank" to the app registration link.
    $steps = array(
      t("Open !app_url in new window (Ctrl + click).", array('!app_url' => l('http://soundcloud.com/you/apps',
      'http://soundcloud.com/you/apps', array('absolute' => true, 'target' => 'parent')))),
      t("Click 'Register new app' button."),
      t('Use your site name as app title. Site name: %sitename', array('%sitename' => variable_get('site_name', 'Drupal site'))),
      t("Enter 'Redirect URL'. Should be: %redirect_url", array('%redirect_url' => url($_GET['q'], array('absolute' => true)))),
      t("Click 'Save'."),
      t("Copy and paste 'Client ID' and 'Client Secret' into fields below."),
    );
    $form['help'] = array('#markup' => theme('item_list', array('items' => $steps, 'type' => 'ol', 'title' => t('Connection Instructions'))));
  }

  $form['soundcloud_sync_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#default_value' => variable_get('soundcloud_sync_client_id', ''),
    '#required' => TRUE,
  );
  $form['soundcloud_sync_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Secret'),
    '#default_value' => variable_get('soundcloud_sync_client_secret', ''),
    '#required' => TRUE,
  );
  $form['#validate'][] = 'soundcloud_sync_admin_settings_form_validate';
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Connect'));
  $form['#submit'][] = 'soundcloud_sync_admin_settings_form_submit';
  if (!empty($_POST) && form_get_errors()) {
    drupal_set_message(t('The settings have not been saved because of the errors.'), 'error');
  }

  return $form;
}

/**
 * Validates values at admin_settings_form form.
 *
 * @param array $form
 * @param array $form_state
 * @access public
 * @return void Returns nothing.
 */
function soundcloud_sync_admin_settings_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  // TODO: do strong validation. No spaces, no punctuation marks.
  if (!isset($values['soundcloud_sync_client_id']) || strlen($values['soundcloud_sync_client_id']) != 32) {
    form_set_error('soundcloud_sync_client_id', 'Incorrect value of "Client ID". Please check again.');
  }
  if (!isset($values['soundcloud_sync_client_secret']) || strlen($values['soundcloud_sync_client_secret']) != 32) {
    form_set_error('soundcloud_sync_client_secret', 'Incorrect value of "Client Secret". Please check again.');
  }
}


/**
 * Submitter for admin_settings_form.
 * Stores provided credentials; connects to the SoundCloud service and stores access_token.
 *
 * @param array $form
 * @param array $form_state
 * @access public
 * @return void
 */
function soundcloud_sync_admin_settings_form_submit($form, &$form_state) {
  // Store provided credentials.
  $values = $form_state['values'];
  variable_set('soundcloud_sync_client_id', $values['soundcloud_sync_client_id']);
  variable_set('soundcloud_sync_client_secret', $values['soundcloud_sync_client_secret']);

  // Connect to the service.
  soundcloud_sync_api_connect();
}

