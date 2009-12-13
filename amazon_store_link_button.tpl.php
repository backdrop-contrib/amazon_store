<?php
// $ID: $
/**
 * @file
 *   Theme a link as a button.
 */
global $_amazon_store_link_formnum;
print drupal_get_form("amazon_store_buttonize_link" . $_amazon_store_link_formnum, $text, $url);
$_amazon_store_link_formnum++;