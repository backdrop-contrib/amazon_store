<?php
/**
 @file
 Similar items block plugin for amazon_store
 */

/**
 *  ItemSimilarItems extends Block
 */
class ItemSimilarItems extends Block {
  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      return theme('amazon_store_similar_items_panel', array('item' => $context->data));
    }
  }
}
