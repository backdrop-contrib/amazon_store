<?php
// $Id$
/**
 @file
  Right now this provides nothing more than a link
  allowing clearing the cache for the context-driven
  amazon product. For debugging.
*/

/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_specials_panels_content_types() {
  $items['item_specials'] = array(
    'title' => t('Special Links'),
    'content_types' => 'amazon_store_item_specials',
    'single' => TRUE,
    'render callback' => 'amazon_store_item_specials_render',
    'title callback' => 'amazon_store_item_specials_admin_title',
    'add callback' => 'amazon_store_item_specials_admin',
    'edit callback' => 'amazon_store_item_specials_admin',

  );
  return $items;
}
function amazon_store_item_specials() {
  $item =  array(
    'description' => array(
      'title' => t('Debugging Links'),
      'icon' => 'icon_amazon.png',
      'path' => panels_get_path('content_types/item_specials'),
      'description' => t('Debugging Tools - Clear Cache for an item.'),
      'required context' => new panels_required_context(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
  ),
  );
  return $item;
}


function amazon_store_item_specials_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_specials';
  $amazon_object = $context->data;
  $block->title = t("Refresh Page/Clear Cache");

  $output .= "<div><a href='/amazon_store/clear_cache/{$amazon_object->ASIN}?destination=amazon_store/item/{$amazon_object->ASIN}'>Refresh this page</a></div>";
  $block->content = $output;
  return $block;

}

/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function amazon_store_item_specials_admin_title($subtype, $conf, $context) {
  return t("Debugging Block");
}


/**
 * 'Edit' callback for the author pane content type.
 */
function amazon_store_item_specials_admin($id, $parents, $conf = array()) {
}


