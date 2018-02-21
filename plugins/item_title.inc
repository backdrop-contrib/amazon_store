<?php



/**
 *  ItemTitle extends Block
 */
class ItemTitle extends Block {

  /**
   *  Builds the block's configuration form.
   */
  function form(&$form, &$form_state) {
    parent::form($form, $form_state);

    $form['title_tag'] = array(
      '#title' => t('Heading level'),
      '#type' => 'select',
      '#options' => array(
        'h1' => 'H1',
        'h2' => 'H2',
        'h3' => 'H3',
        'h4' => 'H4',
        'h5' => 'H5',
        'h6' => 'H6',
        'div' => 'DIV',
        'p' => 'P',
      ),
      '#default_value' => $this->settings['title_tag'],
      '#weight' => 2,
    );
    $form['title_class'] = array(
      '#title' => t('Title classes'),
      '#description' => t('Classes to be added to the title tag, separated by spaces.'),
      '#type' => 'textfield',
      '#default_value' => $this->settings['title_class'],
      '#weight' => 3,
    );
  }

  /**
   * Submit handler to save the form settings.
   */
  function formSubmit($form, &$form_state) {
    parent::formSubmit($form, $form_state);

    $this->settings['title_tag'] = $form_state['values']['title_tag'];
    $this->settings['title_class'] = $form_state['values']['title_class'];
  }

  /**
   * Returns the rendered content of this block.
   *
   * @return string
   */
  function getContent() {
    if (!empty($this->contexts['amazon_item']->data)) {
      $title = (string) $this->contexts['amazon_item']->data->ItemAttributes->Title;
      $tag = isset($this->settings['title_tag']) ? $this->settings['title_tag'] : 'DIV';
      $classes = !empty($this->settings['title_class']) ? ' class="' . $this->settings['title_class'] . '"' : '';
      return '<' . $tag . $classes . '>' . $title . '</' . $tag . '>';
    }
  }
}


