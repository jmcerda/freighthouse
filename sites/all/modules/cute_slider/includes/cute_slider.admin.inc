<?php
/**
 * @file cute_slider.admin.inc
 * User: duynguyen
 * Date: 4/3/13
 * Time: 9:05 AM
 * To change this template use File | Settings | File Templates.
 */

/**
 * Handle manage CuteSliders link
 */
function cute_slider_overview() {
  $sliders = CuteSlider::get_all();
  $rows = array();

  foreach ($sliders as $slider) {
    $row = array(theme('cute_slider_info', array('title' => $slider->title, 'description' => $slider->description)));
    $row[] = array('data' => l(t('Edit'), "admin/structure/cute-slider/{$slider->slid}/edit", array('absolute' => TRUE)));
    $row[] = array('data' => l(t('Configure'), "admin/structure/cute-slider/{$slider->slid}", array('absolute' => TRUE)));
    if (user_access('Super administer CuteSlider'))
      $row[] = array('data' => l(t('Clone'), "admin/structure/cute-slider/clone/{$slider->slid}"));
    $rows[] = $row;
  }

  return theme('table', array('header' => array(t('Title'), array('data' => t('Operations'), 'colspan' => '3')), 'rows' => $rows));
}

/**
 * Configure form for CuteSlider
 */
