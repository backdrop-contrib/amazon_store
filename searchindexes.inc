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
  protected $allCategories = array();   // All categories.
  protected $recommendedCategories = array();  // Categories which will be on by default.
  protected $parametersAllowed = array();
  protected $browseNodes = array();
  protected $sorts = array(); // Allowable sorts for each SearchIndex
  protected $data = array();

  /**
   *
   * @param $locale
   * 	 The Amazon.com locale ("US", "UK", "JP", etc.).
   * @return unknown_type
   */
  function __construct($locale) {
    include_once(strtolower("locales/amazon_store.locale.$locale.inc"));
    $this->data = amazon_store_locale();

    if (!empty($this->data[$locale])) {
      foreach ($this->data[$locale] as $index => $item) {
        if (!empty($item['friendly_name'])) {
          $this->allCategories[$index] = $item['friendly_name'];
          $this->searchIndexPulldown[$index] = $item['friendly_name'];
          $this->parametersAllowed[$index] = $item['parameters_allowed'];
          $this->browseNodes[$index] = !empty($item['BrowseNode']) ? $item['BrowseNode'] : NULL;
          $this->sorts[$index] = $item['sorts'];
          if (empty($item['exclude_default'])) {
            $this->recommendedCategories[] = $index;
          }
        }
      }
    }
  }
  function getBrowseNodes() {
    return $this->browseNodes;
  }
  function getParametersAllowed() {
    return $this->parametersAllowed();
  }
  function getSearchIndexPulldown($exclude_all_searchindex=FALSE) {
    $rv = variable_get('amazon_store_include_categories', $GLOBALS['amazon_store_search_indexes']->getRecommendedCategories());
    $rv = array_filter($rv);
    if (!$exclude_all_searchindex) {
      $rv = array('All' => 'All') + $rv;
    }
    return $rv;
  }
  function getSorts($searchIndex) {
    return $this->sorts;
  }
  /**
   * Returns the possible sorts for this searchIndex.
   * @param $searchIndex
   * @return unknown_type
   */
  function getSortPossiblities($searchIndex) {
    return $this->sorts[$searchIndex];
  }
  /**
   * Return the full category list for this locale.
   */
  function getAllCategories() {
    return $this->allCategories;
  }

  /**
   * Return static array of values of recommended categories to enable.
   */
  function getRecommendedCategories() {
    return $this->recommendedCategories;
  }
}



