<?php
/**
 * $Id$
 * @file
 *  Provides the amazon_item context plugin for amazon_store panel
 * 
 */
/**
 * Implementation of hook_panels_contexts()
 */
function amazon_store_amazon_item_panels_contexts() {

  $items['amazon_item'] = array(
    'title' => t('Amazon Item'),
    'description' => t('An item on Amazon.com (a unique ASIN).'),
    'context' => 'amazon_store_amazon_item_context',
    'keyword' => 'amazon_item',
    'context name' => 'amazon_item',
    'no ui' => TRUE,
  );
  return $items;
}

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function amazon_store_amazon_item_context($empty, $data = NULL, $conf = FALSE) {
  $context = new panels_context('amazon_item');
  $context->plugin = 'amazon_item';
  $context->keyword = 'xxx';

  if ($empty) {
    return $context;
  }

  if ($conf) {
    if (!empty($data)) {
      $context->data = new stdclass();
      $context->data->description = "Our context is &gt;{$data['item1']}&lt; and it came from config info.";
      $context->title    = t("amazon_item Context from config");
      return $context;
    }
  } else { // $data is coming from an arg - it's just a string
    $context->data = amazon_store_retrieve_item($data);
    if ($context->data) {
      $context->arg = $data;
      $context->title = $context->data->ItemAttributes->Title;
    }
    return $context;
  }
}

