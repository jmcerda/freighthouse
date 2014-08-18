<?php
/**
 * @file theme.admin.inc
 * User: duynguyen
 * Date: 4/2/13
 * Time: 3:42 PM
 * To change this template use File | Settings | File Templates.
 */

  /**
   * Implements hook_preprocess for slider_edit_form
   */
  function template_preprocess_cute_slider_edit(&$variables) {
    $slider = $variables['slider'];
    $slider->settings['delay'] = 100;

    $variables['class_fullwidth'] = "";

    $slides = CuteSlide::get_by_slider_id($slider->slid);
    $variables['slides'] = $slides;

    $css_file = cute_slider_load_custom_style_css($slider->slid);
    $variables['style_options'] = cute_slider_get_style_options($css_file);
    $variables['default_bg'] = file_create_url("public://md_slider_def_bg.jpg");

    $google_fonts = $slider->settings['google_font'];
    if ($google_fonts != '') {
      drupal_add_css($google_fonts, array('type' => 'external'));
      $fonts = cute_slider_process_google_web_font($google_fonts);
      $variables['fonts'] = $fonts;
    }
    else {
      $variables['fonts'] = array();
    }
  }

  /**
   * Implements hook_preprocess for admin_layers_render theme
   */
  function template_preprocess_cute_slider_admin_layer(&$variables) {
    $layer = $variables['layer'];

    $data = array();
    foreach ($layer as $attr => $value) {
      if ($attr == 'link') {
        $link_val = drupal_json_encode($value);
        $data[] = "data-link='{$link_val}'";
        continue;
      }

      $data[] = "data-{$attr}='{$value}'";
    }
    $variables['data'] = implode(' ', $data);

    if ($layer['type'] == 'image') {
      $layer['file_url'] = '';
      if (isset($layer['fileid'])) {
        $image = file_load($layer['fileid']);
        $layer['file_url'] = file_create_url($image->uri);
      }
    }

    $variables['layer'] = $layer;

    $style = array();
    $style[] = "z-index: {$layer['zindex']};";
    $style[] = "width: {$layer['width']}px;";
    $style[] = "height: {$layer['height']}px;";
    $style[] = "top: {$layer['top']}px;";
    $style[] = "left: {$layer['left']}px;";
    $variables['styles'] = implode(' ', $style);
  }

  /**
   * Get style options
   */
  function cute_slider_get_style_options($file_path) {

    $output = array();
    $file = fopen($file_path, 'r');
    $is_data = FALSE;
    if ($file !== FALSE) {
      while(!feof($file)) {
        $line = fgets($file);
        if (!$is_data) {
          if (strpos($line, '==start==') !== FALSE) {
            $is_data = TRUE;
            continue;
          }
        }
        else {
          if (strpos($line, '==end==') === FALSE) {
            $line = explode('|', $line);
            $output[$line[0]] = $line[1];
          }
          else {
            break;
          }
        };
      }
    }

    fclose($file);
    return $output;
  }

  /**
   * Implements hook template_preprocess_admin_slides_render()
   */
  function template_preprocess_cute_slider_admin_slides(&$variables) {
    $slides = $variables['slides'];
    $slider = $variables['slider'];

    $variables['class_fullwidth'] = "";
    $variables['default_bg'] = file_create_url("public://md_slider_def_bg.jpg");
    foreach ($slides as &$slide) {
      if ($slide->settings['backgroundimage'] != -1) {
        $background = file_load($slide->settings['backgroundimage']);
        if ($slider->settings['use_image_style']) {
          $slide->settings['background_url'] = image_style_url('cute_slider_' . $slider->slid . '_bg', $background->uri);
        }
        else {
          $slide->settings['background_url'] = file_create_url($background->uri);
        }
      }
      else {
        $slide->settings['background_url'] = $variables['default_bg'];
      }
    }
  }

  /**
   * Implements hook template_preprocess_admin_slide()
   */
  function template_preprocess_cute_slider_admin_slide(&$variables) {
    $slide = $variables['slide'];
    $settings = $slide->settings;

    $variables['background_url'] = $settings['background_url'];

    $settings['sid'] = $slide->sid;
    unset($settings['background_url']);
    $variables['slide_settings'] = drupal_json_encode($settings);
  }

  /**
   * Analyse google link to get font information
   */
  function cute_slider_process_google_web_font($fonts) {
    preg_match('/([^\?]+)(\?family=)?([^&\']+)/i', $fonts, $matches);
    $gfonts = explode("|", $matches[3]);

    for ($i = 0; $i < count($gfonts); $i++) {
      $gfontsdetail = explode(":", $gfonts[$i]);
      $gfontname = str_replace("+", " ", $gfontsdetail['0']);
      $gfontweigth = "";
      if (array_key_exists('1', $gfontsdetail)) {
        $gfontweigth = $gfontsdetail['1'];
      }
      $fontvars[] = array(
        'CSS' =>$gfontname,
        'Weight' => $gfontweigth,
      );
    }

    return $fontvars;
  }
