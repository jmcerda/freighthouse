<?php

/**
 * @file media_ted/includes/media_ted.styles.inc
 * Styles definitions for Media: Ted.
 */

/**
 * Implementation of Styles module hook_styles_register().
 */
function media_ted_styles_register() {
  return array(
    'MediaTedStyles' => array(
      'field_types' => 'file',
      'name' => t('MediaTed'),
      'description' => t('Media Ted styles.'),
      'path' => drupal_get_path('module', 'media_ted') .'/includes',
      'file' => 'media_ted.styles.inc',
    ),
  );
}

/**
 *  Implements hook_styles_containers(). (Deprecated in version 2)
 */
function media_ted_styles_containers() {
  return array(
    'file' => array(
      'containers' => array(
        'media_ted' => array(
          'label' => t('TED Styles'),
          'data' => array(
            'streams' => array(
              'ted',
            ),
            'mimetypes' => array(
              'video/ted',
            ),
          ),
          'weight' => 0,
          'filter callback' => 'media_ted_formatter_filter',
          'themes' => array(
            'field_formatter_styles' => 'media_ted_field_formatter_styles',
            'styles' => 'media_ted_styles',
            'preview' => 'media_ted_preview_style',
          ),
          'description' => t('TED Styles will display embedded TED videos and thumbnails to your choosing, such as by resizing, setting colors, and autoplay. You can !manage.', array('!manage' => l(t('manage your Ted styles here'), 'admin/config/media/media-ted-styles'))),
        ),
      ),
    ),
  );
}

function media_ted_formatter_filter($variables) {
  if (isset($variables['object'])) {
    $object = isset($variables['object']->file) ? $variables['object']->file : $variables['object'];
    return (file_uri_scheme($object->uri) == 'ted') && ($object->filemime == 'video/ted');
  }
}

/**
 * Implementation of the File Styles module's hook_file_styles_filter().
 */
function media_ted_file_styles_filter($object) {
  $file = isset($object->file) ? $object->file : $object;
  if ((file_uri_scheme($file->uri) == 'ted') && ($file->filemime == 'video/ted')) {
    return 'media_ted';
  }
}

/**
 *  Implements hook_styles_styles().
 */
function media_ted_styles_styles() {
  $styles = array(
    'file' => array(
      'containers' => array(
        'media_ted' => array(
          'styles' => array(
            'ted_thumbnail' => array(
              'name' => 'ted_thumbnail',
              'effects' => array(
                array('label' => t('Thumbnail'), 'name' => 'thumbnail', 'data' => array('thumbnail' => 1)),
                array('label' => t('Resize'), 'name' => 'resize', 'data' => array('width' => 100, 'height' => 75)),
              ),
            ),
            'ted_preview' => array(
              'name' => 'ted_preview',
              'effects' => array(
                array('label' => t('Autoplay'), 'name' => 'autoplay', 'data' => array('autoplay' => 0)),
                array('label' => t('Resize'), 'name' => 'resize', 'data' => array('width' => 220, 'height' => 165)),
              ),
            ),
            'ted_full' => array(
              'name' => 'ted_full',
              'effects' => array(
                array('label' => t('Autoplay'), 'name' => 'autoplay', 'data' => array('autoplay' => 0)),
                array('label' => t('Resize'), 'name' => 'resize', 'data' => array('width' => 640, 'height' => 480)),
                array('label' => t('Full screen'), 'name' => 'fullscreen', 'data' => array('fullscreen' => 1)),
              ),
            ),
          ),
        ),
      ),
    ),
  );

  // Allow any image style to be applied to the thumbnail.
  foreach (image_styles() as $style_name => $image_style) {
    $styles['file']['containers']['media_ted']['styles']['ted_thumbnail_' . $style_name] = array(
      'name' => 'ted_thumbnail_' . $style_name,
      'image_style' => $style_name,
      'effects' => array(
        array('label' => t('Thumbnail'), 'name' => 'thumbnail', 'data' => array('thumbnail' => 1)),
      ),
    );
  }

  return $styles;
}

/**
 *  Implements hook_styles_presets().
 */
function media_ted_styles_presets() {
  $presets = array(
    'file' => array(
      'square_thumbnail' => array(
        'media_ted' => array(
          'ted_thumbnail_square_thumbnail',
        ),
      ),
      'thumbnail' => array(
        'media_ted' => array(
          'ted_thumbnail',
        ),
      ),
      'small' => array(
        'media_ted' => array(
          'ted_preview',
        ),
      ),
      'large' => array(
        'media_ted' => array(
          'ted_full',
        ),
      ),
      'original' => array(
        'media_ted' => array(
          'ted_full',
        ),
      ),
    ),
  );
  return $presets;
}

/**
 * Implementation of Styles module hook_styles_default_containers().
 */
function media_ted_styles_default_containers() {
  // We append Ted to the file containers.
  return array(
    'file' => array(
      'containers' => array(
        'media_ted' => array(
          'class' => 'MediaTedStyles',
          'name' => 'media_ted',
          'label' => t('TED'),
          'preview' => 'media_ted_preview_style',
        ),
      ),
    ),
  );
}


/**
 * Implementation of Styles module hook_styles_default_presets().
 */
function media_ted_styles_default_presets() {
  $presets = array(
    'file' => array(
      'containers' => array(
        'media_ted' => array(
          'default preset' => 'unlinked_thumbnail',
          'styles' => array(
            'original' => array(
              'default preset' => 'video',
            ),
            'thumbnail' => array(
              'default preset' => 'linked_thumbnail',
            ),
            'square_thumbnail' => array(
              'default preset' => 'linked_square_thumbnail',
            ),
            'large' => array(
              'default preset' => 'large_video',
            ),
          ),
          'presets' => array(
            'video' => array(
              array(
                'name' => 'video',
                'settings' => array(),
              ),
            ),
            'large_video' => array(
              array(
                'name' => 'resize',
                'settings' => array(
                  'width' => 640,
                  'height' => 390,
                ),
              ),
              array(
                'name' => 'video',
                'settings' => array(),
              ),
            ),
          ),
        ),
      ),
    ),
  );
  // Allow any image style to be applied to the thumbnail.
  foreach (image_styles() as $style_name => $image_style) {
    $presets['file']['containers']['media_ted']['presets']['linked_' . $style_name] = array(
      array(
        'name' => 'linkToMedia',
        'settings' => array(),
      ),
      array(
        'name' => 'imageStyle',
        'settings' => array(
          'image_style' => $style_name,
        ),
      ),
      array(
        'name' => 'thumbnail',
        'settings' => array(),
      ),
    );
    $presets['file']['containers']['media_ted']['presets']['unlinked_' . $style_name] = $presets['file']['containers']['media_ted']['presets']['linked_' . $style_name];
    array_shift($presets['file']['containers']['media_ted']['presets']['unlinked_' . $style_name]);
    foreach ($image_style['effects'] as $effect) {
      if (in_array($effect['name'], array('image_scale', 'image_scale_and_crop', 'image_resize', 'image_crop'))) {
        $presets['file']['containers']['media_ted']['presets']['video_' . $style_name] = array(
          array(
            'name' => 'resize',
            'settings' => $effect['data'],
          ),
          array(
            'name' => 'video',
            'settings' => array(),
          ),
        );
      }
    }
  }
  return $presets;
}
