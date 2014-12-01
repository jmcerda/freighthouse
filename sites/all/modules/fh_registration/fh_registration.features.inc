<?php
/**
 * @file
 * fh_registration.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function fh_registration_default_profile2_type() {
  $items = array();
  $items['client'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "client",
    "label" : "Client",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 }
  }');
  $items['consultant'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "consultant",
    "label" : "Consultant",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 }
  }');
  $items['designer'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "designer",
    "label" : "Designer",
    "weight" : "0",
    "data" : {
      "registration" : false,
      "use_page" : 1,
      "step_step" : "hire_a_designer",
      "step_exclude" : []
    }
  }');
  $items['developer'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "developer",
    "label" : "Developer",
    "weight" : "0",
    "data" : {
      "registration" : false,
      "use_page" : 1,
      "step_step" : "",
      "step_exclude" : []
    }
  }');
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "main",
    "label" : "Join Freighthouse",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 }
  }');
  $items['staff'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "staff",
    "label" : "Staff",
    "weight" : "0",
    "data" : {
      "registration" : false,
      "use_page" : 1,
      "step_step" : "",
      "step_exclude" : []
    }
  }');
  return $items;
}
