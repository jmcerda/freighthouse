/**
 * User: duynguyen
 * Date: 4/1/13
 * Time: 4:55 PM
 * To change this template use File | Settings | File Templates.
 */
(function ($) {
    Drupal.behaviors.configure_cute_slider = {
        attach: function(context, settings) {
            $("#edit-responsive").change(function() {
                if ($(this).is(":checked")) {
                    $("#edit-responsive-width").show();
                }
                else {
                    $("#edit-responsive-width").hide();
                }
            }).trigger("change");
            $("#edit-show-slidecontrol").change(function() {
                if ($(this).is(":checked")) {
                    $(".form-item-thumbnail-align").show();
                }
                else {
                    $(".form-item-thumbnail-align").hide();
                }
            }).trigger("change");
            var first = true;
            $('#edit-thumbbar-direction').change(function() {
                var selected = $("#edit-thumbbar-direction :selected").val();
                var position_selected = $('#edit-thumbbar-position :selected').val();
                var positions = $('#edit-thumbbar-position').empty();
                if (selected == 'vertical') {
                    positions.append('<option value="left">Left</option><option value="right">Right</option>');
                }
                else {
                    positions.append('<option value="top">Top</option><option value="bottom">Bottom</option>');
                }
                if (first) {
                    $('#edit-thumbbar-position').val(position_selected);
                    first = false;
                }
            }).trigger('change');
            $('#edit-show-thumbnail-bar').change(function() {
                if ($(this).is(':checked')) {
                    $('#thumbbar-settings').show();
                }
                else {
                    $('#thumbbar-settings').hide();
                }
            }).trigger('change');
						// Gallery mode
						$("#edit-gallery-mode").change(function() {
                if ($(this).is(":checked")) {
                    $(".form-item-show-thumbnail-bar, #thumbbar-settings, .form-item-show-nextprev").hide();
                }
                else {
                    $(".form-item-show-thumbnail-bar, .form-item-show-nextprev").show();
										$(".form-item-show-thumbnail-bar").trigger("change");
                }
            }).trigger("change");
        }
    }
})(jQuery);