<?php

/**
 * @file
 * Customize the display of a complete webform.
 *
 * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
 * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
 * all webforms on your site.
 *
 * Available variables:
 * - $form: The complete form array.
 * - $nid: The node ID of the Webform.
 *
 * The $form array contains two main pieces:
 * - $form['submitted']: The main content of the user-created form.
 * - $form['details']: Internal information stored by Webform.
 *
 * If a preview is enabled, these keys will be available on the preview page:
 * - $form['preview_message']: The preview message renderable.
 * - $form['preview']: A renderable representing the entire submission preview.
 */
?>

<div id="page-wrapper">
    <div id="page">
        <div class="section-title text-center">
            <h1><?php print drupal_get_title();?></h1>
        </div>
        <section class="section-content">
            <div class="container">
                <div class="row col-lg-12">
                    <div>
                        <?php print $messages; ?>
                        <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                    </div>
                    <?php if($content_wrapper_classes != null) :?>
                        <div class="<?php print $content_wrapper_classes;?>">
                    <?php endif;?>
                            <?php print drupal_render($form['submitted']);
                                  print drupal_render_children($form);?>
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
