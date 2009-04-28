<?php
/**
 * $Id$
 * @file
 * 	Template for Similar Products Panels plugin
 */


if ($item->SimilarProducts->SimilarProduct): ?>
<div class="SimilarProducts" >
<ul>
<?php foreach ($item->SimilarProducts->SimilarProduct as $sim): ?>
	<li><a href="<?php print url("amazon_store/item/{$sim->ASIN}") ?>"><?php print $sim->Title ?></a></li>

<?php endforeach; ?>
</ul>
</div>
<?php endif; ?>