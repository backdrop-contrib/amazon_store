<?php
/**
 * $Id$
 * @file
 * 	Contents of amazon_store_search_block
 */
print drupal_get_form('amazon_store_search_form');
?>
<br>
<div align="center" class="cart-button"><a href="<?php print url("amazon_store/cart") ?>" title="View your shopping cart">
<img src="<?php print "$directory/images/shopping_cart.png" ?>" /></a>
</div>
