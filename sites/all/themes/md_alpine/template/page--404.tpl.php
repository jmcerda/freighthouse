<?php global $base_url;?>
<!-- Intro loader -->
<?php if(theme_get_setting('enable_preloader') == 1) :?>
    <div class="mask">
        <div id="intro-loader"></div>
    </div>
<?php endif;?>
<!-- Intro loader -->

<!-- Home Section -->
<section id="home" class="intro-pattern nf-pattern">
    <div class="text-home">
        <div class="intro-item">
            <div class="section-title text-center">
                <h1><?php print t(theme_get_setting('nf_text'));?></h1>
                <p class="lead">
                    <?php print t(theme_get_setting('nf_des'));?>
                </p>
            </div>
            <div class="mybutton ultra">
                <a class="start-button" href="<?php print $base_url;?>"> <span data-hover="Back to home"><?php print t('Back to home');?></span> </a>
            </div>
        </div>
    </div>
</section>
<!-- Home Section -->