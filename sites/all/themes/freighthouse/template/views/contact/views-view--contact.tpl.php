<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<?php if(isset( $view->result[0])) : $view_result = $view->result[0];?>
<div class="section-title text-center">
    <?php if(isset($view_result)) : print $view_result->node_title; endif;?>
    <br>
</div>
<?php endif;?>

<!-- clock time zone -->
<div class="container">
 <div class="section-title text-center">
  <div class="item_fade_in" style="opacity: 1; right: 0px;">
    <div class="col-md-2 col-sm-2 col-xs-12 timeclock">
    	<canvas id="timezone_NYC" class="CoolClock:swissRail:80::-4"></canvas>
        <span>NYC</span>
    </div>
    <div class="col-md-2 col-sm-2 col-xs-12 timeclock">
    	<canvas id="timezone_MEX" class="CoolClock:swissRail:80::-6"></canvas>
        <span>MEX</span>
    </div>
    <div class="col-md-2 col-sm-2 col-xs-12 timeclock">
    	<canvas id="timezone_RU" class="CoolClock:swissRail:80::+7"></canvas>
        <span>RU</span>
    </div>
    <div class="col-md-2 col-sm-2 col-xs-12 timeclock">
    	<canvas id="timezone_AMS" class="CoolClock:swissRail:80::+1"></canvas>
        <span>AMS</span>
    </div>
    <div class="col-md-2 col-sm-2 col-xs-12 timeclock">
    	<canvas id="timezone_MNL" class="CoolClock:swissRail:80::+8 timeclock"></canvas>
        <span>MNL</span>
    </div>
    <div class="col-md-2 col-sm-2 col-xs-12 timeclock">
    	<canvas id="timezone_IND" class="CoolClock:swissRail:80::+5 timeclock"></canvas>
        <span>IND</span>
    </div>
   </div>
  </div>
</div>
        

<!-- Google maps print -->
<?php if(theme_get_setting('enable_map') == 1) :?>
    <div id="map_canvas" class="element-line"></div>
<?php endif;?>

<div class="<?php print $classes; ?>">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
        <?php print $title; ?>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($header): ?>
        <div class="view-header">
            <?php print $header; ?>
        </div>
    <?php endif; ?>

    <?php if ($exposed): ?>
        <div class="view-filters">
            <?php print $exposed; ?>
        </div>
    <?php endif; ?>

    <?php if ($attachment_before): ?>
        <div class="attachment attachment-before">
            <?php print $attachment_before; ?>
        </div>
    <?php endif; ?>

    <!-- Google maps print -->
    <?php if ($rows): ?>
        <div class="container">
            <div class="element-line">
                <?php if(isset($view_result)):?>
                    <div class="lead text-center">
                        <?php if(isset($view_result->field_field_contact_description[0])):print t($view_result->field_field_contact_description[0]['rendered']['#markup']);endif;?>
                    </div>
                <?php endif;?>
                <div class="row">
                    <?php print $rows; ?>
                </div>
            </div>
        </div>
    <?php elseif ($empty): ?>
        <div class="view-empty">
            <?php print $empty; ?>
        </div>
    <?php endif; ?>

    <?php if ($pager): ?>
        <?php print $pager; ?>
    <?php endif; ?>

    <?php if ($attachment_after): ?>
        <div class="attachment attachment-after">
            <?php print $attachment_after; ?>
        </div>
    <?php endif; ?>

    <?php if ($more): ?>
        <?php print $more; ?>
    <?php endif; ?>

    <?php if ($footer): ?>
        <div class="view-footer">
            <?php print $footer; ?>
        </div>
    <?php endif; ?>

    <?php if ($feed_icon): ?>
        <div class="feed-icon">
            <?php print $feed_icon; ?>
        </div>
    <?php endif; ?>

</div><?php /* class view */ ?>