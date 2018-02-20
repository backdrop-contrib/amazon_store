<?php
/**
 @file
 item_reviews block plugin for amazon_store
 */

/**
 *  ItemReviews extends Block
 */
class ItemReviews extends Block {
  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      return theme('amazon_store_item_reviews_panel', array('item' => $this->contexts['amazon_item']->data));
    }
  }
}

