<?php
// $Id$
/**
 * @file Default panels for amazon_store
 *
 * Implementation of hook_default_panel_pages()
 * To offer a default panel for the item detail page
 * @return unknown_type
 */
function amazon_store_default_panel_pages() {

  $page = new stdClass();
  $page->pid = 'new';
  $page->did = 'new';
  $page->name = 'amazon_item';
  $page->title = 'Amazon Item';
  $page->access = array();
  $page->path = 'amazon_store/item/%';
  $page->load_flags = 1;
  $page->css_id = '';
  $page->arguments = array(
  0 =>
  array(
      'name' => 'asin',
      'id' => 1,
      'default' => 'ignore',
      'title' => '%amazon_item',
      'identifier' => 'ASIN',
      'keyword' => 'amazon_item',
  ),
  );
  $page->relationships = array();
  $page->no_blocks = '0';
  $page->switcher_options = array();
  $page->menu = '0';
  $page->contexts = array();
  $display = new panels_display();
  $display->did = 'new';
  $display->layout = 'twocol_stacked';
  $display->layout_settings = NULL;
  $display->panel_settings = array(
  'style' => 'rounded_corners',
  'style_settings' =>
  array(
  ),
  'individual' => 0,
  'panel' =>
  array(
    'top' =>
  array(
      'style' => -1,
  ),
    'left' =>
  array(
      'style' => -1,
  ),
    'right' =>
  array(
      'style' => -1,
  ),
    'bottom' =>
  array(
      'style' => -1,
  ),
  ),
  );
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1';
  $pane->panel = 'bottom';
  $pane->type = 'item_reviews';
  $pane->shown = '1';
  $pane->subtype = 'description';
  $pane->access = array();
  $pane->configuration = array(
      'context' => 'argument_asin_1',
      'style' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
      'css_id' => '',
      'css_class' => '',
      'template_file' => '',
  );
  $pane->cache = array();
  $display->content['new-1'] = $pane;
  $display->panels['bottom'][0] = 'new-1';
  $pane = new stdClass();
  $pane->pid = 'new-2';
  $pane->panel = 'left';
  $pane->type = 'item_description';
  $pane->shown = '1';
  $pane->subtype = 'description';
  $pane->access = array();
  $pane->configuration = array(
      'context' => 'argument_asin_1',
      'style' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
      'css_id' => '',
      'css_class' => '',
  );
  $pane->cache = array();
  $display->content['new-2'] = $pane;
  $display->panels['left'][0] = 'new-2';
  $pane = new stdClass();
  $pane->pid = 'new-3';
  $pane->panel = 'left';
  $pane->type = 'item_details';
  $pane->shown = '1';
  $pane->subtype = 'description';
  $pane->access = array();
  $pane->configuration = array(
      'context' => 'argument_asin_1',
      'style' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
      'css_id' => '',
      'css_class' => '',
  );
  $pane->cache = array();
  $display->content['new-3'] = $pane;
  $display->panels['left'][1] = 'new-3';
  $pane = new stdClass();
  $pane->pid = 'new-4';
  $pane->panel = 'right';
  $pane->type = 'item_image';
  $pane->shown = '1';
  $pane->subtype = 'description';
  $pane->access = array();
  $pane->configuration = array(
      'context' => 'argument_asin_1',
      'style' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
      'css_id' => '',
      'css_class' => '',
      'size_selection' => 'MediumImage',
  );
  $pane->cache = array();
  $display->content['new-4'] = $pane;
  $display->panels['right'][0] = 'new-4';
  $pane = new stdClass();
  $pane->pid = 'new-5';
  $pane->panel = 'right';
  $pane->type = 'item_offers';
  $pane->shown = '1';
  $pane->subtype = 'description';
  $pane->access = array();
  $pane->configuration = array(
      'context' => 'argument_asin_1',
      'style' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
      'css_id' => '',
      'css_class' => '',
      'template_file' => '',
  );
  $pane->cache = array();
  $display->content['new-5'] = $pane;
  $display->panels['right'][1] = 'new-5';
  $pane = new stdClass();
  $pane->pid = 'new-6';
  $pane->panel = 'right';
  $pane->type = 'item_similar_items';
  $pane->shown = '1';
  $pane->subtype = 'description';
  $pane->access = array();
  $pane->configuration = array(
      'context' => 'argument_asin_1',
      'style' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
      'css_id' => '',
      'css_class' => '',
  );
  $pane->cache = array();
  $display->content['new-6'] = $pane;
  $display->panels['right'][2] = 'new-6';
  $page->display = $display;
  $page->displays = array();

  $pages['amazon_store_item_panel'] = $page;
  return $pages;
}