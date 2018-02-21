<?php


/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
 
 // todo: fix admin title
function amazon_store_item_image_admin_title($subtype, $conf, $context) {
  return t("Product Image (@s) - @size", array('@s' => $context->identifier, '@size' => $conf['size_selection']));
}

class ItemImage extends Block {
  /**
   *  Sets title text on draggable block panel in Layout builder.
   */
  function getAdminTitle() {
    return !empty($this->settings['title']) ? check_plain($this->settings['title']) : t('Amazon Product Image');
  }

  /**
   *  Sets block subject on block view.
   */
  function getTitle() {
    return isset($this->settings['title']) ? check_plain($this->settings['title']) : '';
  }

  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      $amazon_object = $this->contexts['amazon_item']->data;
      $size = $this->settings['size_selection'];
      return theme('amazon_store_item_image', array('amazon_item' => $amazon_object, 'size' => $size));
    }
  }

  /**
   *  Builds the block's configuration form.
   */
  function form(&$form, &$form_state) {
    parent::form($form, $form_state);

    $conf = $form_state['conf'];

    $form['size_selection'] = array(
      '#title' => t("Product Image Size"),
      '#type' => 'select',
      '#description' => t("Which of the three Amazon Product Images would you like"),
      '#options' => array(
        'SmallImage' => t('Small'),
        'MediumImage' => t('Medium'),
        'LargeImage' => t('Large'),
      ),
      '#default_value' => !empty($this->settings['size_selection']) ? $this->settings['size_selection'] : 'MediumImage',
    );

  }

  /**
   * Submit handler to save the form settings.
   */
  function formSubmit($form, &$form_state) {
    parent::formSubmit($form, $form_state);

      $this->settings['size_selection'] = $form_state['values']['size_selection'];
  }
}

