<!DOCTYPE html>
<html xmlns="//www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"
    <?php print $rdf_namespaces; ?>>

<head profile="<?php print $grddl_profile;?>">
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <?php
        print $styles;
        global $base_url;
    ?>
    <style type="text/css">
        <?php if (isset($googlewebfonts)): print $googlewebfonts; endif; ?>
        <?php if (isset($theme_setting_css)): print $theme_setting_css; endif; ?>
        <?php
        // custom typography
        if (isset($typography)): print $typography; endif;
        ?>
        <?php if (isset($custom_css)): print $custom_css; endif; ?>
    </style>
    <?php if (isset($header_code)): print $header_code; endif;?>
</head>
<body data-spy="scroll" data-target=".navbar" data-offset="75" class="blog-page <?php print $classes; ?>" <?php print $attributes;?> >
<?php print $page_top; ?>
<?php print $page; ?>
<?php print $scripts; ?>
<?php
    print $page_bottom;
    if (isset($footer_code)): print $footer_code; endif;
    ?>
</body>

</html>