function cute_slider_configuration_form($form, &$form_state, $slider=NULL) {
  $settings = CuteSlider::get_default_settings();
  $title = '';
  $desc = '';

  # Add js and css for configure form
  $path = drupal_get_path('module', 'cute_slider');
  drupal_add_css($path . '/css/cute-slider.admin.css');
  drupal_add_js($path . '/js/cute-slider.configure.js');

  if ($slider) {
    $settings = array_merge($settings, $slider->settings);
    $title = $slider->title;
    $desc = $slider->description;

    # Add slider to form_state
    $form_state['slider'] = $slider;

    drupal_set_title(t('Configure CuteSlider: ' . $slider->title));
  }

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name use to identify cuteslider for administrator. This field is only show in admin page.'),
    '#default_value' => $title,
    '#required' => TRUE,
  );

  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine name'),
    '#default_value' => ($slider) ? $slider->machine_name : '',
    '#maxlength' => MENU_MAX_MENU_NAME_LENGTH_UI,
    '#description' => t('A unique name to identify for the menu. It must only contain lowercase letters, numbers and hyphens.'),
    '#machine_name' => array(
      'exists' => 'cute_slider_check_machine_name',
      'source' => array('title'),
      'label' => t('Machine name'),
      'replace_pattern' => '[^a-z0-9-]+',
      'replace' => '-',
    ),
    '#disabled' => ($slider && $slider->machine_name != ''),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('The short description about this CuteSlider.'),
    '#default_value' => $desc,
    '#resizable' => FALSE,
    '#rows' => 2,
  );

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['settings']['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#default_value' => $settings['width'],
		'#attributes' => array('class' => array('w60')),
    '#prefix' => '<h3>Basic</h3>',
    '#field_suffix' => 'px',
    '#description' => t('The slider width in pixels.'),
  );

  $form['settings']['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#default_value' => $settings['height'],
		'#attributes' => array('class' => array('w60')),
    '#description' => t('The slider height in pixels.'),
    '#field_suffix' => 'px',
  );

  $form['settings']['use_image_style'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto crop image'),
    '#default_value' => $settings['use_image_style'],
    '#description' => t('Enable this option to crop image to dimensions above'),
  );

  $form['settings']['responsive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Responsiveness'),
    '#default_value' => $settings['responsive'],
    '#description' => t('Enable this option to turn CuteSlider into a responsiveness slider.'),
  );

  $form['settings']['responsive_width'] = array(
    '#type' => 'container'
  );

  $form['settings']['responsive_width']['min_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Min width'),
    '#default_value' => $settings['min_width'],
		'#attributes' => array('class' => array('w60')),
    '#description' => t('The slider minimum width for responsive active. Zero means disable.'),
		'#field_suffix' => 'px',
  );

  $form['settings']['responsive_width']['max_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Max width'),
    '#default_value' => $settings['max_width'],
		'#attributes' => array('class' => array('w60')),
    '#description' => t('The slider maximum width for responsive active. Zero means disable.'),
		'#field_suffix' => 'px',
  );

  $form['settings']['thumb_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Thumbnail width'),
    '#default_value' => $settings['thumb_width'],
		'#attributes' => array('class' => array('w60')),
    '#description' => t('The thumbnail width in pixels.'),
    '#field_suffix' => 'px',
  );

  $form['settings']['thumb_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Thumbnail height'),
    '#default_value' => $settings['thumb_height'],
		'#attributes' => array('class' => array('w60')),
    '#description' => t('The thumbnail height in pixels.'),
    '#field_suffix' => 'px',
  );

  $form['settings']['auto'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically start slideshow'),
    '#default_value' => $settings['auto'],
    '#description' => t('If enable, the slideshow will automatically start after page load.'),
    '#prefix' => '<h3>Slideshow</h3>',
  );

  $form['settings']['pause_hover'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pause on hover'),
    '#default_value' => $settings['min_width'],
    '#description' => t('Slideshow will pause when mouse poiter is over on CuteSlider.')
  );

  # Get list templates available
  $templates_list = _template_list();
  variable_set('cute_slider_templates', $templates_list);
  $templates = array_keys($templates_list);
  $template_options = array();
  foreach ($templates as $template) {
    $template_options[$template] = $template;
  }
  $form['settings']['template'] = array(
    '#type' => 'select',
    '#title' => t('Choose template for slider'),
    '#options' => $template_options,
    '#default_value' => $settings['template'],
    '#description' => t('Template what your CuteSlider will display.'),
    '#prefix' => '<h3>Appearance</h3>',
  );

  $form['settings']['css_generate'] = array(
    '#type' => 'checkbox',
    '#title' => t("Do not render CSS file, I'll do it myself"),
    '#default_value' => $settings['css_generate'],
    '#description' => t('Make sure you know what to do before check it'),
  );

  $form['settings']['enable_shadow'] = array(
    '#type' => 'checkbox',
    '#title' => t('Shadow'),
    '#description' => t('If you enable this option, there will be a shadow below the slider.'),
    '#default_value' => $settings['enable_shadow'],
  );

  $form['settings']['gallery_mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Gallery mode'),
    '#description' => t('If you enable this option, slideshow will be convert to a gallery slider.'),
    '#default_value' => $settings['gallery_mode'],
  );

  $form['settings']['show_slidecontrol'] = array(
    '#type' => 'checkbox',
    '#title' => t('Bullets bar'),
    '#default_value' => $settings['show_slidecontrol'],
    '#description' => t('if disable, the bullets navigation will not display.'),
    '#prefix' => '<h3>Navigation</h3>',
  );

  $form['settings']['thumbnail_align'] = array(
    '#type' => 'select',
    '#title' => t('Thumbnail aligment with bullets'),
    '#default_value' => $settings['thumbnail_align'],
    '#options' => array('disable' => t('Disable'), 'bottom' => t('Bottom'), 'top' => t('Top')),
    '#description' => t('Choose aligment of thumbnails with bullets when mouse pointer is over bullet. If choose disable, thumbnail will not show.'),
  );

  $form['settings']['show_thumbnail_bar'] = array(
    '#type' => 'checkbox',
    '#title' => t('Thumbnails list'),
    '#default_value' => $settings['show_thumbnail_bar'],
    '#description' => t('If enable, thumbnails list will display.'),
  );

  $form['settings']['thumbbar_direction'] = array(
    '#type' => 'select',
    '#title' => t('Thumbnails list direction'),
    '#default_value' => $settings['thumbbar_direction'],
    '#options' => array('vertical' => t('Vertical'), 'horizontal' => t('Horizontal')),
    '#description' => t('Choose direction for thumbnail list.'),
    '#prefix' => '<div id="thumbbar-settings">',
  );

  $form['settings']['thumbbar_position'] = array(
    '#type' => 'select',
    '#title' => t('Thumbnail list position'),
    '#default_value' => $settings['thumbbar_position'],
    '#options' => array('left' => t('Left'), 'right' => t('Right'), 'top' => t('Top'), 'bottom' => t('Bottom')),
    '#description' => t('Choose position where thumbnail list will display.'),
    '#suffix' => '</div>',
  );

  $form['settings']['show_nextprev'] = array(
    '#type' => 'checkbox',
    '#title' => t('Next and Prev buttons'),
    '#default_value' => $settings['show_nextprev'],
    '#description' => t('If disable, Next and Prev buttons will not show.'),
  );

  $form['settings']['show_loadingbar'] = array(
    '#type' => 'checkbox',
    '#title' => t('Bar timer'),
    '#default_value' => $settings['show_loadingbar'],
    '#description' => t('If disable, bar timer will not show on slides.'),
  );

  $form['settings']['show_cyclebar'] = array(
    '#type' => 'checkbox',
    '#title' => t('Circle timer'),
    '#default_value' => $settings['show_cyclebar'],
    '#description' => t('If enable, circle timer will add on slides. Please note that this type timer is only works with modern browsers that supports canvas element.'),
  );

  $form['settings']['google_font'] = array(
    '#type' => 'textarea',
    '#title' => t('@import'),
    '#resizable' => FALSE,
    '#rows' => 1,
    '#description' => t("For example: &lt;link href='<strong>http://fonts.googleapis.com/css?family=Roboto+Condensed</strong>' rel='stylesheet' type='text/css'&gt"),
    '#default_value' =>  $settings['google_font'],
    '#prefix' => '<div id="customfont-wrap" class="form-subform"><h3>Google Web Fonts</h3>
      <ul class="steps">
      <li>Go to <a href="http://www.google.com/webfonts" target="_blank">www.google.com/webfonts</a>, choose your fonts and add to collection</li>
      <li>Click &quot;Use&quot; in the bottom bar after choose fonts</li>
      <li>Find &quot;Add this code to your website&quot;, copy from <strong>http://</strong> to the nearest <strong>\'</strong> and paste it below to activate.</li>
      </ul>',
  );

  $form['settings']['load_google_font'] = array(
    '#type' => 'checkbox',
    '#title' => t("Do not add fonts to theme. My theme's already included this fonts. "),
    '#default_value' => $settings['load_google_font'],
    '#description' => t('If enable, this font will not load because it is defined load in your theme.'),
  );

  $form['callbacks'] = array(
    '#type' => 'fieldset',
    '#title' => t('Callbacks'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $callbacks = array('change_start', 'change_end', 'wating', 'change_next_slide', 'wating_for_next');
  foreach ($callbacks as $callback) {
    $form['callbacks'][$callback] = array(
      '#type' => 'textarea',
      '#title' => t('Cute.SliderEvent.' . strtoupper($callback)),
      '#default_value' => $settings[$callback],
      '#attributes' => array('class' => array('cute-callback')),
      '#resizable' => FALSE,
    );
  }

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  if ($slider) {
    $form['save_edit'] = array(
      '#type' => 'submit',
      '#value' => t('Save & Edit'),
    );

    if (user_access('Super administer CuteSlider')) {
      $form['delete'] = array(
        '#type' => 'submit',
        '#value' => t('Delete')
      );
    }
  }

  return $form;
}

/**
 * Implements handle submit configure CuteSlider form
 */
function cute_slider_configuration_form_submit($form, &$form_state) {
  $configurations = $form_state['values'];
  $settings = CuteSlider::get_default_settings();
  unset($settings['color_saved']);
  $slider = NULL;
  $action = "";

  # Get all custom configure for CuteSlider
  foreach ($settings as $key => $val) {
      $settings[$key] = $configurations[$key];
  }

  # Process for each action submit
  switch($configurations['op']) {
    case t('Save'):
      if (!isset($form_state['slider'])) {
        # Create new CuteSlider
        $slider = CuteSlider::create($configurations['title'], $configurations['description'], $settings, $configurations['machine_name']);
        if ($slider) {
          $action = "created.";
          $form_state['redirect'] = "admin/structure/cute-slider/{$slider->slid}/edit";
        }
        else {
          drupal_set_message(t('CuteSlider <em>' . $configurations->title . '</em>  has been created fail.'));
        }
      }
      else {
        # Update existed CuteSlider
        $slider = $form_state['slider'];
        $slider->title = $configurations['title'];
        $slider->description = $configurations['description'];
        $slider->settings = $settings;

        if ($slider->save())
          $action = 'updated.';
        else
          $action = 'updated fail.';

        $form_state['redirect'] = "admin/structure/cute-slider";
      }
      drupal_set_message(t('CuteSlider <em>' . $slider->title . '</em>  has been ' . $action));
      break;

    case t('Save & Edit'):
      $slider = $form_state['slider'];
      $slider->title = $configurations['title'];
      $slider->description = $configurations['description'];
      $slider->settings = $settings;

      if ($slider->save())
        $action = 'updated.';
      else
        $action = 'updated fail.';

      $form_state['redirect'] = "admin/structure/cute-slider/{$slider->slid}/edit";
      drupal_set_message(t('CuteSlider <em>' . $slider->title . '</em>  has been ' . $action));
      unset($_GET['destination']);
      break;

    case t('Delete'):
      $slider = $form_state['slider'];
      $form_state['redirect'] = array("admin/structure/cute-slider/delete/{$slider->slid}", array('query' => drupal_get_destination()));
      return;
  }

  # Update image_style option
  if ($slider && $configurations['op'] != 'Delete' && $configurations['use_image_style'])
    cute_slider_update_image_style("cute_slider_{$slider->slid}_bg", $configurations['width'], $configurations['height']);

  # Update image style for thumbnails
  cute_slider_update_image_style("cute_slider_{$slider->slid}_thumb", $configurations['thumb_width'], $configurations['thumb_height']);

  # Generate css custom file
  cute_slider_generate_custom_css($slider->slid, $slider->machine_name, CuteSlide::get_by_slider_id($slider->slid), $settings);
}

/**
 * Create edit form for CuteSlider
 */
function cute_slider_edit_form($form, &$form_state, $slider=NULL) {
  if (!$slider) {
    $markup = '<p>This CuteSlider not exist. You need create CuteSlider first and edit them.</p><p>You can click ';
    $markup .= l(t('Here'), 'admin/structure/cute-slider/create', array('absolute' => TRUE));
    $markup .= ' to create new CuteSlider.</p>';
    $form['error_msg'] = array(
      '#markup' => $markup,
    );

    drupal_set_title(t('CuteSlider not found'));

    return $form;
  }

  # Set title for page and remove last breadcrumb
  $breadcrumb = drupal_get_breadcrumb();
  array_pop($breadcrumb);
  drupal_set_breadcrumb($breadcrumb);
  drupal_set_title(t('Edit CuteSlider: ' . $slider->title));

  # Add media file browser lib
  $module_path = drupal_get_path('module', 'cute_slider');
  include_once drupal_get_path('module', 'media') . '/wysiwyg_plugins/media.inc';
  media_include_browser_js();

  # Add jquery ui libraries
  drupal_add_library('system', 'ui.tabs');
  drupal_add_library('system', 'ui.sortable');
  drupal_add_library('system', 'ui.draggable');
  drupal_add_library('system', 'ui.droppable');
  drupal_add_library('system', 'ui.dialog');
  drupal_add_library('system', 'jquery.cookie');

  # Add module css and js file
  drupal_add_css($module_path . '/js/colorpicker/css/colorpicker.css');
  drupal_add_css($module_path . '/css/md-slider-admin.css');
  cute_slider_load_custom_style_css($slider->slid);

  drupal_add_js(array('cutesliderPath' => $module_path), 'setting');
  drupal_add_js($module_path . '/js/colorpicker/js/colorpicker.js');
  drupal_add_js($module_path . '/js/jquery.qtip-1.0.0-rc3.min.js');
  drupal_add_js($module_path . '/js/md-slider-lib.js');
  drupal_add_js($module_path . '/js/md-slider-toolbar.js');
  drupal_add_js($module_path . '/js/md-slider-timeline.js');
  drupal_add_js($module_path . '/js/md-slider-panel.js');
  drupal_add_js($module_path . '/js/cute-slider-admin.edit.js');

  # Get settings for slider
  $settings = array_merge(CuteSlider::get_default_settings(), $slider->settings);

  $form['slider_main'] = array(
    '#markup' => theme('cute_slider_edit', array('slider' => $slider)),
  );

  $form['slider_id'] = array(
    '#type' => 'hidden',
    '#default_value' => $slider->slid,
  );

  $form['slider_data_save'] = array(
    '#type' => 'textarea',
    '#default_value' => '',
    '#resizable' => FALSE,
  );

  $form['color_saved'] = array(
    '#type' => 'hidden',
    '#default_value' => $settings['color_saved'],
  );

  $form['slider_save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['slider_save_continue'] = array(
    '#type' => 'submit',
    '#value' => t('Save & Continue'),
  );

  return $form;
}

/**
 * Implements handle submit edit CuteSlider form
 */
function cute_slider_edit_form_submit($form, &$form_state) {
  $custom = $form_state['values'];
  $slides = drupal_json_decode($custom['slider_data_save']);
  $slider_id = $custom['slider_id'];

  $slider = CuteSlider::get_by_id($slider_id);
  $slider->settings['color_saved'] = $custom['color_saved'];
  $slider->save();

  foreach ($slides as $index => $slide) {
    $sid = $slide['itemsetting']['sid'];
    unset($slide['itemsetting']['sid']);
    $settings = $slide['itemsetting'];
    $layers = $slide['boxitems'];

    if ($sid != -1) {
      # Update current slide
      $slide_saved = CuteSlide::get($sid);
      $slide_saved->position = $index;
      $slide_saved->settings = $settings;
      $slide_saved->layers = $layers;
      $slide_saved->save();
    }
    else {
      # Create new slide
      CuteSlide::create($slider_id, $index, $settings, $layers);
    }
  }

  # Generate custom css file
  cute_slider_generate_custom_css($slider->slid, $slider->machine_name, CuteSlide::get_by_slider_id($slider->slid), $slider->settings);

  # Set redirect form
  if ($custom['op'] == t('Save')) {
    $form_state['redirect'] = 'admin/structure/cute-slider';
  }
  else {
    unset($_GET['destination']);
  }
}

/**
 * Create delete CuteSlider form
 */
function cute_slider_delete_form($form, &$form_state, $slider) {
  # Set page title
  drupal_set_title(t("Are you sure want to delete '{$slider->title}' CuteSlider?"));

  $form['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );

  $form['cancel'] = array(
    '#markup' => l(t('Cancel'), $_GET['destination'], array('absolute' => TRUE)),
  );

  # Pass slider id in state form
  $form_state['slider'] = $slider;

  return $form;
}

/**
 * Handle submit delete form
 */
function cute_slider_delete_form_submit($form, &$form_state) {
  $slider = $form_state['slider'];
  $action = 'deleted fail.';
  if (CuteSlider::delete($slider->slid)) {
    $action = 'deleted';
    unset($_GET['destination']);
    $form_state['redirect'] = 'admin/structure/cute-slider';
  }

  # Set action message
  drupal_set_message(t("CuteSlider <em>{$slider->title}</em> has been {$action}"));
}

/**
 * Clone function link
 */
function cute_slider_clone_slider($slider) {
  $classes = array();

  if (!$slider) {
    drupal_set_message(t('Cuteslider can not clone which is not existed slider.'));
  }
  else {
    $clone = CuteSlider::create('clone of ' . $slider->title, $slider->description, $slider->settings);
    if ($clone) {
      $slides = CuteSlide::get_by_slider_id($slider->slid);
      foreach($slides as $slide) {
        # Create slide in database
        CuteSlide::create($clone->slid, $slide->position, $slide->settings, $slide->layers);
      }

      # Set message
      drupal_set_message(t("CuteSlider <em>{$slider->title}</em> has been clone."));

      # Create image_style for background image
      if ($clone->settings['use_image_style'])
        cute_slider_update_image_style("cute_slider_{$clone->slid}_bg", $clone->settings['width'], $clone->settings['height']);

      # Create image style for thumbnail
      cute_slider_update_image_style("cute_slider_{$clone->slid}_thumb", $clone->settings['thumb_width'], $clone->settings['thumb_height']);

      # Generate custom css file
      cute_slider_generate_custom_css($clone->slid, $clone->machine_name, CuteSlide::get_by_slider_id($clone->slid), $clone->settings);
    }
    else
      drupal_set_message(t("CuteSlider <em>{$slider->title}</em> has been clone faild."));
  }

  drupal_goto('admin/structure/cute-slider');
}

/**
 * Transition library ajax
 */
function cute_slider_transition_view() {
  print theme('cute_transition_view', array('parameters' => $_REQUEST));
}

/**
 * Handle request get slide background
 */
function cute_slider_get_background() {
  $fid = -1;
  $slid = -1;
  $output = '';

  # Get file id to request image url
  if (isset($_POST['fid']))
    $fid = $_POST['fid'];

  # Get slider id
  if (isset($_POST['slider_id']))
    $slid = $_POST['slider_id'];

  # Validate received parameters
  if ($slid == -1) {
    print $output;
    exit();
  }

  # Create image url to response
  if ($fid != -1)
    $file = file_load($fid);
  else {
    $file = new stdClass();
    $file->uri = "public://cute_slider_default_background.jpg";
  }
  $slider = CuteSlider::get_by_id($slid);
  if ($slider->settings['use_image_style']) {
    $output = image_style_url("cute_slider_{$slid}_bg", $file->uri);
  }
  else {
    $output = file_create_url($file->uri);
  }

  print $output;
}

/**
 * Create image_style
 */
function cute_slider_update_image_style($image_style_name, $width, $height, $allow_scaleup = FALSE) {
  # Load image_style if it existed
  $style = image_style_load($image_style_name);
  if (empty($style)) {
    $style = image_style_save(array('name' => $image_style_name));
  }
  else {
    # Remove all effect in this image style
    $current_effects = $style['effects'];
    foreach ($current_effects as $effect) {
      image_effect_delete($effect);
    }
  }

  # Create effect for image_style
  $new_effect = array(
    'name' => 'image_scale_and_crop',
    'data' => array(
      'width' => $width,
      'height' => $height,
      'scaleup' => $allow_scaleup,
    ),
    'isid' => $style['isid'],
  );

  # Save effect for image_styles
  image_effect_save($new_effect);
}

/**
 * Callback for delete slide request
 */
function cute_slider_delete_slide(){
  $sid = $_POST['sid'];
  if (CuteSlide::delete($sid)) {
    print "OK";
  }
  else {
    print "Can not delete slide: {$sid}";
  }
}

/**
 * Generate layer class
 */
function cute_slider_generate_layer_class($layer, $class_name, $width, $height, &$classes) {
  $output = array();

  # Generate size and position css
  $output[] = "\nwidth: " . (100*$layer->width)/$width . "%;\n";
  $output[] = "height: " . (100*$layer->height)/$height . "%;\n";
  $output[] = "left: " . (100*$layer->left)/$width . "%;\n";
  $output[] = "top: " . (100*$layer->top)/$height . "%;\n";
  $output[] = "position: absolute;\n";

  if (isset($layer->link)) {
    $output[] = "overflow:  visible !important;\n";
    $classes[] = ".{$class_name}{" . implode(' ', $output) . "}";
    $output = array();
  }

  # Generate css for background
  if (isset($layer->backgroundcolor)) {
    if (isset($layer->backgroundtransparent)) {
      $rgb = cute_slider_hex_to_rgb($layer->backgroundcolor);
      $alpha = $layer->backgroundtransparent / 100;
      $output[] = "background: rgb({$rgb[0]}, {$rgb[1]}, {$rgb[2]});background: rgba({$rgb[0]}, {$rgb[1]}, {$rgb[2]}, {$alpha});\n";
    } else {
      if (is_string($layer->backgroundcolor)) {
        $output[] = "background: #{$layer->backgroundcolor};\n";
      }
      else {
        $output[] = "background: #000;\n";
      }
    }
  }

  # Process style for layer border
  if (isset($layer->borderposition) && isset($layer->borderwidth) && $layer->borderposition > 0 && $layer->borderwidth > 0) {
    $color = (isset($layer->bordercolor)) ? $layer->bordercolor : "000";
    $border_style = (isset($layer->borderstyle)) ? $layer->borderstyle : "solid";

    # Process border layer position
    $positions = cute_slider_process_layer_border_position($layer->borderposition);
    if (count($positions) == 4) {
      $output[] = "border: {$layer->borderwidth}px {$border_style} #{$color};\n";
    }
    else {
      foreach ($positions as $position) {
        $output[] = "border-{$position}: {$layer->borderwidth}px {$border_style} #{$color};\n";
      }
    }
  }

  # Generate css for border-radius
  if (isset($layer->bordertopleftradius) && $layer->bordertopleftradius > 0) {
    $output[] = "-webkit-border-top-left-radius: {$layer->bordertopleftradius}px; -moz-border-radius-topleft: {$layer->bordertopleftradius}px; border-top-left-radius: {$layer->bordertopleftradius}px;\n";
  }

  if (isset($layer->bordertoprightradius) && $layer->bordertoprightradius > 0) {
    $output[] = "-webkit-border-top-right-radius: {$layer->bordertoprightradius}px; -moz-border-radius-topright: {$layer->bordertoprightradius}px; border-top-right-radius: {$layer->bordertoprightradius}px;\n";
  }

  if (isset($layer->borderbottomleftradius) && $layer->borderbottomleftradius > 0) {
    $output[] = "-webkit-border-bottom-left-radius: {$layer->borderbottomleftradius}px; -moz-border-radius-bottomleft: {$layer->borderbottomleftradius}px; border-bottom-left-radius: {$layer->borderbottomleftradius}px;\n";
  }

  if (isset($layer->borderbottomrightradius) && $layer->borderbottomrightradius > 0) {
    $output[] = "-webkit-border-bottom-right-radius: {$layer->borderbottomrightradius}px; -moz-border-radius-bottomright: {$layer->borderbottomrightradius}px; border-bottom-right-radius: {$layer->borderbottomrightradius}px;\n";
  }

  # Process for padding
  if (isset($layer->paddingtop) && $layer->paddingtop != '')
    $output[] = "padding-top: {$layer->paddingtop}px;\n";
  if (isset($layer->paddingright) && $layer->paddingright != '')
    $output[] = "padding-right: {$layer->paddingright}px;\n";
  if (isset($layer->paddingbottom) && $layer->paddingbottom != '')
    $output[] = "padding-bottom: {$layer->paddingbottom}px;\n";
  if (isset($layer->paddingleft) && $layer->paddingleft != '')
    $output[] = "padding-left: {$layer->paddingleft}px;\n";

  # Process styles for text layer
  if ($layer->type == 'text') {
    if (isset($layer->color) && $layer->color != '') {
      if ($layer->color != '0')
        $output[] = "color: #{$layer->color} !important;\n";
      else
        $output[] = "color: #000 !important;\n";
    }

    if (isset($layer->textalign) && $layer->textalign != '') {
      $output[] = "text-align: {$layer->textalign};\n";
    }

    if (isset($layer->fontsize) && $layer->fontsize !='') {
      $fontsize = $layer->fontsize / 12;
      $output[] = "font-size: {$fontsize}em;\n";
    }

    if (isset($layer->fontweight) && $layer->fontweight != '') {
      if (is_numeric($layer->fontweight) === FALSE) {
        $font_w = substr($layer->fontweight, 0, 3);
        $font_s = substr($layer->fontweight, 3);
        $output[] = "font-weight: {$font_w};\n";
        $output[] = "font-style: {$font_s};\n";
      }
      else
        $output[] = "font-weight: {$layer->fontweight};\n";
    }

    if (isset($layer->fontfamily) && $layer->fontfamily != '') {
      $output[] = "font-family: {$layer->fontfamily};\n";
    }

    if (isset($layer->textdecoration) && $layer->textdecoration != '') {
      $output[] = "text-decoration: {$layer->textdecoration};\n";
    }

    if (isset($layer->texttransform) && $layer->texttransform != '') {
      $output[] = "text-transform: {$layer->texttransform};\n";
    }
  }

  if (isset($layer->link)) {
    $output[] = "display: block;\nwidth: 100%;\nheight: 100%;\n";
    $classes[] = ".{$class_name} a {" . implode(' ', $output) . "}";
  }
  else {
    $classes[] = ".{$class_name} {" . implode(' ', $output) . "}";
  }
}

/**
 * Process border layer position
 */
function cute_slider_process_layer_border_position($border_position) {
  $border_pos = array();

  if ($border_position & 1)
    $border_pos[] = "top";

  if ($border_position & 2)
    $border_pos[] = "right";

  if ($border_position & 4)
    $border_pos[] = "bottom";

  if ($border_position & 8)
    $border_pos[] = "left";

  return $border_pos;
}

/**
 * Convert hex to rgb value
 */
function cute_slider_hex_to_rgb($hex) {
  $hex = str_replace("#", "", $hex);

  if (strlen($hex) == 3) {
    $r = hexdec(substr($hex, 0, 1) . substr($hex, 0, 1));
    $g = hexdec(substr($hex, 1, 1) . substr($hex, 1, 1));
    $b = hexdec(substr($hex, 2, 1) . substr($hex, 2, 1));
  } else {
    $r = hexdec(substr($hex, 0, 2));
    $g = hexdec(substr($hex, 2, 2));
    $b = hexdec(substr($hex, 4, 2));
  }
  return array($r, $g, $b);
}

/**
 * Import and Export form
 */
function cute_slider_import_export_form($form, &$form_state) {
  # Get all CuteSliders are existing
  $sliders = CuteSlider::get_all();

  $sliders_options = array();
  foreach ($sliders  as $slider) {
    $sliders_options[$slider->slid] = $slider->title;
  }
  $form['export'] = array(
    '#type' => 'fieldset',
    '#title' => t('Export'),
    '#collapsible' => FALSE,
  );

  $form['export']['sliders'] = array(
    '#type' => 'radios',
    '#title' => t('Choose sliders to export'),
    '#options' => $sliders_options,
    '#default_value' => array(),
  );

  $form['export']['export_button'] = array(
    '#markup' => '<div><input type="button" name="export-button" class="form-submit" value="Export" /></div>'
  );

  $form['export']['export_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Export data'),
    '#default_value' => '',
    '#description' => t('Copy this data paste into input into Import form of site which you want to import.'),
    '#resizable' => FALSE,
  );

  $form['import'] = array(
    '#type' => 'fieldset',
    '#title' => t('Import'),
    '#collapsible' => FALSE,
  );


  $form['import']['machine_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Machine name'),
    '#default_value' => '',
    '#description' => t('Enter the machine name to use for this CuteSlider if it is different from the source CuteSlider. Leave blank to use the name of the CuteSlider. It must only contain lowercase letters, numbers and hyphens.'),
    '#resizable' => FALSE,
  );

  $form['import']['import_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Import data'),
    '#default_value' => '',
    '#description' => t('Paste CuteSlider data export from another site here to import to this site.'),
    '#resizable' => FALSE,
  );

  $form['import']['import_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  drupal_add_js(drupal_get_path('module', 'cute_slider') . '/js/cute-slider-export.js');

  return $form;
}

