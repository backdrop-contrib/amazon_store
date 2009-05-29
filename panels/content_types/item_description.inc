<?php
// $Id$
/**
 @file
  Provides item description for amazon item

/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_description_panels_content_types() {
  $items['item_description'] = array(
    'title' => t('Amazon Item Description'),
    'content_types' => 'amazon_store_item_description',
    'single' => TRUE,
    'render callback' => 'amazon_store_item_description_render',
    'title callback' => 'amazon_store_item_description_admin_title',
    'add callback' => 'amazon_store_item_description_admin',

  );
  return $items;
}
function amazon_store_item_description() {
  $item =  array(
    'description' => array(
      'title' => t('Item Description'),
      'icon' => 'icon_amazon.png',
      'path' => panels_get_path('content_types/item_description'),
      'description' => t('Amazon Item Description (EditorialReview).'),
      'required context' => new panels_required_context(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
    ),
  );
  return $item;
}


function amazon_store_item_description_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_description';

  $block->title = (string)$context->data->EditorialReviews->EditorialReview[0]->Source;
  $block->content = filter_xss((string)$context->data->EditorialReviews->EditorialReview[0]->Content);

  return $block;
}


function amazon_store_item_description_admin_title($subtype, $conf, $context) {
  return t('Amazon Item Description (@s)', array('@s' => $context->identifier));
}


function amazon_store_item_description_admin($id, $parents, $conf = array()) {
}
