<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
    <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->
  
  <!--[if lt IE 10]>
    <link rel="stylesheet" href="<?php print $directory; ?>/css/ie.css" />
  <![endif]-->
	  
      <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1.0, minimum-scale=1, user-scalable=no" />
	  
	  <!-- iOS Icons -->
	      <link rel="apple-touch-icon-precomposed" sizes="152x152" href="<?php print $directory; ?>/apple-touch-icon-152-precomposed.png">
	      <link rel="apple-touch-icon-precomposed" sizes="144x144" href="<?php print $directory; ?>/apple-touch-icon-144-precomposed.png">
	      <link rel="apple-touch-icon-precomposed" sizes="120x120" href="<?php print $directory; ?>/apple-touch-icon-120-precomposed.png">
	      <link rel="apple-touch-icon-precomposed" sizes="114x114" href="<?php print $directory; ?>/apple-touch-icon-114-precomposed.png">
	      <link rel="apple-touch-icon-precomposed" sizes="72x72" href="<?php print $directory; ?>/apple-touch-icon-72-precomposed.png">
	      <link rel="apple-touch-icon-precomposed" sizes="57x57" href="<?php print $directory; ?>/apple-touch-icon-57-precomposed.png">      
	  
		 <!--  <script src="../bootstrap/js/bootstrap.min.js"></script> -->

		      <script>
		        !function ($) {
		          $(function(){
		            // Fix for dropdowns on mobile devices
		            $('body').on('touchstart.dropdown', '.dropdown-menu', function (e) { 
		                e.stopPropagation(); 
		            });
		            $(document).on('click','.dropdown-menu a',function(){
		                document.location = $(this).attr('href');
		            });
		          })
		        }(window.jQuery)
		      </script>
	  
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
