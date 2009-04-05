<?php
// $Id$


/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_details_panels_content_types() {
  $items['item_details'] = array(
    'title' => t('Product Details'),
    'content_types' => 'amazon_store_item_details',
    'single' => TRUE,
    'render callback' => 'amazon_store_item_details_render',
    'title callback' => 'amazon_store_item_details_admin_title',
    'add callback' => 'amazon_store_item_details_admin',
    'edit callback' => 'amazon_store_item_details_admin',

  );
  return $items;
}
function amazon_store_item_details() {
  $item =  array(
    'description' => array(
      'title' => t('Product Details'),
      'icon' => 'icon_amazon.png',
      'path' => panels_get_path('content_types/item_details'),
      'description' => t('Amazon Item Details.'),
      'required context' => new panels_required_context(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
    ),
  );
  return $item;
}


function amazon_store_item_details_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_details';
  $amazon_object = $context->data;
  $size=$conf['size_selection'];
  $image = (string)$amazon_object->$size->URL;
    $width = (string)$amazon_object->$size->Width;
    $height = (string)$amazon_object->$size->Height;

  $block->title = t("Product Details");
  $block->content = theme('amazon_store_details_panel',$context->data);

  return $block;
}


/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function amazon_store_item_details_admin_title($subtype, $conf, $context) {
  return t("Product details");
}


/**
 * 'Edit' callback for the author pane content type.
 */
function amazon_store_item_details_admin($id, $parents, $conf = array()) {
}


