<?php
// $ID: $
/**
 * @file
 *   Present a block of Amazon store category links.
 */

$categories = $GLOBALS['amazon_store_search_indexes']->getSearchIndexPulldown(TRUE);

$output = "<div class='amazon-store-category-blurb'>" . t("Search Amazon in these categories:") . "</div>";
$output .= "<ul>";
foreach($categories as $category => $friendly_name) {
  $link = l($friendly_name, "amazon_store", array('query' => array('SearchIndex' => $category)));
  $output .= "<li>$link</li>";
}
$output .= "</ul>";
$output = "<div class='amazon-store-category-links'>" . $output . "</div>";
print $output;