<?php
// $Id$
/**
 * @file
 *   template for item_reviews panel
 */

if ($item->CustomerReviews->Review) {
  $rounded_avg = round($item->CustomerReviews->AverageRating);

?>
<p><strong>Average Amazon User Rating:</strong>
  <?php print theme('image', "$directory/images/{$rounded_avg}stars.gif","{$item->CustomerReviews->AverageRating} stars", "{$item->CustomerReviews->AverageRating} stars"); ?>
  
<?php
  foreach ($item->CustomerReviews->Review as $review) {

    $rounded_stars = round($review->Rating);
    ?>
<div class="customer_review">
<p>
  <?php print theme('image', "$directory/images/{$rounded_stars}stars.gif","{$review->Rating} stars", "{$review->Rating} stars"); ?>
	<strong> <?php print $review->Summary ?></strong>
	<?php print $review->Date ?></p>
<p>Reviewer: <strong><?php print $review->Reviewer->Name ?></strong></p>

<p><?php print $review->Content ?></p>
</div>
<?php

  }
}