/**
 * Validate submit form
 */
function cute_slider_import_export_form_validate($form, &$form_state) {
  if ($form_state['values']['machine_name'] != '' && !preg_match('/^[a-z0-9\-]{1,}$/', $form_state['values']['machine_name'])) {
    form_set_error('machine_name', t('Machine name do not valid.'));
  }
}

/**
 * Handle submit import form
 */
function cute_slider_import_export_form_submit($form, &$form_state) {
  $import_data = $form_state['values']['import_data'];
  $new_name = $form_state['values']['machine_name'];

  if ($import_data == '') {
    drupal_set_message(t('Data import is invalided.'), 'error');
    return;
  }

  $slider_data = drupal_json_decode($import_data);
  $slider_data = array_shift($slider_data);
  if (!isset($slider_data['title']) || !isset($slider_data['machine_name'])
    || !isset($slider_data['description']) || !isset($slider_data['settings']) || !isset($slider_data['slides'])) {
    drupal_set_message(t('CuteSlider: Data import is invalided.'), 'error');
    return;
  }

  # Check machine name for CuteSlider is imported
  if ($new_name == '' && cute_slider_check_machine_name($slider_data['machine_name'])) {
    drupal_set_message(t('A CuteSlider by that machine name already exists; please choose a different machine name'), 'error');
    return;
  }

  # Add slider in database
  $slider = CuteSlider::create($slider_data['title'], $slider_data['description'], $slider_data['settings'], ($new_name != '') ? $new_name : $slider_data['machine_name']);
  if (!$slider) {
    drupal_set_message(t('CuteSlider: Import ' . $slider_data['title'] . 'unsuccessful.'), 'error');
    return;
  }

  foreach ($slider_data['slides'] as $slide_data) {
    if (!isset($slide_data['position']) || !isset($slide_data['settings']) || !isset($slide_data['layers']))
      continue;

    CuteSlide::create($slider->slid, $slide_data['position'], $slide_data['settings'], $slide_data['layers']);
  }

  # Create image_style for background image
  if ($slider->settings['use_image_style'])
    cute_slider_update_image_style("cute_slider_{$slider->slid}_bg", $slider->settings['width'], $slider->settings['height']);

  # Create image style for thumbnail image
  cute_slider_update_image_style("cute_slider_{$slider->slid}_thumb", $slider->settings['thumb_width'], $slider->settings['thumb_height']);

  # Generate file custom css for slider
  cute_slider_generate_custom_css($slider->slid, $slider->machine_name, CuteSlide::get_by_slider_id($slider->slid), $slider->settings);

  drupal_set_message(t('CuteSlider: Import successful.'));
}

  /**
 * Callback for export data
 */
