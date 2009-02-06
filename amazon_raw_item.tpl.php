<tr>
              <td>
                
                  <a href="/amazon_raw_item_detail/<?php print $xml->ASIN ?>">
                  <img src="<?php print $xml->SmallImage->URL ?>" alt="Image of <?php $xml->ItemAttributes->Title ?>"/></a>
                
              </td>
              <td>
                <p>
                  <a href="/amazon_raw_item_detail/<?php print $xml->ASIN ?>"><?php print $xml->ItemAttributes->Title ?></a>
                </p>
                
                    <p class="company">
                    <?php print $xml->ItemAttributes->Manufacturer ?>
                  </p>
                
                
              </td>
              <td>
                
                  <p class="price">
                    <?php print $xml->OfferSummary->LowestNewPrice->FormattedPrice ?>
                  </p>
                  <p class="availability">
                      XXX Show availability
                  </p>
                
              </td>
            </tr>




<!-- Original
<img src="<?php print $xml['imagesets']['smallimage']['url']; ?>" />
<div><strong>Title: <a href="amazon_raw_item_detail/<?php print $xml['asin'] ?>"><?php print $xml['title'] ?></a></strong></div>
<div><strong><?php print t('Manufacturer'); ?>:</strong> <?php print $xml['manufacturer']; ?></div>
<div><strong><?php print t('Part Number'); ?>:</strong> <?php print $xml['mpn']; ?></div>
<div><strong><?php print t('Price'); ?>:</strong> <?php print $xml['listpriceformattedprice']; ?></div>
<ul>
<li><?php print l(t("Add to cart"),"amazon_store_add_to_cart/{$xml['asin']}"); ?></li>
</ul>
</div>
-->