<?php
// $Id$
/**
 @file
   item_reviews panels plugin for amazon_store
*/

/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_reviews_panels_content_types() {
  $items['item_reviews'] = array(
    'title' => t('Amazon Customer Reviews'),
    'content_types' => 'amazon_store_item_reviews',
    'single' => TRUE,
    'render callback' => 'amazon_store_item_reviews_render',
    'title callback' => 'amazon_store_item_reviews_admin_title',
    'add callback' => 'amazon_store_item_reviews_admin',

  );
  return $items;
}
function amazon_store_item_reviews() {
  $item =  array(
    'description' => array(
      'title' => t('Customer Reviews'),
      'icon' => 'icon_amazon.png',
      'path' => panels_get_path('content_types/item_reviews'),
      'description' => t('Amazon Item Reviews (CustomerReview).'),
      'required context' => new panels_required_context(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
    ),
  );
  return $item;
}


function amazon_store_item_reviews_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_reviews';

  $block->title = t('Customer Reviews');
  $block->content = theme('amazon_store_item_reviews_panel',$context->data);


  return $block;
}


/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function amazon_store_item_reviews_admin_title($subtype, $conf, $context) {
  return t('Amazon Customer Reviews', array('@s' => $context->identifier));
}


/**
 * 'Edit' callback for the author pane content type.
 */
function amazon_store_item_reviews_admin($id, $parents, $conf = array()) {

}