function cute_slider_export_data() {
  if (!isset($_POST['slids']) || $_POST['slids'] == '') {
    print 'Data invalid'; exit;
  }
  else {
    $response = array();
    $slids = explode(',', $_POST['slids']);

    $sliders = CuteSlider::get_by_list_id($slids);
    $slides = CuteSlide::get_by_list_sliders($slids);

    foreach ($sliders as $slider) {
      $slider_data = array(
        'title' => $slider->title,
        'machine_name' => $slider->machine_name,
        'description' => $slider->description,
        'settings' => $slider->settings
      );
      $slider_data['slides'] = cute_slider_get_slides_data($slider->slid, $slides);
      $response[] = $slider_data;
    }

    print drupal_json_encode($response);
  }
}

/**
 * Get slider slides data
 */
function cute_slider_get_slides_data($slid, &$slides) {
  $output = array();
  foreach ($slides as $key => $slide) {
    if ($slide->slid == $slid) {
      $output[] = array('position' => $slide->position, 'settings' => $slide->settings, 'layers' => $slide->layers);
      unset($slides[$key]);
    }
  }

  return $output;
}

/**
 * Generate configure css classes
 */
function cute_slider_generate_configure_css($slid, $settings, &$classes) {
  # Generate class for galery mode
  if ($settings['gallery_mode']) {
    $bottom_height = $settings['thumb_height'] + 25;
    $classes[] = "#cute-slider-{$slid}-wrapper .br-bottom {height: {$bottom_height}px}";
    $classes[] = "#cute-slider-{$slid}-wrapper .br-list-thumb {height: {$settings['thumb_height']}px; width: {$settings['thumb_height']}px}";
  }

  # Create css for cute-slider tag and wrapper tag
  $css_inline = "#cute-slider-{$slid}-wrapper {margin: 0 auto; ";
  if ($settings['responsive']) {
    $css_inline .= "width: 100%; ";
    if ($settings['min_width'] != 0)
      $css_inline .= "min-width: {$settings['min_width']}px; ";

    if ($settings['max_width'] != 0)
      $css_inline .= "max-width: {$settings['max_width']}px; ";
  }
  else {
    $css_inline .= "width: {$settings['width']}px; ";
  }
  $css_inline .= "}";
  $classes[] = $css_inline;

  # Generate css classes for thumbnail list
  if ($settings['show_thumbnail_bar']) {
    $width = $settings['thumb_width'];
    $height = $settings['thumb_height'];
    $position = $settings['thumbbar_position'];
    $direction = $settings['thumbbar_direction'];

    $classes[] = "#cute-slider-{$slid}-wrapper .br-list-thumb {height: {$height}px; width: {$width}px;}";
    if ($direction == 'horizontal') {
      $position_h = (int)$height + 1;
      $classes[] = "#cute-slider-{$slid}-wrapper .horizontal-{$position} {margin-{$position}: {$position_h}px}";
      $classes[] = "#cute-slider-{$slid}-wrapper .horizontal-{$position} .br-thumblist {{$position}: -{$position_h}px}";
      $classes[] = "#cute-slider-{$slid}-wrapper .thumblist-horizontal .br-thumblist-frame {height: {$height}px}";
    }
    else {
      $position_w = (int)$width + 1;
      $classes[] = "#cute-slider-{$slid}-wrapper .vertical-{$position} .br-thumblist {{$position}: -{$position_w}px}";
      $classes[] = "#cute-slider-{$slid}-wrapper  .thumblist-vertical .br-thumblist, #cute-slider-{$slid}-wrapper .thumblist-vertical .br-thumblist-frame {width: {$width}px}";
    }
  }
}

