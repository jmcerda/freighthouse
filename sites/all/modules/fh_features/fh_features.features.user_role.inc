<?php
/**
 * @file
 * fh_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function fh_features_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 3,
  );

  // Exported role: client.
  $roles['client'] = array(
    'name' => 'client',
    'weight' => 2,
  );

  return $roles;
}
