<div id="page-wrapper">
    <div id="page">
        <?php if($page['navigation'] && $node->nid != '47'):?>
            <?php print render($page['navigation']);?>
        <?php endif;?>
        <section class="section-content blog-content">
            <?php if($page['spb_enabled'] == FALSE):?>
            <div class="container">
            <?php endif;?>
                <!-- Section title -->
                <?php if(isset($node) && !empty($node->title)):?>
                <div class="section-title text-center">
                    <div>
                        <span class="line big"></span>
                        <span><?php print t('Posted by');?> <a href="<?php print base_url().'/user/'.$node->uid;?>"><?php print $node->name;?></a></span>
                        <span class="line big"></span>
                    </div>
                    <h1 class="item_left"><?php print $node->title;?></h1>
                    <div>
                        <span class="line"></span>
                        <span><i class="fontello icon-calendar"></i><?php print date('d F Y',$node->created);?></span>
                        <span class="line"></span>
                    </div>
                    <?php if(isset($node->field_bl_description)):?>
                        <p class="lead">
                            <?php print $node->field_bl_description[$node->language][0]['value'];?>
                        </p>
                    <?php endif;?>
                </div>
                <?php endif; ?>
                <!-- Section title -->
                <?php if(!$page['spb_enabled'] || $page['spb_enabled'] == FALSE):?>
                <div class="row">
                <?php endif;?>
                    <?php if (!empty($messages) || !empty($tabs['#primary']) || !empty($tabs['#secondary'])): ?>
                        <div class="col-md-12">
                            <?php print $messages; ?>
                            <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                        </div>
                    <?php endif;?>
                    <?php if($content_wrapper_classes != null) :?>
                        <div class="<?php print $content_wrapper_classes;?>">
                    <?php endif;?>
                            <?php print render($page['content']);?>
                    <?php if($content_wrapper_classes != null) :?>
                        </div>
                    <?php endif;?>
                    <?php if($page['sidebar']):?>
                        <div class="<?php print $sidebar_wrapper_classes;?>">
                            <?php print render($page['sidebar']);?>
                        </div>
                    <?php endif;?>
                <?php if(!$page['spb_enabled'] || $page['spb_enabled'] == FALSE):?>
                </div>
                <?php endif;?>

                <?php if($page['spb_enabled'] == FALSE):?>
                    <div class="row">
                        <div class="col-md-12">
                            <div class="element-line">
                                <div class="pager">
                                    <?php if(isset($previous_link)):?>
                                    <div class="puls previous">
                                        <a href="<?php print $previous_link;?>">&larr; <?php print t('Older');?></a>
                                    </div>
                                    <?php endif;?>
                                    <?php if(isset($next_link)):?>
                                    <div class="puls next">
                                        <a href="<?php print $next_link;?>"><?php print t('Newer');?> &rarr;</a>
                                    </div>
                                    <?php endif;?>
                                </div>
                            </div>
                        </div>
                    </div>
                <?php endif;?>
            <?php if($page['spb_enabled'] == FALSE):?>
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
