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

<!-- <?php if(isset( $view->result[0])) : $view_result = $view->result[0];?>
<div class="section-title text-center">
    <?php if(isset($view_result)) : print $view_result->node_title; endif;?>
    <br>
</div>
<?php endif;?> -->

<!-- clock time zone -->
<div class="parallax-content mobile-hide">
 <div class="row">
    <div class="five_cols col-lg-1 timeclock">
        <div class="item_fade_in" style="opacity: 1; right: 0px;">
            <canvas id="timezone_SFO" class="CoolClock:freightHouse:40::-8"></canvas>
            <div><h4>SFO</h4>
            <p>156 2nd Street 94105</p>
            </div>
        </div>
    </div>
    <div class="five_cols col-lg-1 timeclock">
        <div class="item_fade_in" style="opacity: 1; right: 0px;">
            <canvas id="timezone_MEX" class="CoolClock:freightHouse:40::-6"></canvas>
            <div><h4>MEX</h4></div>
        </div>
    </div>
    <div class="five_cols col-lg-1 timeclock">
        <div class="item_fade_in" style="opacity: 1; right: 0px;">
            <canvas id="timezone_NYC" class="CoolClock:freightHouse:40::-5"></canvas>
            <div><h4>NYC</h4>
            <p>175 Varick Street 10014</p>
            </div>
        </div>
    </div>
    <div class="five_cols col-lg-1 timeclock">
        <div class="item_fade_in" style="opacity: 1; right: 0px;">
            <canvas id="timezone_WAS" class="CoolClock:freightHouse:40::-5"></canvas>
            <div><h4>WAS</h4>
            <p>641 S Street NW 20001</p>
            </div>
        </div>
    </div>
    <div class="five_cols col-lg-1 timeclock">
        <div class="item_fade_in" style="opacity: 1; right: 0px;">
            <canvas id="timezone_MIA" class="CoolClock:freightHouse:40::-5"></canvas>
            <div><h4>MIA</h4>
            <p>350 Lincoln Road 33139</p>
            </div>
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
