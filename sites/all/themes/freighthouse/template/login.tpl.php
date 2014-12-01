function freighthouse_form_profile2_form_alter(&$form, &$form_state){

    $form['account']['field_profile_first_name'] = $form['profile_account_profile']['field_profile_first_name'];
    $form['account']['field_profile_first_name'] = $form['profile_account_profile']['field_profile_last_name'];
    unset($form['profile_account_profile']['field_profile_first_name']);
    unset($form['profile_account_profile']['field_profile_last_name']);


   $form['#submit'][] = 'freighthouse_form_profile2_form_submit';
}


function freighthouse_form_profile2_form_submit($form, &$form_state) {


  if (is_array($form_state['values']['profile_account_profile']) {


    $form_state['values']['profile_account_profile']['field_profile_first_name']  = array();
    $form_state['values']['profile_account_profile']['field_profile_first_name']['und'] = $form_state['values']['field_profile_first_name'][0]['und'];

    $form_state['values']['profile_account_profile']['field_profile_last_name']  =  array();
    $form_state['values']['profile_account_profile']['field_profile_last_name']['und'] = $form_state['values']['field_profile_first_name'][1]['und'];
  }

}
