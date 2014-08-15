<?php
  /**
   * @file cute_transition_library.tpl.php.
   * @author: Duynv
   * Date: 4/5/13
   */
?>
<!DOCTYPE html>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
  <title>Cute Slider</title>
  <link rel="stylesheet" href="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute_transition_library/css/cute-transitionlib-style.css');?>" type="text/css" media="screen" title="no title" charset="utf-8"/>
  <link rel="stylesheet" href="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute_transition_library/css/cute-transitionlib-slider-style.css');?>" type="text/css" media="screen" title="no title" charset="utf-8"/>
  <script type="text/javascript">
    var cuteSliderPath = "<?php print drupal_get_path('module', 'cute_slider');?>";
  </script>
  <script type="text/javascript" src="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/modernizr.js');?>"></script>
  <script type="text/javascript" src="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute_transition_library/cute.slider.js');?>"></script>
  <script type="text/javascript" src="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute/cute.transitions.all.js');?>"></script>
  <style>
    body {
      -webkit-transform: translate3d(0, 0, 0);
      -webkit-perspective: 1000px;
    }
    #slider {
      width: 354px;
      height: 194px;
      position: relative;
    }
  </style>
</head>
<body>
<div id="slider-wrapper">
<div id="slider" data-width="290" data-height="150" data-vpwidth="354" data-vpheight="194" data-force="canvas">
  <ul data-type="slides">
    <li id='slide1' data-delay="0.5">
      <img src="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute_transition_library/images/1.png');?>"/>
    </li>
    <li id='slide2' data-delay="0.5">
      <img src="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute_transition_library/cute-theme/blank.jpg');?>" data-src="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute_transition_library/images/2.png');?>"/>
    </li>
    <li id='slide3' data-delay="0.5">
      <img src="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute_transition_library/cute-theme/blank.jpg');?>" data-src="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute_transition_library/images/3.png');?>"/>
    </li>
    <li id='slide4' data-delay="0.5">
      <img src="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute_transition_library/cute-theme/blank.jpg');?>" data-src="<?php print file_create_url(drupal_get_path('module', 'cute_slider') . '/js/cute_transition_library/images/4.png');?>"/>
    </li>
  </ul>
  <ul data-type="controls">
  </ul>
  <div class="br-shadow"></div>
</div>
</div>
<div class="loading"></div>
<script>
  var slider = document.getElementById('slider');
  <?php if (strtolower($parameters['direction']) == '2d') print "slider.setAttribute('data-force', '2d');";?>

  for (var i = 1; i <= 4; ++i) {
    document.getElementById('slide' + i).setAttribute('data-trans3d', 'tr<?php print $parameters['transition_id'];?>');
    document.getElementById('slide' + i).setAttribute('data-trans2d', 'tr<?php print $parameters['transition_id'];?>');
  }

  var br = new Cute.Slider();
  br.setup("slider");
</script>
</body>
</html>
