<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php
    $multimedia = $row->field_field_multimedia;
    $icon_type = '';
    $portfolio_type = '';
    if(isset($multimedia) && count($multimedia) > 1 ) {
        $icon_type = $icon_type = '<i class="fontello icon-layers4 icon-4x"></i>';
        $portfolio_type  = t('Dev | Architecture | Creative | Marcomm');
    } else {
        if(isset($multimedia[0])) {
            $file_type = $multimedia[0]['rendered']['#file']->type;
            if($file_type == 'video') {
                $icon_type = '<i class="fontello icon-camera42 icon-4x"></i>';
                $portfolio_type  = t('Video | Motion | Animation');
            }
            if($file_type == 'audio') {
                $icon_type = '<i class="fontello icon-headset3 icon-4x"></i>';
                $portfolio_type  = t('Audio Production');
            }
            if($file_type == 'image') {
                $icon_type = '<i class="fontello icon-brush icon-4x"></i>';
                $portfolio_type  = t('Graphic Design | Illustration');
            }
            // if($file_type == 'image') {
            //     $icon_type = '<i class="fontello icon-code8 icon-4x"></i>';
            //     $portfolio_type  = t('Development | Architecture');
            // }
            // if($file_type == 'image') {
            //     $icon_type = '<i class="fontello icon-statistics icon-4x"></i>';
            //     $portfolio_type  = t('Marcom');
            // }
            }
        else {
            if(is_null(@$multimedia[0])) {
                $icon_type = '<i class="fontello icon-code8 icon-4x"></i>';
                $portfolio_type  = t('Development | Architecture');
            }
    }
}
?>
<!-- portfolio item -->
<div class="portfolio-item <?php foreach($row->field_field_po_taxonomy as $key => $value): print 'tid-'.$value['raw']['tid'].' ';endforeach;?>">
    <div class="portfolio">
        <!-- <a href="#!?q=ajax_portfolio&nid= -->
        <a href="node/<?php print $row->nid;?>&iframe=true" data-nid="<?php print $row->nid;?>" class="zoom colorbox-node"> <?php if(isset($fields['field_po_thumbnail']) && !empty($row->field_field_po_thumbnail)):?><img class="lazy" src="<?php print image_style_url('portfolio_thumbnails',$row->field_field_po_thumbnail[0]['rendered']['#item']['uri']);?>" alt="Freighthouse"/><?php endif;?>
            <div class="hover-items">
                <span> <?php if($icon_type): print $icon_type; endif;?> <em class="lead"><?php print $fields['title']->content;?></em> <em><?php if($portfolio_type): print $portfolio_type; endif;?></em> </span>
            </div>
        </a>
    </div>
    <?php
    unset($fields['field_multimedia']);
    unset($fields['field_po_taxonomy']);
    unset($fields['field_po_layout_mode']);
    unset($fields['field_po_author_name']);
    unset($fields['field_po_author_company']);
    unset($fields['field_po_thumbnail']);
    unset($fields['field_po_description']);
    unset($fields['field_po_button_text']);
    unset($fields['field_po_button_link']);
    unset($fields['title']);
    unset($fields['body']);
    ?>
    <?php foreach ($fields as $id => $field): ?>
        <?php if (!empty($field->separator)): ?>
            <?php print $field->separator; ?>
        <?php endif; ?>

        <?php print $field->wrapper_prefix; ?>
        <?php print $field->label_html; ?>
        <?php print $field->content; ?>
        <?php print $field->wrapper_suffix; ?>
    <?php endforeach; ?>
</div>
<!-- portfolio item -->
