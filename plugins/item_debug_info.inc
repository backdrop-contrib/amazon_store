<?php
/**
 * @file
 * Debugging info block plugin for amazon_store
 */

/**
 *  ItemDebugInfo extends Block
 */
class ItemDebugInfo extends Block {
  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      $output = "<div id='debug_info'  >
      <div class='item_xml toggle'><pre>" . print_r($this->contexts['amazon_item']->data, TRUE) . "</pre>
      </div>
      </div>";
      return $output;
    }
  }
}

