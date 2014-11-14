 //john uncommented to make li element active on specific part of frontpage
 var basePath = Drupal.settings.basePath;
  
 if($("body").hasClass("front")) {
	$("ul.navbar-nav li").each(function(){
		var link = $(this).find("a");
		link.removeClass("active");
		var href = link.attr('href');
		if(href.search("#") != -1) {
		var newHref = href.replace(basePath,'');
		link.attr('href',newHref);
		}
	})
 }
 
 //end uncomment
