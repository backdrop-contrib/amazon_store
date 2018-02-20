<?php



/**
 *  ItemTitle extends Block
 */
class ItemTitle extends Block {
  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      return (string) $this->contexts['amazon_item']->data->ItemAttributes->Title;
    }
  }
}


