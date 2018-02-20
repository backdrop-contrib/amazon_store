<?php
/**
 @file
 Implements browsenodes content type for amazon_store
 */

/**
 *  ItemBrowseNodes extends Block
 */
class ItemBrowseNodes extends Block {
  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      return theme('amazon_store_browsenodes_panel', array('item' => $this->contexts['amazon_item']->data));
    }
  }
}
