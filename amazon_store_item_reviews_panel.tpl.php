<?php
// $Id$
/**
 * @file
 *   template for item_reviews panel
 */

if ($item->CustomerReviews->Review) {
  $rounded_avg = round($item->CustomerReviews->AverageRating);

?>
<p><strong>Average Amazon User Rating:</strong> <img width="56"
	height="11"
	alt="Average rating: <?php print $item->CustomerReviews->AverageRating ?> stars"
	src="<?php print "$directory/images/{$rounded_avg}stars.gif" ?>" /></p>

<?php
  foreach ($item->CustomerReviews->Review as $review) {

    $rounded_stars = round($review->Rating);
    ?>
<div class="customer_review">
<p><img width="56" height="11"
	alt="<?php print $review->Rating ?> stars"
	src="<?php print "$directory/images/{$rounded_stars}stars.gif" ?>" />
	<strong> <?php print $review->Summary ?></strong>
	<?php print $review->Date ?></p>
<p>Reviewer: <strong><?php print $review->Reviewer->Name ?></strong></p>

<p><?php print $review->Content ?></p>
</div>
<?php

  }
}
