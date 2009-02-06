
<div class="round_box_hack_top">
<div class="round_box_hack_right">
<div class="round_box_hack_bottom">
<div class="round_box_hack_left">
<div class="round_box_hack_tl">
<div class="round_box_hack_tr">
<div class="round_box_hack_br">
<div class="round_box_hack_bl">
<h2>Your Cart</h2>
<a href="amazon_store"><img alt="continue shopping"
	class="continue_shopping" src="<?php print $variables['directory'] ?>/images/shop_cont_bu.gif" /></a> 
	<?php if ($xml->CartItems): ?>
	<a
	href="<?php print $xml->PurchaseURL; ?>" target="_blank"><img alt="continue checkout" class="continue_checkout"
	src="<?php print $variables['directory'] ?>/images/check_bu.gif" /></a>
	<?php endif; ?>

<div class="greyrule" />

<?php if (!$xml->CartItems):?>
There are no items in your cart.
<?php else: ?>

<table cellspacing="0" cellpadding="0" class="items_in_cart">


	<tbody>

	<?php
	foreach ($xml->CartItems->CartItem as $item) {
	  $output .= "<div>";
	  $output .= theme('amazon_cart_item',$item);
	  $output .= "</div>";
	}
	print $output;

	?>

		<tr id="cart_items_footer">
			<td colspan="2"></td>
			
			<td class="cart_subtotal"> 
			<!--  <input type="image" class="update"
				value="1" name="update" alt="update" src="<?php print $variables['directory'] ?>/images/update_bu.gif" />
			-->
			Subtotal: <span class="price"><?php print $xml->SubTotal->FormattedPrice ?></span>
			<p><a href="<?php print $xml->PurchaseURL ?>" target="_blank"><img alt="continue checkout"
				class="continue_checkout" src="<?php print $variables['directory'] ?>/images/check_bu.gif" /></a></p>
			<p><a href="/amazon_store_clear_cart">Empty your cart</a></p>
			</td>
		</tr>
	</tbody>
</table>
<?php endif; ?>
</div>
</div>
</div>
</div>
</div>
</div>
</div>
</div>
</div>



	<?php
	/**
	 * Theme the amazon cart object (simplexml format returned from amazon)
	 * @param $xml  The Cart object
	 * @return formatted html to display the cart
	  
	 function theme_amazon_cart($xml) {
	 if (!isset($xml->CartItems)) {
	 $output .= t("Your cart is empty.");
	 } else {
	 $output .= t("Your cart contains: ");

	 foreach ($xml->CartItems->CartItem as $item) {
	 $output .= "<div>";
	 $output .= theme('amazon_cart_item',$item);
	 $output .= "</div>";
	 }
	 $output .= "<div>Grand total: {$xml->SubTotal->FormattedPrice}</div>";
	 $output .= "<div><a href='{$xml->PurchaseURL}'>Check out now</a></div>";
	 $output .= "<div>".l("Continue Shopping","amazon_store"). "</div>";
	 $output .= '<a href="' . url('amazon_store_clear_cart') . '">Clear cart</a></div>';

	 }
	 return $output;
	 }
	 */
	?>