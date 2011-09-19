<?php

/*
 * Global Content form for Extension.
 */
function extension_settings_global_block1() {
  $default_values = variable_get('extension_settings_global_content_1', '');
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
    '#title' => t('Block 1 global content'),
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

/**
 * Form submit logic for the global content clear button.
 */
function extension_settings_global_block1_clear($form, &$form_state) {
  variable_del('extension_settings_global_content_1');
  drupal_set_message('Global content for block 1 has been cleared.');
}

/**
 * Form validation logic for the global content settings.
 */
function extension_settings_global_block1_submit($form, &$form_state) {
  $values['regions'] = $form_state['values']['regions'];
  $values['content'] = $form_state['values']['content'];

  variable_set('extension_settings_global_content_1', $values);
  drupal_set_message('Global content for block 1 has been saved.');
}

function extension_settings_form_extension_settings_global_block1_alter($form, &$form_state, $form_id) {
  $form['buttons']['submit']['#submit'][] = 'extension_settings_global_block1_submit';
  $form['buttons']['submit']['#value'][] = 'extension_settings_global_block1_submit';
  $form['buttons']['reset']['#value'] = 'Clear global content from block 1';
  $form['buttons']['reset']['#submit'][] = 'extension_settings_global_block1_clear';
}