// $Id$

(function ($) {

  Drupal.behaviors.exampleModule = {
    attach: function(context, settings) {
      $('.togglebtn', context).click(function () {
        $(this).parent().find('.toggle').toggle();
      });
    }
  };

})(jQuery);