/**
 * Generate css classes for layers
 */
function cute_slider_generate_layers_css($slid, $slides, &$classes, $width, $height) {
  foreach ($slides as $index => $slide) {
    foreach ($slide->layers as $key => &$layer) {
      $slide_index = $index + 1;
      $layer_index = $key + 1;

      # Generate css classes for layers
      $class_name = "caption-{$slid}-{$slide_index}-{$layer_index}";
      cute_slider_generate_layer_class((object)$layer, $class_name, $width, $height, $classes);

      # Generate css for link hover
      if (isset($layer['link']) && is_array($layer['link'])) {
        $css = cute_slider_generate_layer_link_css($layer['link']);
        if ($css != '')
          if ($layer['type'] != "text")
            $classes[] = ".caption-{$slid}-{$slide_index}-{$layer_index} a:hover img" . $css;
          else
            $classes[] = ".caption-{$slid}-{$slide_index}-{$layer_index} a:hover" . $css;
      }
    }
  }
}

/**
 * Generate css files
 */
function cute_slider_generate_custom_css($slid, $machine_name, $slides, $settings) {
  $classes = array();
  $width = $settings['width'];
  $height = $settings['height'];

  # Generate css for configure
  if (!$settings['css_generate'])
    cute_slider_generate_configure_css($slid, $settings, $classes);

  # Generate css classes for layers
  cute_slider_generate_layers_css($slid, $slides, $classes, $width, $height);

  # Write content to css file
  $content = implode("\r\n", $classes);
  file_unmanaged_save_data($content, "public://cute-slider-{$machine_name}-custom.css", FILE_EXISTS_REPLACE);
}

