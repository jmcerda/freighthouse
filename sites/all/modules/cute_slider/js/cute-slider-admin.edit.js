/*------------------------------------------------------------------------
# MD Slider - March 18, 2013
# ------------------------------------------------------------------------
# Websites:  http://www.megadrupal.com -  Email: info@megadrupal.com
--------------------------------------------------------------------------*/
(function($) {
    Drupal.behaviors.edit_cute_slider = {
        attach: function(context, settings) {
            var mdSliderPanel = new MdSliderPanel();
            mdSliderPanel.init();
            $('#cute-slider-edit-form', context).submit(function() {
                $("#edit-slider-data-save", context).val($.objectToString(mdSliderPanel.getSliderData()));
            });
        }
    }
})(jQuery);
