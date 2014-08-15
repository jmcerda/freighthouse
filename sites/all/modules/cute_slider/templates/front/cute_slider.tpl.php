<?php
/**
 * @file cute_slider.tpl.php.
 * @author: Duynv
 * Date: 4/8/13
 */
?>
<div id="cute-slider-<?php print $slider->slid;?>-wrapper" class="<?php print $template;?> cute-slider-<?php print $slider->slid;?>-wrapper">
  <div id="cute-slider-<?php print $slider->slid;?>" class="<?php print $slider_classes;?>" data-width="<?php print $width;?>" data-height="<?php print $height;?>" data-overpause="<?php print $hover_pause;?>">
    <?php if (count($slides)):?>
      <ul data-type="slides">
        <?php foreach ($slides as $key => $slide):?>
          <?php if ($key == 0):?>
          <li data-delay="<?php print ((int)$slide->settings['timelinewidth'])/10;?>" data-trans3d="<?php print $slide->settings['trs3d'];?>" data-trans2d="<?php print $slide->settings['trs2d'];?>">
            <img src="<?php print $slide->settings['backgroundimage'];?>" data-src="<?php print $slide->settings['backgroundimage'];?>" data-thumb="<?php print $slide->settings['thumbnail'];?>" />
            <?php print $slide->content;?>
          </li>
          <?php else:?>
          <li data-delay="<?php print ((int)$slide->settings['timelinewidth'])/10;?>" data-trans3d="<?php print $slide->settings['trs3d'];?>" data-trans2d="<?php print $slide->settings['trs2d'];?>">
            <img src="" data-src="<?php print $slide->settings['backgroundimage'];?>" data-thumb="<?php print $slide->settings['thumbnail'];?>" />
            <?php print $slide->content;?>
          </li>
          <?php endif;?>
        <?php endforeach;?>
      </ul>
        <ul data-type="controls">
          <?php print $controls;?>
        </ul>
    <?php endif;?>
  </div>
  <?php if ($slider->settings['enable_shadow'] && !$slider->settings['gallery_mode']):?>
  <div class="cute-shadow"><img src="<?php print $shadow_image;?>" alt="shadow"></div>
  <?php endif;?>
</div>