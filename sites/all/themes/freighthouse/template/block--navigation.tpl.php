<?php
global $base_url;
if(theme_get_setting('logo_normal_path')) {
    $logo_path = md_alpine_theme_setting_check_path(theme_get_setting('logo_normal_path'));
} else {
    $logo_path = $base_url.'/'.drupal_get_path('theme','md_alpine').'/img/logo.png';
}
 $logo_path = $base_url.'/'.drupal_get_path('theme','freighthouse').'/images/fh_logo100.png';
?>
<div id="navigation" class="navbar navbar-default navbar-fixed-top" role="navigation">
    <div class="navbar-inner">
        <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                <span class="sr-only">Toggle navigation</span>
                <i class="icon fontello icon-menu icon-2x"></i>
            </button>
            <a id="brand" class="navbar-brand item_left mobile-hide" href="<?php print $base_url;?>"> <img width="40px" height="40px" src="<?php print $logo_path;?>" alt="Freighthouse"/> </a>
            <div class="mybutton small cta item_fade_in">
                <a class="start-button colorbox-node cta_button" href="get-help"><span data-hover="Do Work">New Project</span></a>
            </div>
            <div class="mybutton small cta item_fade_in">
                <a class="start-button colorbox-node cta_button" href="project-proposal"><span data-hover="Get Help">Get Support</span></a>
            </div>
        </div>
        <div class="navbar-collapse collapse">
            <?php print $content;?>
        </div>
    </div>
</div>
