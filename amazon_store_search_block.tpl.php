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
<?php print theme('image',"$directory/images/shopping_cart.png", t('Shopping Cart'), t('Shopping Cart')); ?></a>
</div>
