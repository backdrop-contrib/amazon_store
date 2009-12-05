<?php
/**
 * $Id$
 * @file
 *   Template file for Amazon_store cart
 */
?>
<h2>Your Cart</h2>

<?php print l(t("Continue Shopping"), 'amazon_store', array('attributes' => array('class' => 'buttonize continue_shopping')));
  if ($cart->CartItems) {
     print l(t("Checkout at Amazon"), $cart->PurchaseURL, array('attributes' => array('class' => 'buttonize continue_checkout')));
  } ?>
<div class="greyrule" ></div>
<?php if (!$cart->CartItems):?> There are no
items in your cart. <?php else: ?>

<table cellspacing="0" cellpadding="0" class="items_in_cart">


	<tbody>

	<?php
	$fullinfo=current($fullrecords);
	$i=0;
	foreach ($cart->CartItems->CartItem as $item) {
	  ?>
		<tr class="cart_item">
			<td class="item_cart_image"><a
				href="<?php print url("amazon_store/item/{$fullinfo->ASIN}") ?>"> <?php if (!empty($fullinfo->SmallImage)) : ?>
			<img src="<?php print $fullinfo->SmallImage->URL ?>"
				alt="<?php print $item->Title ?> " /></a> <?php else: ?>
			<?php print theme('image',"$directory/images/no_image_small.jpg"); ?> <?php endif; ?></td>
			<td class="item_stats"><a class="product_name"
				href="<?php print url("amazon_store/item/{$fullinfo->ASIN}") ?>"><?php print $fullinfo->ItemAttributes->Title ?></a>
			<strong class="company_name"> <?php print $fullinfo->ItemAttributes->Manufacturer ?>
			</strong></td>
			<td class="price_quantity">
			<p class="price"><?php print $item->Price->FormattedPrice?></p>
      <!--  Note that $item->Availability has been added by amazon_store; it's not normally there -->
			<p class="availability">Sold by <?php print $item->SellerNickname . ": ".  $item->Availability ?>
			</p>

			<td class="enter_quantity"><?php print drupal_get_form('_amazon_store_cart_quantity_form'."-$item->ASIN",$item, $i++); ?></td>

		</tr>


		<?php
		$fullinfo = next($fullrecords);
	} ?>

		<tr id="cart_items_footer">
			<td colspan="2"></td>

			<td class="cart_subtotal">Subtotal: <span class="price"><?php print $cart->SubTotal->FormattedPrice ?></span>
			<p>
      <?php if ($cart->CartItems) {
        print l(t("Checkout at Amazon"), $cart->PurchaseURL, array('attributes' => array('class' => 'buttonize continue_checkout')));
      } ?>

    </p>
			<p><a href="<?php print url("amazon_store/clear_cart"); ?>">Empty your cart</a></p>
			</td>
		</tr>
	</tbody>
</table>
<?php endif; ?>