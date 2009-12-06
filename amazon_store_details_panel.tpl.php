<?php
/**
 * $Id$
 * @file
 *   Template file for item details panel plugin
 */

// For each ItemAttribute to be reported, list the attribute
// and an array with:
// name, if different from the XML name
// outputElement - Child that can be output as is
// handler, if handling has to be done by a special function, which will be passed the name and object
// These will be done in the order listed here.
// If not found here, they will not be output
$handlers = array(
  'Author' => array('name'=>'Author', 'handler' => 'amazon_store_author_format'),
  'Composer' => array('name'=>'Composer', 'handler'=>'amazon_store_composer_format'),
  'Artist' => array('name'=>'Artist', 'handler'=>'amazon_store_artist_format'),
  'PublicationDate' => array('name'=>"Publication Date"),
  'Publisher' => array('name'=>"Publisher"),

  'ProductGroup' => array('name'=>"Product Group"),
  'Manufacturer' => array('name'=>"Manufacturer", 'handler' => 'amazon_store_manufacturer_format'),
  'Binding' => array('name'=>"Binding", 'handler' => 'amazon_store_binding_format'),
  'Brand' => array('name'=>"Brand",),
  'Feature' => array('name'=>"Features", 'handler'=>'amazon_store_feature_format'),
  'FormFactor' => array('name'=>"Form Factor"),
  'HardwarePlatform'=>array('name'=>"Hardware Platform"),
  'ItemDimensions' => array('name'=>"Item Dimensions", 'handler'=>'amazon_store_dimensions_format'),
  'PackageDimensions' => array('name'=>"Package Dimensions", 'handler'=>'amazon_store_dimensions_format'),
  'ListPrice' => array('name'=>"List Price", 'outputElement'=>'FormattedPrice'),
  'Model' => array('name' => "Model Number"),
  'UPC' => array('name' => "UPC",),
  'ISBN' => array('name'=>"ISBN"),
  'Warranty' => array('name'=>"Warranty",),
);
function amazon_store_manufacturer_format($item) {
  return theme('amazon_store_search_results_manufacturer',(string)$item);
}
function amazon_store_author_format($item) {
    return l($item,"amazon_store",array('query'=>"author=$item"));
}
function amazon_store_artist_format($item) {
  return l($item,"amazon_store",array('query'=>"artist=$item"));
}
function amazon_store_composer_format($item) {
  return l($item,"amazon_store",array('query'=>"composer=$item"));
}

function amazon_store_feature_format($item) {
  $output = "<ul>";
  foreach ($item as $feature) {
    // Strip items that contain links, which will be unuseful.
    if (!preg_match("/href=/i", $feature)) {
      $output .= "<li>" . check_plain($feature) . "</li>";
    }
  }
  $output .= "</ul>";
  return $output;
}
function amazon_store_binding_format($item,$allAttributes) {
  $output = "$item";
  if (!empty($allAttributes->NumberOfPages)) {
    $output .= ", {$allAttributes->NumberOfPages} pages";
  }
  return $output;
}
function amazon_store_dimensions_format($item) {
  $output = "<ul>";
  if ($item->Height) {
    $output .= "<li>Dimensions: {$item->Length}L x {$item->Width}W x {$item->Height}H</li>";
  }
  if ($item->Weight) {
    $output .= "<li>Weight: $item->Weight</li>";
  }
  $output .= "</ul>";
  return $output;
}
function amazon_store_format_attribute($item,$handler,$allAttributes) {
  $output = "{$handler['name']}: ";
  if (!empty($handler['outputElement'])) {
    $output .= $item->{$handler['outputElement']};
  } else if (!empty($handler['handler'])) {
    $output .= $handler['handler']($item,$allAttributes);
  } else {
    $output .= (string)$item;
  }
  return $output;
}

?>
<div class="product_details">
<ul>
<?php
foreach ($handlers as $itemName=>$handler) {
  $output = "";
  if ($item->ItemAttributes->$itemName) {
    $output ="<li>";
    $output .= amazon_store_format_attribute($item->ItemAttributes->$itemName,
      $handler,
      $item->ItemAttributes);
    $output .= "</li>";
  }
  print $output;
}
print "<li>ASIN: $item->ASIN</li>";

?>
</ul>
</div>