/**
 * Generate css class for layer link
 */
function cute_slider_generate_layer_link_css($link) {
  $output = array();

  if ($link['color'] != '') {
    if ($link['color'] == '0')
      $output[] = "color: #000 !important;\n";
    else
      $output[] = "color: #{$link['color']} !important;\n";
  }

  if ($link['background'] != '') {
    if ($link['background'] == '0')
      $output[] = "background-color: #000;\n";
    else
      $output[] = "background-color: #{$link['background']};\n";
  }

  if ($link['transparent'] != '' && is_numeric($link['transparent'])) {
    $opacity = $link['transparent']/100;
    $output[] = "opacity: {$opacity};\n-ms-filter:\"progid:DXImageTransform.Microsoft.Alpha(Opacity={$link['transparent']})\";\nfilter: alpha(opacity={$link['transparent']});\n";
  }

  if ($link['border'] != '') {
    if ($link['border'] == '0')
      $output[] = "border-color: #000;\n";
    else
      $output[] = "border-color: #{$link['border']};\n";
  }

  if (count($output))
    return "{\n" . implode('', $output) . "}";
  else
    return "";
}

/**
 * Callback for check machine name
 */
function cute_slider_check_machine_name($name) {
  $results = CuteSlider::get_by_machine_name($name);
  return count($results);
}
