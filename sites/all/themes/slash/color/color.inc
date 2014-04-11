<?php

$info = array(

  // Available colors and color labels used in theme.
  'fields' => array(
    'color1' => t('Main Links and Regions'),
	'color2' => t('Closure Back'),
	'color3' => t('Footer Back'),
	'color4' => t('Body Back'),
	'color5' => t('InterContent Region'),
  ),
  // Pre-defined color schemes.
  'schemes' => array(
    'default' => array(
      'title' => t('Slash Corporate (Blue Base)'),
      'colors' => array(
        'color1' => '#0088cc', 
		'color2' => '#000000',   
		'color3' => '#333333', 
		'color4' => '#ffffff',   
		'color5' => '#eeeeee',       
      ),
    ),
		
  ),


  // Images to copy over.
  'copy' => array( 
	'logo.png',
  ),

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => array(
    'color/color.css',
  ),

  // Gradient definitions.
  'gradients' => array(
  ),

  // Color areas to fill (x, y, width, height).
  'fill' => array(
  ),

  // Coordinates of all the theme slices (x, y, width, height)
  // with their filename as used in the stylesheet.
  'slices' => array(  
  ),

  // Reference color used for blending. Matches the base.png's colors.
  'blend_target' => '#ffffff',

  // Preview files.
  'preview_image' => 'color/preview.png',
  'preview_css' => 'color/preview.css',
  'preview_js' => 'color/preview.js',
  'preview_html' => 'color/preview.html',
  
  'base_image' => 'color/preview.png',
);
