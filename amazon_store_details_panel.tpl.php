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
  'Author' => array('name'=>'Author', 'handler' => 'amazon_store_participant_format'),
  'Composer' => array('name'=>'Composer', 'handler'=>'amazon_store_participant_format'),
  'Artist' => array('name'=>'Artist', 'handler'=>'amazon_store_participant_format'),
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

function amazon_store_manufacturer_format($attributeType, $attributeValue) {
  return theme('amazon_store_search_results_manufacturer', array('manufacturer' => (string)$attributeValue));
}

/**
 * Format a participant detail.
 *
 * This works for author, artist, composer. It guesses the SearchIndex from
 * the ProductGroup. There may be more than one author, so it returns an
 * unordered list in that case.
 *
 * @param $attributeType
 *   'Author' or 'Composer', etc.
 * @param $attributeValue
 *   An array of author/composer/artist names
 * @param $allAttributes
 *   The Attributes section from the original XML.
 */
function amazon_store_participant_format($attributeType, $attributeValue, $allAttributes) {
  $search_index = ProductGroup2SearchIndex((string)$allAttributes->ProductGroup);
  $output = "";
  if (count($attributeValue) > 1) {
    $multi = 1;
  }

  foreach ($attributeValue as $value) {
    $link = l((string)$value, 'amazon_store', array('attributes' => array('rel' => 'nofollow'), 'query'=> array((string)$attributeType => (string)$value, 'SearchIndex' => $search_index)));
    if ($multi) {
      $link = "<li>$link</li>";
    }
    $output .= $link;
  }
  if ($multi) {
    $output = '<ul>' . $output . '</ul>';
  }
  return $output;
}

function amazon_store_feature_format($attributeType, $attributeValue, $allAttributes) {
  $output = "<ul>";
  foreach ($attributeValue as $feature) {
    // Strip items that contain links, which will be unuseful.
    if (!preg_match("/href=/i", $feature)) {
      $output .= "<li>" . check_plain($feature) . "</li>";
    }
  }
  $output .= "</ul>";
  return $output;
}


function amazon_store_binding_format($attributeType, $attributeValue, $allAttributes) {
  $output = (string)$attributeValue;
  if (!empty($allAttributes->NumberOfPages)) {
    $output .= ", {$allAttributes->NumberOfPages} pages";
  }
  return $output;
}


function amazon_store_dimensions_format($attributeType, $attributeValue, $allAttributes) {
  $output = "<ul>";
  if ($attributeValue->Height) {
    $output .= "<li>Dimensions: {$attributeValue->Length}L x {$attributeValue->Width}W x {$attributeValue->Height}H</li>";
  }
  if ($attributeValue->Weight) {
    $output .= "<li>Weight: $attributeValue->Weight</li>";
  }
  $output .= "</ul>";
  return $output;
}

/**
 * Format an attribute based on various handlers.
 *
 * @param $attribute_value
 * @param $handler
 * @param $allAttributes
 */
function amazon_store_format_attribute($attributeType, $attribute_value, $handler, $allAttributes) {
  $output = "{$handler['name']}: ";
  if (!empty($handler['outputElement'])) {
    $output .= $attribute_value->{$handler['outputElement']};
  } else if (!empty($handler['handler'])) {
    $output .= $handler['handler']($attributeType, $attribute_value, $allAttributes);
  } else {
    $output .= (string)$attribute_value;
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
    $output .= amazon_store_format_attribute($itemName, $item->ItemAttributes->{$itemName},
      $handler, $item->ItemAttributes);
    $output .= "</li>";
  }
  print $output;
}
print "<li>ASIN: $item->ASIN</li>";

?>
</ul>
</div>
