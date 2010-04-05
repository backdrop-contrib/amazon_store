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
  $image = "$directory/images/no_image_med.jpg";
  $width = $height = 192;
}

if (!empty($amazon_item->LargeImage)) {
  $largeImage=$amazon_item->LargeImage->URL;
}
$img_code = theme('image', $image, $amazon_item->ItemDetails->Title, $amazon_item->ItemDetails->Title, array('class' => 'amazon-product-image', 'height' => $height, 'width' => $width), FALSE);
$output = $img_code;
if (!empty($largeImage)) {
  $output = l($img_code, $largeImage, array('attributes' => array('html' => TRUE, 'attributes' => array('title' => $amazon_item->ItemAttributes->Title, 'class' => 'thickbox', 'rel' => 'nofollow')));
}
print $output;
