<?php
/**
 * @file theme.front.inc.
 * @author: Duynv
 * Date: 4/8/13
 */

/**
 * Implements template_preprocess_hook() for cute_slider.tpl.php
 */
function template_preprocess_cute_slider_front(&$vars) {
  $slider = $vars['slider'];
  $slides = CuteSlide::get_by_slider_id($slider->slid);
  $controls = array();

  # Prepare for slides
  $slide_order = 1;
  foreach ($slides as &$slide) {
    # Get slide image background
    if ($slide->settings['backgroundimage'] != -1) {
      $bg = file_load($slide->settings['backgroundimage']);
    }
    else {
      $bg = new stdClass();
      $bg->uri = "public://cute_slider_default_background.jpg";
    }

    if ($slider->settings['use_image_style']) {
      $slide->settings['backgroundimage'] = image_style_url("cute_slider_{$slider->slid}_bg", $bg->uri);
    }
    else {
      $slide->settings['backgroundimage'] = file_create_url($bg->uri);
    }

    # Get slide thumbnail image
    if ($slide->settings['thumbnail'] != -1) {
      $thubnail = file_load($slide->settings['thumbnail']);
    }
    else {
      $thubnail = $bg;
    }
    $slide->settings['thumbnail'] = image_style_url("cute_slider_{$slider->slid}_thumb", $thubnail->uri);

    # Get slide content
    $slide->content = _cute_slider_generate_slide_content($slider->slid, $slide, $slide_order, $controls);
    $slide_order++;

    # Create list transitions
    foreach ($slide->settings['trs3d'] as &$trans){
      $trans = 'tr' . $trans;
    }
    $slide->settings['trs3d'] = implode(',', $slide->settings['trs3d']);

    foreach ($slide->settings['trs2d'] as &$trans){
      $trans = 'tr' . $trans;
    }
    $slide->settings['trs2d'] = implode(',', $slide->settings['trs2d']);
  }

  # Prepare controls
  if ($slider->settings['show_thumbnail_bar'] && !$slider->settings['gallery_mode']) {
    $controls[] = '<li data-type="thumblist" data-autohide="true"></li>';
  }

  if ($slider->settings['show_nextprev']  && !$slider->settings['gallery_mode']) {
    $controls[] = '<li data-type="next"></li>';
    $controls[] = '<li data-type="previous"></li>';
  }

  if ($slider->settings['show_cyclebar'])
    $controls[] = '<li data-type="circletimer"></li>';

  if ($slider->settings['show_loadingbar'])
    $controls[] = '<li data-type="bartimer"></li>';

  if ($slider->settings['show_slidecontrol']) {
    if ($slider->settings['thumbnail_align'] == 'disable')
      $controls[] = '<li data-type="slidecontrol" data-thumb="false"></li>';
    else
      $controls[] = "<li data-type=\"slidecontrol\" data-thumbalign=\"{$slider->settings['thumbnail_align']}\"></li>";
  }

  $vars['controls'] = implode("\r\n", array_unique($controls));
  $vars['width'] = $slider->settings['width'];
  $vars['height'] = $slider->settings['height'];
  $vars['slides'] = $slides;
  $vars['template'] = $slider->settings['template'];
  $vars['hover_pause'] = ($slider->settings['pause_hover']) ? 'true' : 'false';

  if ($slider->settings['enable_shadow'] && !$slider->settings['gallery_mode']) {
    $templates = variable_get('cute_slider_templates');
    $shadow_image = $templates[$slider->settings['template']] . '/cute-theme/shadow.png';
    if (file_exists($shadow_image))
      $vars['shadow_image'] = base_path() . $shadow_image;
    else {
      $vars['shadow_image'] =  base_path() . drupal_get_path('module', 'cute_slider') . '/images/cute-theme/shadow.png';
    }
  }

  # Prepare classes for slider
  $slider_classes = array('cute-slider', "cute-slider-{$slider->slid}");
  if ($slider->settings['show_thumbnail_bar']) {
    $slider_classes[] = "thumblist-{$slider->settings['thumbbar_direction']}";
    $slider_classes[] = "{$slider->settings['thumbbar_direction']}-{$slider->settings['thumbbar_position']}";
  }
  $vars['slider_classes'] = implode(' ', $slider_classes);
}

/**
 * Generate slide html content
 */
function _cute_slider_generate_slide_content($slid, $slide, $slide_order, &$controls) {
  $output = "";

  # Generate slide link
  if ($slide->settings['linktext'] != "") {
    $link_target = ($slide->settings['linktarget']) ? '_blank' : 'none';
    $output .= theme('cute_slide_content', array('type' => 'link', 'elements' => array('link' => $slide->settings['linktext'], 'link_target' => $link_target)));
    $controls[] = '<li data-type="link"></li>';
  }

  # Generate slide info
  if ($slide->settings['infotitle'] != '' || $slide->settings['infotext'] != '') {
    $elements = array();
    $elements['align'] = $slide->settings['infoposition'];
    $elements['title'] = $slide->settings['infotitle'];
    $elements['text'] = $slide->settings['infotext'];
    $elements['button_text'] = ($slide->settings['infobuttontext'] != '') ? $slide->settings['infobuttontext'] : 'read more';
    $elements['button_link'] = $slide->settings['infobuttonlink'];
    $elements['button_target'] = ($slide->settings['infobuttontarget'] != '') ? $slide->settings['infobuttontarget'] : 'none';
    $elements['classes'] = "info-{$slid}-{$slide_order}";

    $output .= theme('cute_slide_content', array('type' => 'info', 'elements' => $elements));
    $controls[] = '<li data-type="slideinfo"></li>';
  }

  # Generate video link
  if ($slide->settings['videourl'] != "") {
    $output .= theme('cute_slide_content', array('type' => 'video', 'elements' => array('video_link' => $slide->settings['videourl'])));
    $controls[] = '<li data-type="video"></li>';
  }

  # Generate caption
  if (count($slide->layers)) {
    $elements = array();
    $order = 1;
    foreach ($slide->layers as $layer) {
      $caption = new stdClass();
      if (isset($layer['style']))
        $caption->class = implode(' ', array("caption-{$slid}-{$slide_order}-{$order}", $layer['style']));
      else
        $caption->class = "caption-{$slid}-{$slide_order}-{$order}";;
      $caption->delay = $layer['starttime'];
      $caption->effect = (isset($layer['startani'])) ? $layer['startani'] : 'fade';
      if ($layer['type'] == 'text')
        $caption->content = $layer['title'];
      else {
        $img = file_load($layer['fileid']);
        $caption->content = theme('image', array('path' => $img->uri, 'width' => $layer['width'], 'height' => $layer['height'], 'title' => $layer['title']));
      }

      if (isset($layer['link']) && is_array($layer['link'])) {
        $link = $layer['link'];
        if (strpos($link['value'], 'http') === FALSE) {
          $url = url($link['value'], array('absolute' => TRUE));
        }
        else {
          $url = $link['value'];
        }

        if ($layer['type'] == 'text')
          $caption->content = "<a title='{$link['title']}' href='{$url}'>{$layer['title']}</a>";
        else
          $caption->content = "<a title='{$link['title']}' href='{$url}'><img src='{$layer['url']}'/></a>";
      }

      $elements[] = $caption;
      $order++;
    }

    $output .= theme('cute_slide_content', array('type' => 'captions', 'elements' => $elements));
    $controls[] = '<li data-type="captions"></li>';
  }

  return $output;
}
