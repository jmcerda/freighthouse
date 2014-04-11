
(function ($) {
  Drupal.color = {
    callback: function(context, settings, form, farb, height, width) {
	
      // This is where Live Preview Updates must be made. using jQuery selectors, change the properties values.
      $('#preview-color-1', form).css('backgroundColor', $('#palette input[name="palette[color1]"]', form).val());
	  $('#preview-color-2', form).css('backgroundColor', $('#palette input[name="palette[color2]"]', form).val());
	  $('#preview-color-3', form).css('backgroundColor', $('#palette input[name="palette[color3]"]', form).val());
	  $('#preview-color-4', form).css('backgroundColor', $('#palette input[name="palette[color4]"]', form).val());
	  $('#preview-color-5', form).css('backgroundColor', $('#palette input[name="palette[color5]"]', form).val());	  
    }
  };
})(jQuery);
