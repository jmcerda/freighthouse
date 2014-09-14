<?php

/**
 * @param $form
 * @param $form_state
 * @param $form_id
 */
function freighthouse_form_alter(&$form, &$form_state, $form_id) {
    if (strpos($form_id,"webform_client_form") === false) {
        switch ($form_id) {
            case 'user_login':
                $form['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['name']['#suffix'] = '</div>';
                $form['pass']['#attributes']['class'][] = 'form-control input-lg';
                $form['pass']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['pass']['#suffix'] = '</div>';
                $form['actions']['submit']['#value'] = t('Login');
                $form['actions']['submit']['#prefix'] = '<div class="row">
              <div class="col-md-12 text-center">
                  <div class="action mybutton medium"><span>';
                $form['actions']['submit']['#suffix'] = '</span></div>
              </div>
            </div>';
                break;
            case 'user_register_form':
                $form['account']['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['account']['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['account']['name']['#suffix'] = '</div>';
                $form['account']['mail']['#attributes']['class'][] = 'form-control input-lg';
                $form['account']['mail']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['account']['mail']['#suffix'] = '</div>';

                $form['actions']['submit']['#value'] = t('Sign up');
                $form['actions']['submit']['#prefix'] = '<div class="row">
              <div class="col-md-12 text-center">
                  <div class="action mybutton medium"><span>';
                $form['actions']['submit']['#suffix'] = '</span></div>
              </div>
            </div>';
                break;
            case 'user_login_block':
                $form['name']['#attributes']['class'][] = 'form-control input-lg';
                $form['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['name']['#suffix'] = '</div>';
                $form['pass']['#attributes']['class'][] = 'form-control input-lg';
                $form['pass']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
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
                $form['name']['#prefix'] = '<div class="col-md-12 col-sm-12 col-md-12 col-xs-12">';
                $form['name']['#suffix'] = '</div>';
                $form['actions']['submit']['#value'] = t('Request new password');
                $form['actions']['submit']['#prefix'] = '<div class="row">
              <div class="col-md-12 text-center">
                  <div class="action mybutton medium"><span>';
                $form['actions']['submit']['#suffix'] = '</span></div>
              </div>
            </div>';
                break;
        }
    } else {

        $form['#attributes']['class'][] = 'element-inline';
        $form['actions']['submit']['#value'] = 'Send Message';
        $form['actions']['submit']['#prefix'] = '<div class="row">
              <div class="col-md-12 text-center">
                <div class="action form-button medium">
                  <div class="mybutton medium"><span data-hover="Send Message">';
        $form['actions']['submit']['#sufix'] = '</span></div>
                </div>
              </div>
            ';
    }


}