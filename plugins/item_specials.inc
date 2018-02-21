<?php
/**
 * @file
 * Right now this provides nothing more than a link
 * allowing clearing the cache for the context-driven
 * amazon product. For debugging.
 */

/**
 *  ItemSpecials extends Block
 */
class ItemSpecials extends Block {
  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      $query = array('destination' => AMAZON_STORE_PATH . "/item/{$this->contexts['amazon_item']->data->ASIN}");
      $output = "<div>" . l(t("Refresh this page"), AMAZON_STORE_PATH . "/clear_cache/{$this->contexts['amazon_item']->data->ASIN}", array('query' => $query, 'attributes' => array('rel' => 'nofollow'))) . "</div>";
      return $output;
    }
  }
}
