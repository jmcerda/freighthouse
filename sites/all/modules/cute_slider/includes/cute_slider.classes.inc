<?php
/**
 * @file cute_slider.classes.inc
 * User: duynguyen
 * Date: 3/30/13
 * Time: 12:00 PM
 * To change this template use File | Settings | File Templates.
 */

  /**
   * CuteSlider class
   */
class CuteSlider {
  public $slid;
  public $title;
  public $description;
  public $machine_name;
  public $settings;

  public function db_fields() {
    return array('title', 'description', 'machine_name', 'settings');
  }

  public function initialize() {
    if (is_string($this->settings)) {
      $this->settings = unserialize($this->settings);
    };
  }

  public function save() {
    $response = FALSE;
    $fields = array();
    if ($this->title == NULL || $this->title == '') {
      return $response;
    }

    foreach ($this->db_fields() as $field) {
      $fields[$field] = $this->{$field};
    }

    if (is_array($fields['settings'])) {
      $fields['settings'] = serialize($fields['settings']);
    }

    if ($this->slid) {
      $response = db_update('cute_sliders')
        ->fields($fields)
        ->condition('slid', $this->slid)
        ->execute();
    }
    else {
      $slid = db_insert('cute_sliders')
        ->fields($fields)
        ->execute();

      if ($slid > 0) {
        $this->slid = $slid;
        $response = TRUE;
      }
    }

    return $response;
  }

  public static function create($title, $description = NULL, $settings = NULL, $machine_name = NULL) {
    $default_settings = CuteSlider::get_default_settings();

    if ($settings) {
      $settings = array_merge($default_settings, $settings);
    }
    else {
      $settings = $default_settings;
    }

    # Create new CuteSlider object
    $slider = new CuteSlider();
    $slider->title = $title;
    $slider->description = $description;
    $slider->machine_name = ($machine_name) ? $machine_name : uniqid('cuteslider-');
    $slider->settings = $settings;

    if ($slider->save()) {
      return $slider;
    }

    return NULL;
  }

  public static function get_all() {
    $results = db_select('{cute_sliders}', 'mss')
      ->fields('mss')
      ->execute()
      ->fetchAll(PDO::FETCH_CLASS, 'CuteSlider');

    if (!count($results)) {
      return array();
    }

    # Run object initialize
    foreach ($results as &$slider) {
      $slider->initialize();
      $slider->initialize();
    }

    # Return list menus
    return $results;
  }

  public static function get_by_id($slid) {
    $results = db_select('{cute_sliders}', 'mss')
      ->fields('mss')
      ->condition('slid', $slid)
      ->execute()->fetchAll(PDO::FETCH_CLASS, 'CuteSlider');

    if (!count($results)) {
      return array();
    }

    # Run object initialize
    foreach ($results as &$slider) {
      $slider->initialize();
    }

    # Return list menus
    return array_shift($results);
  }

  public static function get_by_list_id($slids) {
    $results = db_select('{cute_sliders}', 'mss')
      ->fields('mss')
      ->condition('slid', $slids, 'IN')
      ->execute()->fetchAll(PDO::FETCH_CLASS, 'CuteSlider');

    if (!count($results)) {
      return array();
    }

    # Run object initialize
    foreach ($results as &$slider) {
      $slider->initialize();
    }

    # Return list menus
    return $results;
  }

  public static function delete($slid) {
    # Delete all slides of slider
    $slides = CuteSlide::get_by_slider_id($slid);
    if (count($slides) > 0)
      $ret = CuteSlide::delete_by_slider($slid);
    else
      $ret = TRUE;

    # Delete slider
    if ($ret)
      return db_delete('cute_sliders')
        ->condition('slid', $slid)
        ->execute();

    return $ret;
  }

  /**
   * Get CuteSlider by machine name
   */
  public static function get_by_machine_name($machine_name) {
    $results = db_select('{cute_sliders}', 'mss')
      ->fields('mss')
      ->condition('machine_name', $machine_name)
      ->execute()->fetchAll(PDO::FETCH_CLASS, 'CuteSlider');

    if (!count($results)) {
      return array();
    }

    # Run object initialize
    foreach ($results as &$slider) {
      $slider->initialize();
    }

    # Return list menus
    return $results;
  }

