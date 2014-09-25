<?php
global $base_url;
if(isset($content['field_bl_multimedia'])) {
    $multimedia = $content['field_bl_multimedia']['#items'];
    $media_content = '';
    foreach($multimedia as $key => $value){
        $file_type = $value['file']->type;
        $file_uri = $value['file']->uri;
        if($file_type == 'image') {
            if(count($multimedia) > 1 ) {
                $media_content .= '<li>';
            }
            $media_content .= '<img src="'.image_style_url('blog_multimedia',$file_uri).'"/>';
            if(count($multimedia) > 1 ) {
                $media_content .= '</li>';
            }
        } else {
            if(count($multimedia) > 1 ) {
                $media_content .= '<li>';
            }
            $media_content .= render($content['field_bl_multimedia'][$key]);
            if(count($multimedia) > 1 ) {
                $media_content .= '</li>';
            }
        }
    }
}
?>
<?php if(strpos(current_path(),'taxonomy/term') !== FALSE):?>
<div class="col-md-10 col-md-offset-1">
    <div class="section-title text-center">
        <div>
            <span class="line"></span>
            <span><i class="fontello icon-calendar"></i><?php print date('d F Y',$node->created);?></span>
            <span class="line"></span>
        </div>
        <h1><?php print $node->title;?></h1>
        <div>
            <span class="line big"></span>
            <span><?php print t('By');?> <a href="<?php print url('/user/'.$node->uid);?>"><?php print $node->name;?></a></span>
            <span class="line big"></span>
        </div>
    </div>
<?php endif;?>

<div class="element-line">
    <?php if(isset($multimedia) && count($multimedia) > 1) :?>
    <div class="flexslider">
            <ul class="slides">
        <?php endif;?>
            <?php if(isset($media_content) && $media_content != null): print $media_content; endif;?>
        <?php if(isset($multimedia) && count($multimedia) > 1) :?>
            </ul>
    </div>
    <?php endif;?>
    <div class="blog-text">
        <?php print render($content['body']);?>
    </div>
    <?php print render($content['comments']); ?>
</div>

<?php if(strpos(current_path(),'taxonomy/term') !== FALSE):?>
</div>
<?php endif;?>
