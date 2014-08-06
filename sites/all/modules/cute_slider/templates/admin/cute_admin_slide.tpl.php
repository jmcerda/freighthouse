<?php
/**
 * @file cute_admin_slide.tpl.php.
 * @author: Duynv
 * Date: 4/6/13
 */
?>
<div id="tabs-<?php print $slide->position+1;?>" class="md-tabcontent clearfix" data-timelinewidth="<?php print $slide->settings['timelinewidth'];?>">
  <div class="settings">
    <a href="#" class="panel-settings-link">[Setting]</a> &nbsp;
    <a class="panel-clone" href="#">[Clone slide]</a>
    <input type="hidden" autocomplete="off" class="panelsettings" value='<?php print $slide_settings;?>' />
  </div>
  <div class="md-slidewrap" style="height: <?php print $height;?>px; width: <?php print $width;?>px;">
    <div class="md-slide-image"><img src="<?php print $background_url;?>" /></div>
    <div class="md-objects" style="width: <?php print $width;?>px; height: <?php print $height;?>px;">
      <?php foreach ($slide->layers as $layer) { print theme('cute_slider_admin_layer', array('layer' => $layer));}?>
    </div>
  </div>
</div>