<?php
/**
 * $Id$
 * @file
 *   Amazon item detail template
 */
?>

<div id="main-wrapper" class="item-detail-wrapper">
<div class="columns-wrapper">
<?php drupal_set_title((string)$amazon_item->ItemAttributes->Title); ?>
<!--  Top section, with title and navigation, cart -->
<div id="topnav">
<h3 id="title"><?php print (string)$amazon_item->ItemAttributes->Title ?></h3>

<a href="<?php print url("amazon_store") ?>">Continue Shopping</a> or <a
  href='<?php print url("amazon_store/cart")?>'>See your cart</a></div>

<!-- Left section: Item Description and Product Reviews -->
<div id="item-details" class="left-column column">
<h3>Item Description</h3>
<p id="product-description">
<?php
if (!empty($editorialreview)) {
  print $editorialreview;
}
?>
</p>

<h3>Product Details</h3>
<p id="product-details"><?php print theme('amazon_store_details_panel', array('item' => $amazon_item)); ?>
</p>
</div>
<!-- End item-details -->

<div id="right-column" class="column">
<?php print theme('amazon_store_item_image', array('amazon_item' => $amazon_item, 'size' => 'MediumImage')); ?>

<h3>Buying Options</h3>
<?php print theme('amazon_store_item_offers', array('amazon_item' => $amazon_item)); ?>

<h3>Similar Items</h3>
<?php print theme('amazon_store_similar_items_panel', array('item' => $amazon_item)); ?>
</div>

</div>
<div id="bottom-section" class="column">
<h3>Customer Reviews</h3>
<?php print theme('amazon_store_item_reviews_panel', array('item' => $amazon_item)); ?></div>

</div>