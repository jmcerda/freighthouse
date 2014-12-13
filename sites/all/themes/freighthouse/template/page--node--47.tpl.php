<div id="page-wrapper">
    <div id="page">
        <?php if($page['navigation'] && $node->nid != '47'):?>
         <?php       print render($page['navigation']);?>
        <?php endif;?>
        <div class="section-title text-center">
                <h1><?php print drupal_get_title();?></h1>
        </div>
        <section class="section-content">
            <div class="container">
                <div class="row fh_form_item col-md-12">
                        <div>
                            <?php print $messages; ?>
                            <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                        </div>
                    <?php if($content_wrapper_classes != null) :?>
                        <div class="<?php print $content_wrapper_classes;?>">
                    <?php endif;?>
                            <?php print render($page['content']);?>
                    <?php if($content_wrapper_classes != null) :?>
                        </div>
                    <?php endif;?>
                </div>
            </div>
        </section>
        <!-- Back to top -->
        <a href="#" id="back-top"><i class="fontello icon-angle-up icon-2x"></i></a>
    </div>
</div>
