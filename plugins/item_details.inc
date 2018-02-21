<?php


/**
 * Callback function to supply a list of content types.
 */

/**
 *  ItemDetails extends Block
 */
class ItemDetails extends Block {
  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      return theme('amazon_store_details_block', array('item' => $this->contexts['amazon_item']->data));
    }
  }
}
