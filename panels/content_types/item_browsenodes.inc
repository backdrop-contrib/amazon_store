<?php
// $Id$
/**
 @file
  Implements browsenodes content type for amazon_store
 */

/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_browsenodes_panels_content_types() {
  $items['item_browsenodes'] = array(
    'title' => t('Amazon Browse'),
    'content_types' => 'amazon_store_item_browsenodes',
    'single' => TRUE,
    'render callback' => 'amazon_store_item_browsenodes_render',
    'title callback' => 'amazon_store_item_browsenodes_admin_title',
    'add callback' => 'amazon_store_item_browsenodes_admin',
  
  );
  return $items;


  
}
function amazon_store_item_browsenodes() {
  $item =  array(
    'description' => array(
      'title' => t('Browse'),
      'icon' => 'icon_amazon.png',
      'path' => panels_get_path('content_types/item_browsenodes'),
      'description' => t('Amazon Item Reviews (CustomerReview).'),
      'required context' => new panels_required_context(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
    ),
  );
  return $item;
}


function amazon_store_item_browsenodes_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_browsenodes';
  $amazon_object = $context->data;
  $block->title = t('Browse Categories');
  $block->content = theme('amazon_store_browsenodes_panel',$context->data);
  return $block;
}


/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function amazon_store_item_browsenodes_admin_title($subtype, $conf, $context) {
  return t('Amazon Browse', array('@s' => $context->identifier));
}


/**
 * 'Edit' callback for the author pane content type.
 */
function amazon_store_item_browsenodes_admin($id, $parents, $conf = array()) {
}


