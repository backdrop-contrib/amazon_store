<?php
// $Id$
/**
 @file
   Item_offers content_type panels plugin
*/

/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_offers_panels_content_types() {
  $items['item_offers'] = array(
    'title' => t('Offers'),
    'content_types' => 'amazon_store_item_offers',
    'single' => TRUE,
    'render callback' => 'amazon_store_item_offers_render',
    'title callback' => 'amazon_store_item_offers_admin_title',
    'add callback' => 'amazon_store_item_offers_admin',
    'edit callback' => 'amazon_store_item_offers_admin',

  );
  return $items;
}
function amazon_store_item_offers() {
  $item =  array(
    'description' => array(
      'title' => t('Offers'),
      'icon' => 'icon_amazon.png',
      'path' => panels_get_path('content_types/item_offers'),
      'description' => t('Amazon Item Offers.'),
      'required context' => new panels_required_context(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
  ),
  );
  return $item;
}


function amazon_store_item_offers_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_offers';
  $amazon_object = $context->data;
  $block->title = t("Buying Options");

  $block->content = theme('amazon_store_item_offers',$amazon_object);
  return $block;

}

/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function amazon_store_item_offers_admin_title($subtype, $conf, $context) {
  return t("Amazon Offers");
}


/**
 * 'Edit' callback for the author pane content type.
 */
function amazon_store_item_offers_admin($id, $parents, $conf = array()) {

}


