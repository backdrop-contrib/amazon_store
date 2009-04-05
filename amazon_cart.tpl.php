<?php
/**
 * $Id$
 * @file
 *   Template file for Amazon_store cart
 */
?>
<h2>Your Cart</h2>
<a href="amazon_store"><img alt="continue shopping"
	class="continue_shopping"
	src="<?php print url("$directory/images/shop_cont_bu.gif") ?>" /></a> <?php if ($cart->CartItems): ?>
<a href="<?php print $cart->PurchaseURL; ?>" target="_blank"><img
	alt="continue checkout" class="continue_checkout"
	src="<?php print url("$directory/images/check_bu.gif") ?>" /></a> <?php endif; ?>

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
				href="/amazon_store/item/<?php print $fullinfo->ASIN ?>"> <?php if (!empty($fullinfo->SmallImage)) : ?>
			<img src="<?php print $fullinfo->SmallImage->URL ?>"
				alt="<?php print $item->Title ?> " /></a> <?php else: ?>
			<img src="<?php print url("$directory/images/no_image_small.jpg"); ?>" /> <?php endif; ?></td>
			<td class="item_stats"><a class="product_name"
				href="/amazon_store/item/<?php print $fullinfo->ASIN ?>"><?php print $fullinfo->ItemAttributes->Title ?></a>
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

			<td class="cart_subtotal"><!--  <input type="image" class="update"
				value="1" name="update" alt="update" src="<?php print url("$directory/images/update_bu.gif") ?>" />
			--> Subtotal: <span class="price"><?php print $cart->SubTotal->FormattedPrice ?></span>
			<p><a href="<?php print $cart->PurchaseURL ?>" target="_blank"><img
				alt="continue checkout" class="continue_checkout"
				src="<?php print $directory ?>/images/check_bu.gif" /></a></p>
			<p><a href="/amazon_store/clear_cart">Empty your cart</a></p>
			</td>
		</tr>
	</tbody>
</table>
<?php endif; ?>