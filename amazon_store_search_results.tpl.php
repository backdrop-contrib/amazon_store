<?php
/**
 * $Id$
 * @file
 *   Template file for the searchresults page (/amazon_store)
 *
 */

?>
<?php
  if (variable_get('amazon_store_show_searchform',TRUE)) {
    print drupal_get_form('amazon_store_search_form');
  }
?>
<div class="amazon-store-panel search-results"><!--
<a href='<?php url("amazon_store/cart") ?>'> Go to your cart</a>
 -->


<?php if (!empty($results->Item)): ?>

<div class="change_sort"><?php
if (variable_get('amazon_store_show_sort_form',TRUE)) {
    print drupal_get_form('amazon_store_sort_form');
}?>
</div>
<div class="search-sets narrow-by"><?php
if (variable_get('amazon_store_show_narrowby_form',TRUE) && !empty($results->SearchBinSets)) {
  $form = drupal_get_form('amazon_store_searchbin_sets_form',$results->SearchBinSets);
  print $form;
}
?></div>


<div id="amazon-store-search-results" class="amazon-form"><?php if  (isset($Keywords) && isset($SearchIndex) && count($SearchIndex)) : ?>
<h3>Your search for <?php print "$Keywords in $SearchIndex" ?></h3>
<?php endif; ?>
<table>
	<tbody>

	<?php $i=0;
	foreach ($results->Item as $result):
	if ($result->OfferSummary->TotalNew == 0 && empty($result->Variations->Item)) {
	  continue;
	}
	$asin = (string)$result->ASIN;
	$form = drupal_get_form('amazon_store_addcart_form',(string)$result->ASIN);
	?>

		<!--  BEGIN ITEM PROCESSING -->
		<tr>
			<td><?php if (!empty($result->LargeImage)) : ?> <a
				href="<?php print $result->LargeImage->URL; ?>" class="thickbox"
				title="<?php print $result->ItemAttributes->Title ?>"> <img
				src="<?php print $result->MediumImage->URL ?>"
				alt="Image of <?php print $result->ItemAttributes->Title ?>"
				class="product-image" /></a> <?php else: ?>
        <?php print theme('image',"$directory/images/no_image_med.jpg"); ?>
       <?php endif; ?></td>
			<td>
			<p class="title"><a
				href="<?php print url("amazon_store/item/{$result->ASIN}") ?>"> <?php print $result->ItemAttributes->Title ?></a></p>
				<?php if (!empty($result->ItemAttributes->Manufacturer)){
				  print theme('amazon_store_search_results_manufacturer',(string)$result->ItemAttributes->Manufacturer);
				}
				?>

			<div class="editorial">
        <?php if (!empty($result->EditorialReviews->EditorialReview[0]->Content)) { ?>
          <a href="javascript:void(null)"
          class="togglebtn">Show/hide full description</a> or
          <?php } ?>
          <a
				href="<?php print url("amazon_store/item/{$result->ASIN}"); ?>">See full
			details</a>
			<div class="toggle editorial">
			<?php
			if (!empty($result->EditorialReviews->EditorialReview[0]->Content)) {
			  print check_markup($result->EditorialReviews->EditorialReview[0]->Content, 2 /* full html */, FALSE);
			}
			?>
      </div>
			</div>
			<?php print $form; ?></td>

		</tr>
		<!--  END ITEM PROCESSING -->
		<?php endforeach; ?>


		<tr>
			<td colspan="3">
			<div class="greyrule"></div>
			</td>
		</tr>
	</tbody>
</table>

</div>
<!--  end mid_right_column_wrap --><?php $nextpage = _amazon_store_nextpage($results->TotalPages); ?>
		<?php if ($nextpage) { ?>
<div class="nextpage"><a
	href="<?php print url("amazon_store",array('query' => _amazon_store_revise_query(array('ItemPage'=>$nextpage))));  ?>">&gt;&gt;Go
to Page <?php print "$nextpage of {$results->TotalPages} pages " ?> of
results</a></div>
<?php } ?>

		<?php endif; ?></div>
<?php print "<br />" . l(t("View Cart"), 'amazon_store/cart', array('attributes' => array('class' => 'buttonize continue_checkout')));
?>
