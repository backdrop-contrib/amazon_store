<?php
// $ID: $
/**
 * @file Item image template
 * Pass in: amazon_item, size
 */


$configured_image = $amazon_item->$size;
if (!empty($configured_image)) {
  $image = (string)$configured_image->URL;
  $width = (string)$configured_image->Width;
  $height = (string)$configured_image->Height;
} else {
  $image = url("$directory/images/no_image_med.jpg");
  $width = $height = 192;
}

if (!empty($amazon_item->LargeImage)) {
  $largeImage=$amazon_item->LargeImage->URL;
}
$output .= "<img src='$image' width='$width' height='$height' title='{$amazon_item->ItemDetails->Title}' class='amazon-product-image'/>";
if (!empty($largeImage)) {
  $output = "<a href='$largeImage' title='{$amazon_item->ItemAttributes->Title}' class='thickbox'>
    $output</a>";
}
print $output;
