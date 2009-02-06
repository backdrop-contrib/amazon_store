<?php $fullinfo = $variables['fullinfo']?>
<tr class="cart_item">
            <td class="item_cart_image">
              
                <a href="/amazon_raw_item_detail/<?php print $fullinfo->ASIN ?>"><img src="<?php print $fullinfo->SmallImage->URL ?>" alt="<?php print $fullinfo->ItemAttributes->Title ?> "/></a>
              
            </td>
            <td class="item_stats">
              <a class="product_name" href="/amazon_raw_item_detail/<?php print $fullinfo->ASIN ?>"><?php print $fullinfo->ItemAttributes->Title ?></a>
              <strong class="company_name">
                <?php print $fullinfo->ItemAttributes->Manufacturer ?>              </strong>
              
            </td>
            <td class="price_quantity">
              <p class="price"><?php print $xml->Price->FormattedPrice?></p>
              <!-- 
                <p class="availability">
                  XXX Availability
                </p>
                -->
              
              <table cellspacing="0" cellpadding="0">
                <tbody><tr>
                  <td>Quantity:</td>
                  <td class="enter_quantity">
                    <?php print $xml->Quantity ?>
                  </td>
                  <td>
                  	<?php print l("<img src='{$variables['directory']}/images/remove_bu.gif' alt='Remove from cart'>","amazon_store_remove_from_cart/{$xml->CartItemId}",
                  		array('html'=>TRUE)); ?>
                  </td>
                </tr>
              </tbody></table>
            </td>
          </tr>

<?php 
/* Original
function theme_amazon_cart_item($item) {
  $output .= <<<END
  <li>$item->Title ({$item->Price->FormattedPrice} each) Quantity: {$item->Quantity}  
  Total for this item: {$item->ItemTotal->FormattedPrice}
END;
  $output .= l(t("Remove from cart"),"amazon_store_remove_from_cart/{$item->CartItemId}");
  $output .= "</li>";
  
  return $output;
}
*/
?>