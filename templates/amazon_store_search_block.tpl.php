<?php
/**
 * @file
 * 	Contents of amazon_store_search_block
 */
$width = config_get('amazon_store.settings', 'amazon_store_search_block_keywords_width');
$form = drupal_get_form('amazon_store_search_form', $width);
print drupal_render($form);
// You could add a link to the cart here.