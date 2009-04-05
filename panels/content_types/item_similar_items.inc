<?php
// $Id$
/**
 @file
  Similar items panels plugin for amazon_store
*/

/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_similar_items_panels_content_types() {
  $items['item_similar_items'] = array(
    'title' => t('Similar Items'),
    'content_types' => 'amazon_store_item_similar_items',
    'single' => TRUE,
    'render callback' => 'amazon_store_item_similar_items_render',
    'title callback' => 'amazon_store_item_similar_items_admin_title',
    'add callback' => 'amazon_store_item_similar_items_admin',
  
  );
  return $items;


  
}
function amazon_store_item_similar_items() {
  $item =  array(
    'description' => array(
      'title' => t('Similar Items'),
      'icon' => 'icon_amazon.png',
      'path' => panels_get_path('content_types/item_similar_items'),
      'description' => t('Amazon Item Reviews (CustomerReview).'),
      'required context' => new panels_required_context(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
    ),
  );
  return $item;
}


function amazon_store_item_similar_items_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_similar_items';
  $amazon_object = $context->data;
  $block->title = t('Similar Products');
  $block->content = theme('amazon_store_similar_items_panel',$context->data);
  return $block;
}


/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function amazon_store_item_similar_items_admin_title($subtype, $conf, $context) {
  return t('Amazon Similar Items', array('@s' => $context->identifier));
}


/**
 * 'Edit' callback for the author pane content type.
 */
function amazon_store_item_similar_items_admin($id, $parents, $conf = array()) {
}


