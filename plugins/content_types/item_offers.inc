<?php
/**
 @file
 Item_offers content_type ctools plugin
 */

/**
 *  ItemOffers extends Block
 */
class ItemOffers extends Block {
  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      return theme('amazon_store_item_offers', array('amazon_item' => $this->contexts['amazon_item']->data));
    }
  }
}
