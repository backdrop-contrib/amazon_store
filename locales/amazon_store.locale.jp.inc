<?php


function _amazon_store_locale() {

  $locale = array(
    'JP' => array(
      'All' => array(
        'friendly_name' => t('All'),
        'BrowseNode' => 2000,
        'parameters_allowed' => array('Keywords'),
        'sorts' => NULL,
      ),
      'Apparel' => array(
        'friendly_name' => t('Apparel'),
        'BrowseNode' => 361299011,
        'parameters_allowed' => array('Author', 'Availability', 'Brand', 'BrowseNode', 'Condition', 'Count', 'DeliveryMethod', 'Format', 'ISPUPostalCode', 'ItemPage', 'Keywords', 'Magazines', 'Manufacturer', 'MerchantId', 'Performer', 'PostalCode', 'Sort', 'State', 'Title'),
        'sorts' => array(
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'relevancerank' => t('Relevance'),
          'salesrank' => t('Bestselling to worst selling'),
        ),
      ),
      'Baby' => array(
        'friendly_name' => t('Baby'),
        'BrowseNode' => 13331821,
        'parameters_allowed' => array('Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'Title'),
        'sorts' => array(
          //       'psrank' => t('Bestseller ranking taking into consideration projected sales.The lower the value, the better the sales.')),
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
        ),
      ),
      'Beauty' => array(
        'friendly_name' => t('Beauty'),
        'BrowseNode' => 52391051,
        'parameters_allowed' => array('Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
        'sorts' => array(
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'relevancerank' => t('Relevance'),
          'reviewrank' => t('Average customer review: high to low'),
        ),
      ),
      'Books' => array(
        'friendly_name' => t('Books'),
        'BrowseNode' => 465610,
        'parameters_allowed' => array('Author', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Power', 'Publisher', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'pricerank' => t('Price: low to high'),
          'inverse-pricerank' => t('Price: high to low'),
          'daterank' => t('Publication date: newer to older'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
        ),
      ),
      'Classical' => array(
        'friendly_name' => t('Classical'),
        'BrowseNode' => 562032,
        'parameters_allowed' => array('Actor', 'Availability', 'BrowseNode', 'Composer', 'Conductor', 'Count', 'Format', 'ItemPage', 'Keywords', 'Magazines', 'MusicLabel', 'Orchestra', 'Performer', 'PostalCode', 'Sort', 'State', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'pricerank' => t('Price: low to high'),
          '-pricerank' => t('Price: high to low'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          '-orig-rel-date' => t('Release date: newer to older'),
          'orig-rel-date' => t('Release date: older to newer'),
          'releasedate' => t('Release date: newer to older'),
          '-releasedate' => t('Release date: older to newer'),
        ),
      ),
      'DVD' => array(
        'friendly_name' => t('DVD'),
        'BrowseNode' => 562002,
        'parameters_allowed' => array('Actor', 'AudienceRating', 'Availability', 'BrowseNode', 'Count', 'Director', 'Format', 'ItemPage', 'Keywords', 'Magazines', 'Performer', 'PostalCode', 'Publisher', 'Sort', 'State', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'pricerank' => t('Price: low to high'),
          '-pricerank' => t('Price: high to low'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          '-orig-rel-date' => t('Release date: newer to older'),
          'orig-rel-date' => t('Release date: older to newer'),
          'releasedate' => t('Release date: older to newer'),
          '-releasedate' => t('Release date: newer to older'),
        ),
      ),
      'Electronics' => array(
        'friendly_name' => t('Electronics'),
        'BrowseNode' => 3210991,
        'parameters_allowed' => array('BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          '-releasedate' => t('Release date: newer to older'),
          'releasedate' => t('Release date: older to newer'),
        ),
      ),
      'ForeignBooks' => array(
        'friendly_name' => t('Foreign Books'),
        'BrowseNode' => 388316011,
        'parameters_allowed' => array('Author', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Publisher', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'pricerank' => t('Price: low to high'),
          'inverse-pricerank' => t('Price: high to low'),
          'daterank' => t('Publication date: newer to older'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
        ),
      ),
      'Grocery' => array(
        'friendly_name' => t('Grocery'),
        'BrowseNode' => 57240051,
        'parameters_allowed' => array('Brand', 'BrowseNode', 'Condition', 'Count', 'ItemPage', 'Keywords', 'MaximumPrice', 'MinimumPrice', 'Manufacturer', 'MerchantId', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'reviewrank' => t('Average customer review: high to low'),
        ),
      ),
      'HealthPersonalCare' => array(
        'friendly_name' => t('Health Personal Care'),
        'BrowseNode' => 161669011,
        'parameters_allowed' => array('BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
        ),
      ),
      'Hobbies' => array(
        'friendly_name' => t('Hobbies'),
        'BrowseNode' => 13331821,
        'parameters_allowed' => array('BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          'release-date' => t('Release date: older to newer'),
          '-release-date' => t('Release date: newer to older'),
          'mfg-age-min' => t('Minimum age of user sorted from youngest to oldest'),
          '-mfg-age-min' => t('Minimum age of user sorted from oldest to youngest'),
        ),
      ),
      'Jewelry' => array(
        'friendly_name' => t('Jewelry'),
        'BrowseNode' => 85896051,
        'parameters_allowed' => array('Availability', 'BrowseNode', 'DeliveryMethod', 'Keywords', 'MerchantId', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'relevancerank' => t('Relevance'),
          'reviewrank' => t('Average customer review: high to low'),
        ),
      ),
      'Kitchen' => array(
        'friendly_name' => t(''),
        'BrowseNode' => 3839151,
        'parameters_allowed' => array('Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          '-release-date' => t('Release date: newer to older'),
          'release-date' => t('Release date: older to newer'),
          'releasedate' => t('Release date: older to newer'),
          '-releasedate' => t('Release date: newer to older'),
        ),
      ),
      'Music' => array(
        'friendly_name' => t('Music'),
        'BrowseNode' => 562032,
        'parameters_allowed' => array('Artist', 'Availability', 'BrowseNode', 'Count', 'Format', 'ItemPage', 'Keywords', 'Magazines', 'MusicLabel', 'Performer', 'PostalCode', 'Sort', 'State', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'pricerank' => t('Price: low to high'),
          '-pricerank' => t('Price: high to low'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          '-orig-rel-date' => t('Release date: newer to older'),
          'orig-rel-date' => t('Release date: older to newer'),
          'releasedate' => t('Release date: older to newer'),
          '-releasedate' => t('Release date: newer to older'),
        ),
      ),
      'Software' => array(
        'friendly_name' => t('Software'),
        'BrowseNode' => 637630,
        'parameters_allowed' => array('Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          '-release-date' => t('Release date: newer to older'),
          'release-date' => t('Release date: older to newer'),
          'releasedate' => t('Release date: older to newer'),
          '-releasedate' => t('Release date: newer to older'),
        ),
      ),
      'SportingGoods' => array(
        'friendly_name' => t('Sporting Goods'),
        'BrowseNode' => 14315361,
        'parameters_allowed' => array('BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          'releasedate' => t('Release date: older to newer'),
          '-releasedate' => t('Release date: newer to older'),
        ),
      ),
      'Toys' => array(
        'friendly_name' => t('Toys'),
        'BrowseNode' => 13331821,
        'parameters_allowed' => array('BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          '-release-date' => t('Release date: newer to older'),
          'release-date' => t('Release date: older to newer'),
          'releasedate' => t('Release date: older to newer'),
          '-releasedate' => t('Release date: newer to older'),
        ),
      ),
      'VHS' => array(
        'friendly_name' => t('VHS'),
        'BrowseNode' => 561972,
        'parameters_allowed' => array('Actor', 'AudienceRating', 'Availability', 'BrowseNode', 'Count', 'Director', 'Format', 'ItemPage', 'Keywords', 'Magazines', 'Performer', 'PostalCode', 'Publisher', 'Sort', 'State', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'pricerank' => t('Price: low to high'),
          '-pricerank' => t('Price: high to low'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          '-orig-rel-date' => t('Release date: newer to older'),
          'orig-rel-date' => t('Release date: older to newer'),
          'releasedate' => t('Release date: older to newer'),
          '-releasedate' => t('Release date: newer to older'),
        ),
      ),
      'Video' => array(
        'friendly_name' => t('Video'),
        'BrowseNode' => 561972,
        'parameters_allowed' => array('Actor', 'AudienceRating', 'Availability', 'BrowseNode', 'Count', 'Director', 'Format', 'ItemPage', 'Keywords', 'Magazines', 'Performer', 'PostalCode', 'Publisher', 'Sort', 'State', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'pricerank' => t('Price: low to high'),
          '-pricerank' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          '-orig-rel-date' => t('Release date: newer to older'),
          'orig-rel-date' => t('Release date: older to newer'),
          'releasedate' => t('Release date: older to newer'),
          '-releasedate' => t('Release date: newer to older'),
        ),
      ),
      'VideoGames' => array(
        'friendly_name' => t('Video Games'),
        'BrowseNode' => 637872,
        'parameters_allowed' => array('Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
          '-release-date' => t('Release date: newer to older'),
          'release-date' => t('Release date: older to newer'),
          'releasedate' => t('Release date: older to newer'),
          '-releasedate' => t('Release date: newer to older'),
        ),
      ),
      'Watches' => array(
        'friendly_name' => t('Watches'),
        'BrowseNode' => 14315361,
        'parameters_allowed' => array('BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'TextStream', 'Title'),
        'sorts' => array(
          'salesrank' => t('Bestselling'),
          'price' => t('Price: low to high'),
          '-price' => t('Price: high to low'),
          'titlerank' => t('Alphabetical: A to Z'),
          '-titlerank' => t('Alphabetical: Z to A'),
        ),
      ),
    ),
  );
  return $locale;
}
