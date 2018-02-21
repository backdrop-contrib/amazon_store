<?php
/**
 @file
 Provides item description for amazon item

/**
 *  ItemDescription extends Block
 */
class ItemDescription extends Block {
  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      if (!empty($this->contexts['amazon_item']->data->EditorialReviews->EditorialReview[0]->Content)) {
        return _filter_htmlcorrector(filter_xss_admin($this->contexts['amazon_item']->data->EditorialReviews->EditorialReview[0]->Content));
      }
    }
  }
}
