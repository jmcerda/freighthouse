<?php
/**
 * @file cute_slide_content.tpl.php.
 * @author: Duynv
 * Date: 4/8/13
 */
?>
<?php if ($type == "info"):?>
  <div data-type="info" data-align="<?php print $elements['align'];?>" class="<?php print $elements['classes'];?>">
    <?php if ($elements['title'] != ""):?><h3><?php print $elements['title'];?></h3><?php endif;?>
    <?php if ($elements['text'] != ""):?><div><?php print $elements['text'];?></div><?php endif;?>
    <?php if ($elements['button_link'] != ""):?><div class="br-button"><a href="<?php print $elements['button_link'];?>" target="<?php print $elements['button_target'];?>"><?php print $elements['button_text'];?></a></div><?php endif;?>
  </div>
<?php elseif ($type == "captions"):?>
  <ul data-type="captions">
    <?php foreach ($elements as $index => $caption):?>
    <li class="<?php print $caption->class;?>" data-effect="<?php print $caption->effect;?>" data-delay="<?php print $caption->delay;?>">
      <?php print $caption->content;?>
    </li>
    <?php endforeach;?>
  </ul>
<?php elseif ($type == "video"):?>
  <a data-type="video" href="<?php print $elements['video_link'];?>"></a>
<?php elseif ($type == "link"):?>
<a data-type="link" href="<?php print $elements['link'];?>" target="<?php print $elements['link_target'];?>"></a>
<?php endif;?>