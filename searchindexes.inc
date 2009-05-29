<?php
// $Id$
/**
 @file
	Implement SearchIndexes class
*/

/**
 * @class
 * SearchIndex
 *
 * Allows getting important info about a search index by locale
 * Currently only fitted with US info
 *
 */
class SearchIndexes {
  protected $searchIndexPulldown = array();
  protected $parametersAllowed = array();
  protected $browseNodes = array();
  protected $sorts = array(); // Allowable sorts for each SearchIndex
  // List created by processing docs at http://docs.amazonwebservices.com/AWSECommerceService/latest/DG/USSearchIndexParamForItemsearch.html
  protected $data = array( 'US' => array(
  'All' => array('friendly_name' => 'All',
    'BrowseNode' => 2000,
    'parameters_allowed' => array('Keywords'),
    'sorts' => NULL,
),
'Apparel' => array('friendly_name' => 'Apparel',
  'BrowseNode' => 15683091,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
       'pricerank' => 'Price: low to high',
       'inverseprice' => 'Price: high to low',
       '-launch-date' => 'Newest arrivals',
       'sale-flag' => 'On sale',
),
),
'Automotive' => array('friendly_name' => 'Automotive',
  'BrowseNode' => 15690151,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'Baby' => array('friendly_name' => 'Baby',
  'BrowseNode' => 3760931,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'Title'),
  'sorts' => array(
//       array('psrank' => 'Bestseller ranking taking into consideration projected      sales.The lower the value, the better the sales.'),
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
),
),
'Beauty' => array('friendly_name' => 'Beauty',
  'BrowseNode' => 11055981,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       '-launch-date' => 'Newest arrivals',
       'sale-flag' => 'On sale',
),
),
'Books' => array('friendly_name' => 'Books',
  'BrowseNode' => 1000,
  'parameters_allowed' => array( 'Author', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Power', 'Publisher', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
       'reviewrank' => 'Average customer review: high to low',
       'pricerank' => 'Price: low to high',
       'inverse-pricerank' => 'Price: high to low',
       'daterank' => 'Publication date: newer to older',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'Classical' => array('friendly_name' => 'Classical',
  'BrowseNode' => 301668,
  'parameters_allowed' => array( 'Artist', 'Author', 'Availability', 'BrowseNode', 'Composer', 'Conductor', 'Count', 'Format', 'ItemPage', 'Keywords', 'Magazines', 'MusicLabel', 'Orchestra', 'Performer', 'PostalCode', 'Sort', 'State', 'Title'),
  'sorts' =>  array(
//       array('psrank' => 'Bestseller ranking taking into consideration projected      sales.The lower the value, the better the sales.'),
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
       'orig-rel-date' => 'Release date: newer to older',
       '-orig-rel-date' => 'Release date: older to newer',
       'releasedate' => 'Release date: newer to older',
       '-releasedate' => 'Release date: older to newer',
),
),
'DigitalMusic' => array('friendly_name' => 'Digital Music',
  'BrowseNode' => 301668,
  'parameters_allowed' => array( 'Actor', 'BrowseNode', 'Condition', 'Director', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'Title'),
  'sorts' => array(
       'songtitlerank' => 'Most popular',
       'uploaddaterank' => 'Date added',
),
),

'DVD' => array('friendly_name' => 'DVD',
  'BrowseNode' => 130,
  'parameters_allowed' => array( 'Actor', 'AudienceRating', 'Availability', 'BrowseNode', 'Count', 'Director', 'Format', 'ItemPage', 'Keywords', 'Magazines', 'Performer', 'PostalCode', 'Publisher', 'Sort', 'State', 'Title'),
  'sorts' => array(
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-video-release-date' => 'Release date: newer to older',
       'releasedate' => 'Release date: newer to older',
),
),
'Electronics' => array('friendly_name' => 'Electronics',
  'BrowseNode' => 493964,
  'parameters_allowed' => array( 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'reviewrank' => 'Average customer review: high to low',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
),
),
'GourmetFood' => array('friendly_name' => 'Gourmet Food',
  'BrowseNode' => 3580501,
  'parameters_allowed' => array( 'BrowseNode', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
       'pricerank' => 'Price: low to high',
       'inverseprice' => 'Price: high to low',
       'launch-date' => 'Newest arrivals',
       'sale-flag' => 'On sale',
),
),
'HealthPersonalCare' => array('friendly_name' => 'Health/Personal Care',
  'BrowseNode' => 3760931,
  'parameters_allowed' => array( 'request.', 'Brand', 'BrowseNode', 'Condition', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'ItemPage', 'Keywords', 'Sort', 'State', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'pricerank' => 'Price: low to high',
       'inverseprice' => 'Price: high to low',
       'launch-date' => 'Newest arrivals',
       'sale-flag' => 'On sale',
),
),

'HomeGarden' => array('friendly_name' => 'Home and Garden',
  'BrowseNode' => 1063498,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
  'sorts' => array(
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'Industrial' => array('friendly_name' => 'Industrial',
  'BrowseNode' => 228013,
  'parameters_allowed' => array( 'BrowseNode', 'Keywords', 'Manufacturer', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'Jewelry' => array('friendly_name' => 'Jewelry',
  'BrowseNode' => 3880591,
  'parameters_allowed' => array( 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' =>  array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'pricerank' => 'Price: low to high',
       'inverseprice' => 'Price: high to low',
       'launch-date' => 'Newest arrivals',
),
),
'KindleStore' => array('friendly_name' => 'Kindle Store',
  'parameters_allowed' => array( 'Author', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Power', 'Publisher', 'Sort', 'TextStream', 'Title'),
  'sorts' => array(
       'daterank' => 'Publication date: newer to older',
       '-edition-sales-velocity' => 'Quickest to slowest selling products.',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'relevancerank' =>  'Relevance',
       'reviewrank' => 'Average customer review: high to low',
),
),
'Kitchen' => array('friendly_name' => 'Kitchen',
  'BrowseNode' => 1063498,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'ItemPage', 'Keywords', 'Sort', 'State', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'Magazines' => array('friendly_name' => 'Magazines',
  'BrowseNode' => 44264011,
  'parameters_allowed' => array( 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Publisher', 'State', 'Sort', 'Title'),
  'sorts' => array(
       'subslot-salesrank' => 'Bestselling',
       'reviewrank' => 'Average customer review: high to low',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'daterank' => 'Publication date: newer to older',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'Merchants' => array('friendly_name' => 'Merchants',
  'BrowseNode' => 493964,
  'parameters_allowed' => array( 'Keywords', 'Title', 'BrowseNode', 'Artist', 'Author', 'Actor', 'Director', 'AudienceRating', 'Manufacturer', 'MusicLabel', 'Composer', 'Publisher', 'Brand', 'Conductor', 'City', 'Neighborhood', 'Orchestra', 'TextStream'),
  'sorts' =>  array(
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
       'pricerank' => 'Price: low to high',
       'inverseprice' => 'Price: high to low',
       '-launch-date' => 'Newest arrivals',
       'sale-flag' => 'On sale',
),
),
'Miscellaneous' => array('friendly_name' => 'Miscellaneous',
  'BrowseNode' => 349028011,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),

),
'MP3Downloads' => array('friendly_name' => 'MP3 Downloads',

  'parameters_allowed' => array( 'Browsenode', 'Keyword', 'Title'),
  'sorts' => array(
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       '-releasedate' => 'Release date',
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
),
),
'Music' => array('friendly_name' => 'Music',
  'BrowseNode' => 301668,
  'parameters_allowed' => array( 'Artist', 'Availability', 'BrowseNode', 'Count', 'Format', 'ItemPage', 'Keywords', 'Magazines', 'MusicLabel', 'Performer', 'PostalCode', 'Sort', 'State', 'Title'),
  'sorts' => array(
//       array('psrank' => 'Bestseller ranking taking into consideration projected      sales.The lower the value, the better the sales.'),
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
       'artistrank' => 'Artist name: A to Z',
       'orig-rel-date' => 'Original Release Date',
       'release-date' => 'Latest Release Date',
       'releasedate' => 'Release date: most recent to oldest',
       '-releasedate' => 'Release date: oldest to most recent',
       'relevancerank' =>  'Relevance',
),

),
'MusicalInstruments' => array('friendly_name' => 'Musical Instruments',
  'BrowseNode' => 12923151,
  'parameters_allowed' => array( 'request.', 'Brand', 'BrowseNode', 'Condition', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'ItemPage', 'Keywords', 'Sort', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       '-launch-date' => 'Newest arrivals',
       'sale-flag' => 'On sale',
),
),
'MusicTracks' => array('friendly_name' => 'Music Tracks',
  'parameters_allowed' => array( 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State'),
  'sorts' => array(
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),

),
'OfficeProducts' => array('friendly_name' => 'Office Products',
  'BrowseNode' => 1084128,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'ItemPage', 'Keywords', 'Sort', 'State', 'Title'),
  'sorts' =>  array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'reviewrank' => 'Average customer review: high to low',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
),
),
'OutdoorLiving' => array('friendly_name' => 'Outdoor Living',
  'BrowseNode' => 1063498,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'ItemPage', 'Keywords', 'Sort', 'State', 'Title'),
  'sorts' => array(
//       array('psrank' => 'Bestseller ranking taking into consideration projected      sales.The lower the value, the better the sales.'),
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'PCHardware' => array('friendly_name' => 'PC Hardware',
  'BrowseNode' => 493964,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'ItemPage', 'Keywords', 'Sort', 'State', 'Title'),
  'sorts' => array(
// //       array('psrank' => 'Bestseller ranking taking into consideration projected      sales.The lower the value, the better the sales.'),
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
),
),
'PetSupplies' => array('friendly_name' => 'Pet Supplies',
  'BrowseNode' => 13900811,
  'parameters_allowed' => array( 'Author', 'Brand', 'BrowseNode', 'Condition', 'Count', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'Title'),
  'sorts' => array(
       '+pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'Photo' => array('friendly_name' => 'Photo',
  'BrowseNode' => 13900861,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'ItemPage', 'Keywords', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'Shoes' => array('friendly_name' => 'Shoes',
  'BrowseNode' => 3375301,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       '-launch-date' => 'Newest arrivals',
       'pmrank' => 'Featured items',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'xsrelevancerank' => 'Relevance',
       'reviewrank' => 'Average customer review: high to low',
),

),
'SilverMerchants' => array('friendly_name' => 'Silver Merchants',
  'parameters_allowed' => array( 'Keywords', 'Title', 'BrowseNode', 'Artist', 'Author', 'Actor', 'Director', 'AudienceRating', 'Manufacturer', 'MusicLabel', 'Composer', 'Publisher', 'Brand', 'Conductor', 'City', 'Neighborhood', 'Orchestra', 'TextStream'),
  'sorts' => array(
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
       'pricerank' => 'Price: low to high',
       'inverseprice' => 'Price: high to low',
       '-launch-date' => 'Newest arrivals',
       'sale-flag' => 'On sale',
), ),
'Software' => array('friendly_name' => 'Software',
  'BrowseNode' => 409488,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'ItemPage', 'Keywords', 'Sort', 'State', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
),
),
'SportingGoods' => array('friendly_name' => 'Sporting Goods',
  'BrowseNode' => 1036682,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'Title'),
  'sorts' => array(
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
       'pricerank' => 'Price: low to high',
       'inverseprice' => 'Price: high to low',
       'launch-date' => 'Newest arrivals',
       'sale-flag' => 'On sale',
),
),
'Tools' => array('friendly_name' => 'Tools',
  'BrowseNode' => 228013,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'Toys' => array('friendly_name' => 'Toys',
  'BrowseNode' => 130,
  'parameters_allowed' => array( 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-age-min' => 'Age: high to low',
),
),
'UnboxVideo' => array('friendly_name' => 'Unboxed Video',
  'parameters_allowed' => array( 'Actor', 'BrowseNode', 'Condition', 'Director', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'MPAARating', 'Publisher', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-video-release-date' => 'Release date: newer to older',
),
),
'VHS' => array('friendly_name' => 'VHS',
  'BrowseNode' => 404272,
  'parameters_allowed' => array( 'Actor', 'AudienceRating', 'Availability', 'BrowseNode', 'Count', 'Director', 'Format', 'ItemPage', 'Keywords', 'Magazines', 'Performer', 'PostalCode', 'Publisher', 'Sort', 'State', 'Title'),
  'sorts' =>  array(
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-video-release-date' => 'Release date: newer to older',
       '-releasedate' => 'Release date: newer to older',
),
),
'Video' => array('friendly_name' => 'Video',
  'BrowseNode' => 130,
  'parameters_allowed' => array( 'Actor', 'AudienceRating', 'Availability', 'BrowseNode', 'Count', 'Director', 'Format', 'ItemPage', 'Keywords', 'Magazines', 'Performer', 'PostalCode', 'Publisher', 'Sort', 'State', 'Title'),
  'sorts' => array(
       'relevancerank' =>  'Relevance',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
       '-video-release-date' => 'Release date: newer to older',
       '-releasedate' => 'Release date: newer to older',
),
),
'VideoGames' => array('friendly_name' => 'Video Games',
  'BrowseNode' => 44263011,
  'parameters_allowed' => array( 'Brand', 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'Manufacturer', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       'pmrank' => 'Featured items',
       'salesrank' => 'Bestselling',
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'titlerank' => 'Alphabetical: A to Z',
),
),
'Watches' => array('friendly_name' => 'Watches',
  'BrowseNode' => 378516011,
  'parameters_allowed' => array( 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'TextStream', 'Title'),
  'sorts' => array(
       'price' => 'Price: low to high',
       '-price' => 'Price: high to low',
       'relevancerank' =>  'Relevance',
       'reviewrank' => 'Average customer review: high to low',
       'salesrank' => 'Bestselling to worst selling',
),
),
'Wireless' => array('friendly_name' => 'Wireless',
  'BrowseNode' => 408234,
  'parameters_allowed' => array( 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'State', 'Title'),
  'sorts' => array(
       'daterank' => 'Publication date: newer to older',
       'pricerank' => 'Price: low to high',
       'inverse-pricerank' => 'Price: high to low',
       'reviewrank' => 'Average customer review: high to low',
       'salesrank' => 'Bestselling',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),
'WirelessAccessories' => array('friendly_name' => 'Wireless Accessories',
  'BrowseNode' => 408234,
  'parameters_allowed' => array( 'BrowseNode', 'Condition', 'ItemPage', 'Keywords', 'MaximumPrice', 'MerchantId', 'MinimumPrice', 'Sort', 'Title'),
  'sorts' => array(
//       array('psrank' => 'Bestseller ranking taking into consideration projected      sales.The lower the value, the better the sales.'),
       'salesrank' => 'Bestselling',
       'titlerank' => 'Alphabetical: A to Z',
       '-titlerank' => 'Alphabetical: Z to A',
),
),

  ),
  );

  /**
   *
   * @param $locale
   * 	Locale ("US") in the Amazon scheme of Locale
   * @return unknown_type
   */
  function __construct($locale) {
    if (!empty($this->data[$locale])) {
      $error_level = error_reporting(0);
      foreach ($this->data[$locale] as $index => $item) {
        if (!empty($item['friendly_name'])) {
          $this->searchIndexPulldown[$index] = $item['friendly_name'];
          $this->parametersAllowed[$index] = $item['parameters_allowed'];
          $this->browseNodes[$index] = $item['BrowseNode'];
          $this->sorts[$index] = $item['sorts'];
        }
      }
      error_reporting($error_level);

    }
  }
  function getBrowseNodes() {
    return $this->browseNodes;
  }
  function getParametersAllowed() {
    return $this->parametersAllowed();
  }
  function getSearchIndexPulldown($exclude_all_searchindex=FALSE) {
    $rv = $this->searchIndexPulldown;
    if ($exclude_all_searchindex == TRUE) {
      unset($rv['All']);
    }
    return $rv;
  }
  function getSorts($searchIndex) {
    return $this->sorts;
  }
  function getSortPossiblities($searchIndex) {
    return $this->sorts[$searchIndex];
  }
}



