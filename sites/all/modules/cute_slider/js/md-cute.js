/**
 * @file
 * @author Neo
 * Date: 4/9/13
 */
 
(function($){
    $.mdCuteResponsive = function(el){};
    
    $.mdCuteResponsive.defaultOptions = {};
    
    $.fn.mdCuteResponsive = function(){
        return this.each(function(){
						id = '#' + $(this).attr('id');
						changeFontSize(id);
						$(window).resize(function(){
							changeFontSize(id)
						});
						if($(id + '-wrapper .br-fullscreen-btn').length) {
							$(id + '-wrapper .br-fullscreen-btn').click(function(){
								changeFontSize(id)
							})
						}
        });
				
				function changeFontSize(id) {
					if ($(id).data('width') > $(id).width()) {
						ratio = (($(id).width() / $(id).data('width')) * 100) - 2;
						$(id + ' .br-captions').css({'font-size': ratio + '%'});
					} else {
						$(id + ' .br-captions').css('font-size','inherit');
					}
				}
    };
    
})(jQuery);

(function($){
    $.mdCuteThumbList = function(el, options){};
    
    $.mdCuteThumbList.defaultOptions = {};
    
    $.fn.mdCuteThumbList = function(options){
        return this.each(function(){
						id = '#' + $(this).attr('id');
						if ($(this).hasClass('thumblist-horizontal')) {
							thumblist_content = 0;
							$(id + '-wrapper .br-list-thumb').each(function(){
								thumblist_content += $(this).outerWidth();
							});
							$(id + '-wrapper .br-thumblist-content').width(thumblist_content);
						}
        });
    };
    
})(jQuery);

(function($){
    $.mdCuteGalleryThumb = function(el, options){};
    
    $.mdCuteGalleryThumb.defaultOptions = {};
    
    $.fn.mdCuteGalleryThumb = function(options){
        return this.each(function(){
						id = '#' + $(this).attr('id');
						thumblist_content = 0;
						$(id + '-wrapper .br-bottom .br-list-thumb').each(function(){
							thumblist_content += $(this).outerWidth();
						});
						$(id + '-wrapper .br-bottom .br-thumblist-content').width(thumblist_content);
        });
    };
    
})(jQuery);