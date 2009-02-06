<?php $xml = $variables['xml']; ?>
<a href='/amazon_store'><img alt='continue shopping'
	class='continue_shopping' src='/<?php print $variables['directory'] ?>/images/shop_cont_bu.gif'  /></a> 
<a href='/amazon_store_show_cart'><img src='/<?php print $variables['directory'] ?>/images/cart.gif' alt='shopping cart' /> See your cart</a>

<div id="product_summary">
<div id="summary_left_column"><img alt=" "
	src="<?php print $xml->MediumImage->URL; ?>" />
<div id="viewlarger">

<p><a href="<?php print $xml->LargeImage->URL ?>"><img alt=" "
	src="<?php print $variables['directory'] ?>/images/zoom.gif" /></a> <a
	href="<?php print $xml->LargeImage->URL ?>">View larger image</a></p>


</div>

</div>
<!-- end summary_left_column -->
<div id="summary_mid_rt_column_wrap">
<div id="summary_middle_column">
<h2><?php print $xml->ItemAttributes->Title ?></h2>

<!-- 
         TODO: select list to show buying options goes here
      -->

<p><a href="/amazon_store_add_to_cart/<?php print $xml->ASIN ?>"> <img
	src="/<?php print $variables['directory'] ?>/images/addcart_bu.gif" alt="Add to cart" /></a>

</p>
<!-- Optional wish list goes here -->
</div><!-- end summary_middle_column -->
<div id="summary_right_column">

<h3><?php print $xml->ItemAttributes->Manufacturer ?></h3>
<p>XXX find company data and put here</p>
<p><a href="/about/company_rating">Learn more</a> »</p>


<!-- end summary_right_column --></div>
<!-- end summary_mid_rt_column_wrap --></div>
<!-- end product_summary --></div>
<div class="greyrule_clear"></div>
<div id="left_column">
    <div class="box">
      <div class="corner_hack_tr">
        
          
            <h4>
              <span class="corner_hack_tl">
                <span class="corner_hack_tr">
                  <span class="corner_hack_br">
                    <span class="corner_hack_bl">
                      Browse Similar Items
                    </span>
                  </span>
                </span>
              </span>
            </h4>
            <ul id="similar_itemlist">
              <!--  display similar items -->
                
            <!--  end similar_itemlist --></ul>
          
        
        
          
          
        
      </div>
    </div>
  </div>
<div id="mid_right_column_wrap">
<h3>Product Details</h3>

<p><strong>Average Amazon User Rating:</strong> <img width="56"
	height="11" alt="Average rating: <?php print $xml->CustomerReviews->AverageRating ?> stars"
	src="/<?php print "{$variables['directory']}/images/" . round($xml->CustomerReviews->AverageRating) ?>stars.gif" />
</p>


<p><strong>Availability:</strong> XXX get availability. <!-- But may not
belong here, as this is per offer.--></p>

<h4><?php print $xml->EditorialReviews->EditorialReview[0]->Source ?></h4>
<?php print $xml->EditorialReviews->EditorialReview[0]->Content; ?>
<?php if ($xml->CustomerReviews->Review): ?>
<h3>Reviews</h3>

<?php foreach ($xml->CustomerReviews->Review as $review) : ?>
<div class="customer_review">
<p><img width="56" height="11"
	alt="<?php print $review->Rating ?> stars"
	src="<?php print "/{$variables['directory']}/images/". round($review->Rating) ?>stars.gif" 
	/>  <strong><?php print $review->Summary ?></strong> 
<?php print $review->Date ?></p>

<p>Reviewer: <strong><?php print $review->Reviewer->Name ?></strong></p>

<p><?php print $review->Content; ?></p>
</div>

<?php endforeach; ?></div>
<?php endif; ?>
