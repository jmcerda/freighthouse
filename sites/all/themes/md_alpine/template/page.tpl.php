<div id="page-wrapper">
    <div id="page">
        <?php if($page['navigation']):?>
            <?php print render($page['navigation']);?>
        <?php endif;?>
        <section class="section-content blog-content">
            <!-- Section title -->
            <div class="section-title text-center">
                <h1><?php print drupal_get_title();?></h1>
            </div>
            <!-- Section title -->
            <?php if(empty($page['spb_enabled']) || $page['spb_enabled'] == FALSE):?>
                <div class="container">
            <?php endif;?>
                <div class="row">
                    <?php if (!empty($messages) || !empty($tabs['#primary']) || !empty($tabs['#secondary'])): ?>
                        <div class="col-md-12">
                            <?php print $messages; ?>
                            <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                        </div>
                    <?php endif;?>
                    <div class="<?php print $content_wrapper_classes;?>">
                        <?php print render($page['content']);?>
                    </div>
                    <?php if($page['sidebar']):?>
                        <div class="<?php print $sidebar_wrapper_classes;?>">
                            <?php print render($page['sidebar']);?>
                        </div>
                    <?php endif;?>
                </div>
            <?php if(empty($page['spb_enabled']) || $page['spb_enabled'] == FALSE):?>
                </div>
            <?php endif;?>
        </section>
        <?php if($page['footer']):?>
            <?php print render($page['footer']);?>
        <?php endif;?>
        <!-- Back to top -->
        <a href="#" id="back-top"><i class="fontello icon-angle-up icon-2x"></i></a>
    </div>
</div>
