<?php
// $Id$


/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_title_panels_content_types() {
  $items['item_title'] = array(
    'title' => t('Amazon Item Title'),
    'content_types' => 'amazon_store_item_title',
    'single' => TRUE,
    'render callback' => 'amazon_store_item_title_render',
    'title callback' => 'amazon_store_item_title_admin_title',
    'add callback' => 'amazon_store_item_title_admin',
  
  );
  return $items;
}
function amazon_store_item_title() {
  $item =  array(
    'description' => array(
      'title' => t('Item Title'),
      'icon' => 'icon_amazon.png',
      'path' => panels_get_path('content_types/item_title'),
      'description' => t('Amazon Item Title.'),
      'required context' => new panels_required_context(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
    ),
  );
  return $item;
}


function amazon_store_item_title_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_title';

  $block->title = (string)$context->data->ItemAttributes->Title;
  $block->content = " ";   // without something, block doesn't get displayed
  
  return $block;
}


/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function amazon_store_item_title_admin_title($subtype, $conf, $context) {
  return t('Amazon Product Title', array('@s' => $context->identifier));
}


/**
 * 'Edit' callback for the author pane content type.
 */
function amazon_store_item_title_admin($id, $parents, $conf = array()) {

}


