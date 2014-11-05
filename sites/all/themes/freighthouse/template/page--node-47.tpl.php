<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
<div class="container">
  <div class="row">
    <div class="col-lg-12">
      <?php print render($page['content']); ?>
      <?php $block = module_invoke('webform', 'block_view', 'request-proposal');
print render($block['content']);?>
<?php echo "custom contetn";?>
    </div>
  </div>
</div>
