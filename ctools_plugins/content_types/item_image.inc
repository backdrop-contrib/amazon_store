<?php
// $Id$


/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_image_ctools_content_types() {
  $items['item_image'] = array(
      'title' => t('Amazon Product Image'),
      'content_types' => 'amazon_store_item_image',
      'single' => TRUE,
      'render callback' => 'amazon_store_item_image_render',
      'edit form' => 'amazon_store_item_image_admin',
      'icon' => 'icon_amazon.png',
      'description' => t('Amazon Item Title.'),
      'required context' => new ctools_context_required(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
  );
  return $items;
}


function amazon_store_item_image_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_image';
  $amazon_object = $context->data;
  // TODO: $conf doesn't seem to be coming through
  $size=$conf['size_selection'];
  $block->content = theme('amazon_store_item_image',$amazon_object,$size);
  return $block;
}


/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function amazon_store_item_image_admin_title($subtype, $conf, $context) {
  return t("Product Image (@s) - {$conf['size_selection']}", array('@s' => $context->identifier));
}


/**
 * 'Edit' callback for the author pane content type.
 */
function amazon_store_item_image_admin(&$form, &$form_state) {
  $conf = $form_state['conf'];

  $form['size_selection'] = array(
      '#title' => t("Product Image Size"),
      '#type' => 'select',
      '#description' => t("Which of the three Amazon Product Images would you like"),
      '#options' => array('SmallImage' => t('Small'), 'MediumImage'=>t('Medium'), 'LargeImage'=>t('Large')),
      '#default_value' => !empty($conf['size_selection']) ? $conf['size_selection'] : 'MediumImage',
  );
  return $form;
}

function amazon_store_item_image_admin_submit(&$form, &$form_state) {
  $form_state['conf']['size_selection'] = $form_state['values']['size_selection'];
}

