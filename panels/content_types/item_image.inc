<?php
// $Id$


/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_image_panels_content_types() {
  $items['item_image'] = array(
    'title' => t('Amazon Product Image'),
    'content_types' => 'amazon_store_item_image',
    'single' => TRUE,
    'render callback' => 'amazon_store_item_image_render',
    'title callback' => 'amazon_store_item_image_admin_title',
    'add callback' => 'amazon_store_item_image_admin',
    'edit callback' => 'amazon_store_item_image_admin',

  );
  return $items;
}
function amazon_store_item_image() {
  $item =  array(
    'description' => array(
      'title' => t('Product Image'),
      'icon' => 'icon_amazon.png',
      'path' => panels_get_path('content_types/item_image'),
      'description' => t('Amazon Item Title.'),
      'required context' => new panels_required_context(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
    ),
  );
  return $item;
}


function amazon_store_item_image_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_image';
  $amazon_object = $context->data;
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
function amazon_store_item_image_admin($id, $parents, $conf = array()) {

  $form['size_selection'] = array(
    '#title' => t("Product Image Size"),
    '#type' => 'select',
    '#description' => t("Which of the three Amazon Product Images would you like"),
    '#options' => array('SmallImage' => t('Small'), 'MediumImage'=>t('Medium'), 'LargeImage'=>t('Large')),
    '#default_value' => $conf['size_selection'],
  );


  return $form;
}