  public static function get_default_settings($key = NULL) {
    static $default_settings = array(
      'width' => 900,
      'height' => 350,
      'use_image_style' => 1,
      'responsive' => 1,
      'min_width' => 0,
      'max_width' => 0,
      'thumb_width' => 60,
      'thumb_height' => 60,
      'auto' => 1,
      'pause_hover' => 0,
      'template' => 'default',
      'css_generate' => 0,
      'enable_shadow' => 0,
      'gallery_mode' => 0,
      'show_slidecontrol' => 1,
      'thumbnail_align' => 'bottom',
      'show_thumbnail_bar' => 0,
      'thumbbar_direction' => 'vertical',
      'thumbbar_position' => 'left',
      'show_nextprev' => 1,
      'show_cyclebar' => 0,
      'show_loadingbar' => 1,
      'google_font' => '',
      'load_google_font' => 0,
      'change_start' => 'function(event){}',
      'change_end' => 'function(event){}',
      'wating' => 'function(event){}',
      'change_next_slide' => 'function(event){}',
      'wating_for_next' => 'function(event){}',
      'color_saved' => '',
    );

    if ($key) {
      return $default_settings[$key];
    }

    return $default_settings;
  }
}

/**
 * CuteSlide class
 */
class CuteSlide {
  public $sid;
  public $slid;
  public $position;
  public $settings;
  public $layers;

  public function db_fields() {
    return array('slid', 'position', 'settings', 'layers');
  }

  public function initialize() {
    if (is_string($this->settings)) {
      $this->settings = unserialize($this->settings);
      $this->settings = array_merge(CuteSlide::get_default_settings(), $this->settings);
    }

    if (is_string($this->layers)) {
      $this->layers = unserialize($this->layers);
    }
  }

  public function save() {
    $fields = array();
    foreach ($this->db_fields() as $field_name) {
      $fields[$field_name] = $this->{$field_name};
    }

    if (is_array($fields['layers'])) {
      $fields['layers'] = serialize($fields['layers']);
    }

    $fields['settings'] = array_merge(CuteSlide::get_default_settings(), $fields['settings']);
    if (is_array($fields['settings'])) {
      $fields['settings'] = serialize($fields['settings']);
    }

    if ($this->sid) {
      db_update('cute_slides')
        ->fields($fields)
        ->condition('sid', $this->sid)
        ->execute();
    }
    else {
      db_insert('cute_slides')
        ->fields($fields)
        ->execute();
    }
  }

  public static function create($slid, $position, $settings = NULL, $layers = NULL) {
    $slider = CuteSlider::get_by_id($slid);
    if ($slider == NULL) {
      return;
    }

    $new_slide = new CuteSlide();
    $new_slide->slid = $slid;
    $new_slide->position = $position;
    $new_slide->settings = $settings;
    $new_slide->layers = $layers;

    $new_slide->save();
  }

  public static function get_by_slider_id($slid) {
    $results = db_select('cute_slides', 'mds')
      ->fields('mds')
      ->condition('slid', $slid)
      ->orderBy('position')
      ->execute()
      ->fetchAll(PDO::FETCH_CLASS, 'CuteSlide');

    if (count($results) > 0) {
      foreach ($results as &$slide) {
        $slide->initialize();
      }

      return $results;
    }

    return array();
  }

  public static function get_by_list_sliders($slids) {
    $results = db_select('cute_slides', 'mds')
      ->fields('mds')
      ->condition('slid', $slids, 'IN')
      ->orderBy('position')
      ->execute()
      ->fetchAll(PDO::FETCH_CLASS, 'CuteSlide');

    if (count($results) > 0) {
      foreach ($results as &$slide) {
        $slide->initialize();
      }

      return $results;
    }

    return array();
  }

  public static function get($sid) {
    $output = NULL;
    $results = db_select('cute_slides', 'mds')
      ->fields('mds')
      ->condition('sid', $sid)
      ->execute()
      ->fetchAll(PDO::FETCH_CLASS, 'CuteSlide');

    if (count($results) > 0) {
      $output = array_shift($results);
      $output->initialize();
    }

    return $output;
  }

  public static function delete($sid) {
    return db_delete('cute_slides')
      ->condition('sid', $sid)
      ->execute();
  }

  public static function delete_by_slider($slid) {
    return db_delete('cute_slides')
      ->condition('slid', $slid)
      ->execute();
  }

  public static function get_default_settings($key = NULL) {
    static $default_settings = array(
      'backgroundimage' => -1,
      'thumbnail' => -1,
      'linktext' => '',
      'linktarget' => FALSE,
      'infoposition' => 'bottom',
      'infotitle' => '',
      'infotext' => '',
      'infobuttontext' => '',
      'infobuttonlink' => '',
      'infobuttontarget' => '',
      'videourl' => '',
      'trs2d' => '',
      'trs3d' => '',
      'timelinewidth' => 80,
    );

    if ($key && $key != '') {
      return $default_settings[$key];
    }

    return $default_settings;
  }
}
