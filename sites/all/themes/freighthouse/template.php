<?php

/**
 * @param $form
 * @param $form_state
 * @param $form_id
 */

function freighthouse_theme() {
  $items = array();

  // $items['user_login'] = array(
  //   'render element' => 'form',
  //   'path' => drupal_get_path('theme', 'freighthouse') . '/template',
  //   'template' => 'user-login',
  //   'preprocess functions' => array(
  //      'freighthouse_preprocess_user_login'
  //   ),
  // );
  $items['user_register_form'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'freighthouse') . '/template',
    'template' => 'user-register-form',
    'preprocess functions' => array(
      'freighthouse_preprocess_user_register_form'
    ),
  );
  $items['user_pass'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'freighthouse') . '/template',
    'template' => 'user-pass',
    'preprocess functions' => array(
      'freighthouse_preprocess_user_pass'
    ),
  );
  return $items;
}

function freighthouse_form_alter(&$form, &$form_state, $form_id) {
    if (strpos($form_id,"webform_client_form_1") === false) {
        switch ($form_id) {
            case 'user_login':
                $form['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-xs-12">';
                $form['name']['#suffix'] = '</div>';
                $form['pass']['#attributes']['class'][] = 'form-control input-lg';
                $form['pass']['#prefix'] = '<div class="col-md-12 col-sm-12 col-xs-12">';
                $form['pass']['#suffix'] = '</div>';
                $form['actions']['submit']['#value'] = t('Login');
                $form['actions']['submit']['#prefix'] = '<div class="row col-md-12 col-sm-12 col-xs-12">
              <div class="col-md-12 text-center">
                  <div class="action mybutton medium"><button onclick="this.submit();"><span style="position:relative; display:inline-block; " data-hover="Login">';
                $form['actions']['submit']['#suffix'] = '</span></button></div>
              </div>
            </div>';
                break;
            case 'user_register_form':
                $form['account']['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['account']['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-xs-12">';
                $form['account']['name']['#suffix'] = '</div>';
                $form['account']['mail']['#attributes']['class'][] = 'form-control input-lg';
                $form['account']['mail']['#prefix'] = '<div class="col-md-12 col-sm-12 col-xs-12">';
                $form['account']['mail']['#suffix'] = '</div>';
                $form['actions']['submit']['#value'] = t('Join Freighthouse');
                $form['actions']['submit']['#prefix'] = '<div class="row">
              <div class="col-md-12 text-center">
                  <div class="action mybutton medium"><button onclick="this.submit();"><span style="position:relative; display:inline-block; " data-hover="Join Freighthouse">';
                $form['actions']['submit']['#suffix'] = '</span></button></div>
              </div>
            </div>';
                break;
            case 'user_login_block':
                $form['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-xs-12">';
                $form['name']['#suffix'] = '</div>';
                $form['pass']['#attributes']['class'][] = 'form-control input-lg';
                $form['pass']['#prefix'] = '<div class="col-md-12 col-sm-12 col-xs-12">';
                $form['pass']['#suffix'] = '</div>';
                $form['actions']['submit']['#value'] = t('Login');
                $form['actions']['submit']['#prefix'] = '<div class="row">
              <div class="col-md-12 text-center">
                  <div class="action mybutton medium"><span>';
                $form['actions']['submit']['#suffix'] = '</span></div>
              </div>
            </div>';
                break;
            case 'user_pass':
                $form['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-xs-12">';
                $form['name']['#suffix'] = '</div>';
                $form['actions']['submit']['#value'] = t('Request new password');
                $form['actions']['submit']['#prefix'] = '<div class="row">
              <div class="text-center">
                  <div class="action mybutton medium"><span>';
                $form['actions']['submit']['#suffix'] = '</span></div>
              </div>
            </div>';
                break;
        }
    } else {
        /*
        $form['#attributes']['class'][] = 'element-inline';
        $form['actions']['submit']['#value'] = 'Send Message';
        $form['actions']['submit']['#prefix'] = '<div class="row">
              <div class="col-md-12 text-center">
                <div class="action form-button medium">
                  <div class="mybutton ultra medium"><span data-hover="Send Message">';
        $form['actions']['submit']['#sufix'] = '</span></div>
                </div>
              </div>
            ';
        */
        $form['#attributes']['class'][] = 'element-line';
        $form['actions']['submit']['#value'] = 'Send Message';
        $form['actions']['submit']['#prefix'] = '<div class="row">
              <div class="col-md-12 text-center">
                <div class="action mybutton"><button onclick="this.submit();"><span style="position:relative; display:inline-block;" data-hover="SEND MESSAGE">';
        $form['actions']['submit']['#sufix'] = '</span></button></div>
                </div>
              </div>
            ';
    }
}


// Force js to load in footer

drupal_add_js('https://cdn.sublimevideo.net/js/gk9qliwk.js', 'external');
// drupal_add_js('https://cdn.sublimevideo.net/js/gk9qliwk.js', 'external',
//   array('type' => 'inline', 'scope' => 'footer', 'weight' => 5)
//   );

/**
 * Theme the username/password description of the user login form
 * and the user login block.
 */
// function freighthouse_username_description($variables) {
//   switch ($variables['form_id']) {
//     case 'user_login':
//       // The username field's description when shown on the /user/login page.
//       return t("");
//       break;
//     case 'user_login_block':
//       return '';
//       break;
//   }
// }

// function freighthouse_password_description($variables) {
//   switch ($variables['form_id']) {
//     case 'user_login':
//       // The password field's description on the /user/login page.
//       return t("");
//       break;
//     case 'user_login_block':
//       // If showing the login form in a block, don't print any descriptive text.
//       return '';
//       break;
//   }
// }

/*css includes*/
/*
drupal_add_css(drupal_get_path('theme', 'freighthouse') . '/css/style-custom.css', array('group' => CSS_THEME));
*/
/*js includes*/
/*
$themepath = drupal_get_path('theme', 'freighthouse');
drupal_add_js($themepath . '/js/script.js');
drupal_add_js(drupal_get_path('theme', 'freighthouse') . '/js/script-freighthouse.js',  array('type' => 'file', 'scope' => 'footer'));
drupal_add_js(drupal_get_path('theme', 'freighthouse') . '/js/coolclock.js',  array('type' => 'file', 'scope' => 'footer'));
drupal_add_js(drupal_get_path('theme', 'freighthouse') . '/js/moreskins.js',  array('type' => 'file', 'scope' => 'footer'));
drupal_add_js(drupal_get_path('theme', 'freighthouse') . '/js/excanvas.js',  array('type' => 'file', 'scope' => 'footer'));
*/
