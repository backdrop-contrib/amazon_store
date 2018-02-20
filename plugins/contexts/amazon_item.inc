<?php
/**
 * @file
 *  Provides the amazon_item context plugin for amazon_store panel
 *
 */

/**
 * @file
 * Layout context handler for entities.
 */
class AmazonItemLayoutContext extends LayoutContext {
  function type() {
    return 'amazon_item';
  }
  function label() {
    return t('Amazon item');
  }
}

