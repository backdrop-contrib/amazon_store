<?php
/**
 * $Id$
 * @file
 *   Template file for the searchresults page (/amazon_store)
 *
 */

?>
<div class="amazon-store-panel search-results"><!--
<a href='/amazon_store/cart'> Go to your cart <img
  src='/<?php // print url("$directory/images/chngcart_bu.gif") ?>'
  alt='shopping cart' /></a>
 -->

<div class="change_sort"><?php  print drupal_get_form('_amazon_store_sort_form')?>
</div>
<div class="search-sets"><?php
if (!empty($results->SearchBinSets)) {
  $form = drupal_get_form('_amazon_store_searchbin_sets_form',$results->SearchBinSets);
  print $form;
}
?></div>
<?php if ($results): ?>


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
	$form = drupal_get_form('_amazon_store_addcart_form',(string)$result->ASIN);
	?>

		<!--  BEGIN ITEM PROCESSING -->
		<tr>
			<td><?php if (!empty($result->LargeImage)) : ?> <a
				href="<?php print $result->LargeImage->URL; ?>" class="thickbox"
				title="<?php print $result->ItemAttributes->Title ?>"> <img
				src="<?php print $result->MediumImage->URL ?>"
				alt="Image of <?php print $result->ItemAttributes->Title ?>"
				class="product-image" /></a> <?php else: ?> <img
				src="<?php print url("$directory/images/no_image_med.jpg"); ?>" /> <?php endif; ?></td>
			<td>
			<p class="title"><a
				href="/amazon_store/item/<?php print "{$result->ASIN}" ?>"> <?php print $result->ItemAttributes->Title ?></a></p>
				<?php if (!empty($result->ItemAttributes->Manufacturer)){
				  print theme('amazon_store_search_results_manufacturer',(string)$result->ItemAttributes->Manufacturer);
				}
				?>

			<div class="editorial"><a href="javascript:void(null)"
				class="togglebtn">Show/hide full description</a> or <a
				href="amazon_store/item/<?php  print $result->ASIN; ?>">See full
			details</a>
			<div class="toggle editorial"><?php print $result->EditorialReviews->EditorialReview[0]->Content; ?></div>
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
<!--  end mid_right_column_wrap --><?php $nextpage = _amazon_store_nextpage(); ?>
		<?php //TODO: Rewrite query - page X of Y, and make sure we don't go beyond the available pages ?>
<div class="nextpage"><a
	href="/amazon_store/?<?php print _amazon_store_revise_query(array('ItemPage'=>$nextpage)); ?>">&gt;&gt;Go
to Page <?php print "$nextpage of {$results->TotalPages} pages " ?> of
Results</a></div>
<div class="narrow_by"></div>
		<?php endif; ?></div>

