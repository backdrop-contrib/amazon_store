<?php
// $Id$
/**
 @file
  Debugging info content_type plugin for amazon_store
*/

/**
 * Callback function to supply a list of content types.
 */
function amazon_store_item_debug_info_panels_content_types() {
  $items['item_debug_info'] = array(
    'title' => t('Debug Info'),
    'content_types' => 'amazon_store_item_debug_info',
    'single' => TRUE,
    'render callback' => 'amazon_store_item_debug_info_render',
    'title callback' => 'amazon_store_item_debug_info_admin_title',
    'add callback' => 'amazon_store_item_debug_info_admin',
    'edit callback' => 'amazon_store_item_debug_info_admin',

  );
  return $items;
}
function amazon_store_item_debug_info() {
  $item =  array(
    'description' => array(
      'title' => t('Debug Info'),
      'icon' => 'icon_amazon.png',
      'path' => panels_get_path('content_types/item_debug_info'),
      'description' => t('Debugging data - shows the actual object returned from Amazon and displayed on this page'),
      'required context' => new panels_required_context(t('Amazon Item'), 'amazon_item'),
      'category' => array(t('Amazon'), -9),
  ),
  );
  return $item;
}



function amazon_store_item_debug_info_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'item_debug_info';
  $amazon_object = $context->data;
  $block->title = 'Debug Info <a href="#" class="togglebtn" >click here</a>';

  $output .= "<div id='debug_info'  >
  <div class='item_xml toggle' style='display:none'>" . dpr($context->data,true,"XML input")
   . "
  </div>
  </div>";
  $block->content = $output;
  return $block;

}

/**
 * Display the administrative title for a panel pane in the drag & drop UI
 */
function amazon_store_item_debug_info_admin_title($subtype, $conf, $context) {
  return t("Debug info");
}


/**
 * 'Edit' callback for the author pane content type.
 */
function amazon_store_item_debug_info_admin($id, $parents, $conf = array()) {
}


