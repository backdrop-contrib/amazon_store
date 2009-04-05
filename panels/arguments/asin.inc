<?php
// $Id$


/**
 * @file arguments/asin.inc
 *
 * Plugin to provide an argument for Amazon ASIN 
 */
function amazon_store_asin_panels_arguments() {
  $args['asin'] = array(
    'title' => t("ASIN (Amazon item identifier)"),
    // keyword to use for %substitution
    'keyword' => 'ASIN',
    'description' => t('Creates an Amazon item from the ASIN.'),
    'context' => 'amazon_store_create_asin_context',
    'settings form' => 'amazon_store_asin_settings_form',
    'settings form submit' => 'amazon_store_asin_settings_form_submit',
    'displays' => 'amazon_store_asin_displays',
    'choose display' => 'amazon_store_asin_choose_display',
    'native path' => 'amazon_store/item',
  );
  return $args;
}

function amazon_store_create_asin_context($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If unset it wants a generic, unfilled context.
  if ($empty) {
    return panels_context_create_empty('amazon_item');
  }

  return panels_context_create('amazon_item', $arg);
}


/**
 * Settings form for the argument
 */
function amazon_store_asin_settings_form($conf) {
  // Doing different displays based upon role is hard because roles are not
  // 1:1 like type/vocabulary are for node and term.
}


function amazon_store_asin_settings_form_submit(&$values) {
}

function amazon_store_asin_displays($conf, $id) {
  return array();
}

/**
 * Based upon the settings and the context, choose which display to use.
 */
function amazon_store_asin_choose_display($conf, $context) {
}
