<?php
/**
 * @file admin_layer.tpl.php
 * User: duynguyen
 * Date: 4/2/13
 * Time: 4:32 PM
 * To change this template use File | Settings | File Templates.
 */
?>
<?php if ($layer['type'] == 'text'):?>
<div class="slider-item ui-widget-content item-text ui-draggable ui-resizable" <?php print $data;?> style="<?php print $styles;?>">
  <p><?php print $layer['title'];?></p>
  <span class="sl-tl"></span><span class="sl-tr"></span><span class="sl-bl"></span><span class="sl-br"></span>
  <span class="sl-top"></span><span class="sl-right"></span><span class="sl-bottom"></span><span class="sl-left"></span>
</div>
<?php elseif ($layer['type'] == 'image'):?>
<div class="slider-item ui-widget-content item-image ui-draggable ui-resizable" <?php print $data;?> style="<?php print $styles;?>">
  <img width="100%" height="100%" src="<?php print $layer['file_url'];?>" />
  <span class="sl-tl"></span><span class="sl-tr"></span><span class="sl-bl"></span><span class="sl-br"></span>
  <span class="sl-top"></span><span class="sl-right"></span><span class="sl-bottom"></span><span class="sl-left"></span>
</div>
<?php elseif ($layer['type'] == 'video'):?>
<div class="slider-item ui-widget-content item-video ui-draggable ui-resizable" <?php print $data;?> style="<?php print $styles;?>">
  <img width="100%" height="100%" src="<?php print $layer['thumb'];?>" />
  <span class="sl-tl"></span><span class="sl-tr"></span><span class="sl-bl"></span><span class="sl-br"></span>
  <span class="sl-top"></span><span class="sl-right"></span><span class="sl-bottom"></span><span class="sl-left"></span>
</div>
<?php endif;?>
