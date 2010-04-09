<?php
/**
 * $Id$
 * @file
 * 	Contents of amazon_store_search_block
 */
print drupal_render(drupal_get_form('amazon_store_search_form', variable_get('amazon_store_search_block_keywords_width', 15)));
// You could add a link to the cart here.