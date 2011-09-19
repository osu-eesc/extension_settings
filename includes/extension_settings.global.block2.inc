<?php

/*
 * Global Content form for Extension.
 */
function extension_settings_global_block2() {
  $default_values = variable_get('extension_settings_global_content_2', '');
  if ($default_values == '') {
    $default_values['regions']['1'] = '1';
    $default_values['regions']['2'] = '2';
    $default_values['regions']['3'] = '3';
    $default_values['regions']['4'] = '4';
    $default_values['regions']['5'] = '5';
    $default_values['regions']['6'] = '6';
    $default_values['content'] = '';
  }
  
  $form['global_content'] = array(
    '#type' => 'fieldset',
    '#title' => t('block 2 global content'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );
  
  $form['global_content']['regions'] = array(
    '#type' => 'checkboxes', 
    '#title' => t('Regions'), 
    '#default_value' => $default_values['regions'], 
    '#options' => array(
      '1' => '<span class="checkbox-label">North West</span>',
      '2' => '<span class="checkbox-label">North Central</span>',
      '3' => '<span class="checkbox-label">North East</span>',
      '4' => '<span class="checkbox-label">South West</span>',
      '5' => '<span class="checkbox-label">South Central</span>',
      '6' => '<span class="checkbox-label">South East</span>',
    ), 
    '#description' => t('Select regions to push content to.'),
    '#required' => TRUE,
  );

  $form['global_content']['content'] = array(
    '#type' => 'textarea',
    '#title' => t('Content'),
    '#description' => t('Enter the content to push to sites. (full HTML)'),
    '#default_value' => $default_values['content'],
    '#required' => TRUE
  );
  
 return system_settings_form($form);
}

function extension_settings_form_extension_settings_global_block2_alter(&$form, &$form_state, $form_id) {
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('extension_settings_global_block2_submit'),
    '#value' => t('Save Configuration'),
  );
  $form['actions']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Clear global content from block 2'),
    '#submit' => array('extension_settings_global_block2_clear'),
  );
}

/**
 * Form validation logic for the global content settings.
 */
function extension_settings_global_block2_submit($form, &$form_state) {
  $values['regions'] = $form_state['values']['regions'];
  $values['content'] = $form_state['values']['content'];

  variable_set('extension_settings_global_content_2', $values);
  drupal_set_message('Global content for block 2 has been saved.');
}

/**
 * Form submit logic for the global content clear button.
 */
function extension_settings_global_block2_clear($form, &$form_state) {
  variable_del('extension_settings_global_content_2');
  drupal_set_message('Global content for block 2 has been cleared.');
}