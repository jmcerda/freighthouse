(function($){
//place all code  after this line



 //john uncommented to make li element active on specific part of frontpage
 var basePath = Drupal.settings.basePath;

 if($("body").hasClass("front")) {
	$("ul.navbar-nav li").each(function(){
		var link = $(this).find("a");
		link.removeClass("active");

		$(this).removeClass("active");
		console.log(link);

		var href = link.attr('href');
		if(href.search("#") != -1) {
			var newHref = href.replace(basePath,'');
			link.attr('href',newHref);
		}
	})
 }
 //end uncomment




//place all code  before this line
})(jQuery);
