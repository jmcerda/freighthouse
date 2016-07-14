<?php

/**
 * @file
 * SoundCloud admin settings page.
 */

/**
 * Menu callback. Check if we received code from SouldCloud.com and request 'access token'.
 * This callback allows to avoid using hook_init().
 */
function soundcloud_sync_admin_get_client() {
  if (isset($_GET['code'])) {
    $client = new SoundCloudClient();
    $response = $client->connect($_GET['code']);
    drupal_set_message('Sucessfully connected to SoundCloud.com.');
    drupal_goto(SOUNDCLOUD_ADMIN_URL);
  }
}

/**
 * Menu callback; Displays the administration settings for Disqus.
 */
function soundcloud_sync_admin_connection_settings_form() {
  $form = array();

  $client = new SoundCloudClient();

  // Troubleshoot first.
  if (isset($_GET['error'])) {
    drupal_set_message(t('Error: %error_description',
    array(
      '%error_code' => $_GET['error'],
      '%error_description' => $_GET['error_description'],
    )), 'error', FALSE);
  }

  // Check if site was connected to SoundCloud account.
  $submit_button_label = t('Connect');
  $status_class = 'error';
  $status_message = t('Not connected');
  if ($client->isConnected()) {
    $submit_button_label =  t('Disconnect');
    $status_class = 'status';
    $status_message = t('Connected');
  }

  $form['connection_status'] = array(
    '#markup' => '<div class="messages ' . $status_class . '">' .
    t('Status: %status', array('%status' => $status_message)) . '</div>',
  );

  // Build step-by-step instructions for both cases.
  if (!$client->isConnected()) {
    // TODO: add target="_blank" to the app registration link.
    $steps = array(
      t("Open !app_url in new window (Ctrl + click).", array('!app_url' => l('http://soundcloud.com/you/apps',
      'http://soundcloud.com/you/apps', array('absolute' => true, 'target' => 'parent')))),
      t("Click 'Register new app' button."),
      t('Use your site name as app title. Site name: %sitename', array('%sitename' => variable_get('site_name', 'Drupal site'))),
      t("Enter 'Redirect URL'. Should be: %redirect_url", array('%redirect_url' => url($_GET['q'], array('absolute' => true)) . '/client')),
      t("Click 'Save'."),
      t("Copy and paste 'Client ID' and 'Client Secret' into fields below."),
    );
    $form['help'] = array('#markup' => theme('item_list', array('items' => $steps, 'type' => 'ol', 'title' => t('Connection Instructions'))));
    $form['soundcloud_sync_client_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Client ID'),
      '#default_value' => $client->clientId,
      '#required' => TRUE,
    );
    $form['soundcloud_sync_client_secret'] = array(
      '#type' => 'textfield',
      '#title' => t('Client Secret'),
      '#default_value' => $client->clientSecret,
      '#required' => TRUE,
    );
  }
  $form['#validate'][] = 'soundcloud_sync_admin_settings_form_validate';
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => $submit_button_label);

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
  $connected = (boolean)($form_state['buttons'][0]['#value'] == 'Disconnect');
  if (!$connected) {
    $values = $form_state['values'];
    // TODO: do strong validation. No spaces, no punctuation marks.
    if (!isset($values['soundcloud_sync_client_id']) || strlen($values['soundcloud_sync_client_id']) != 32) {
      form_set_error('soundcloud_sync_client_id', 'Incorrect value of "Client ID". Please check again.');
    }
    if (!isset($values['soundcloud_sync_client_secret']) || strlen($values['soundcloud_sync_client_secret']) != 32) {
      form_set_error('soundcloud_sync_client_secret', 'Incorrect value of "Client Secret". Please check again.');
    }
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
  $client = new SoundCloudClient();
  if ($client->isConnected()) {
    // Disconnect.
    $client->accessToken = '';
    $form_state['rebuild'] = TRUE;
  }
  else {
    // Store provided credentials.
    $client->clientId = $form_state['values']['soundcloud_sync_client_id'];
    $client->clientSecret = $form_state['values']['soundcloud_sync_client_secret'];
    $client->accessToken = '';

    // Redirect user to SoundClound's authorization page to connect the app.
    header("Location: " . $client->getConnectUrl());
    exit;
  }
}

