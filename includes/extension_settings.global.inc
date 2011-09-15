<?php

/*
 * Global Content form for Extension.
 */
function extension_settings_global_content() {
  $form['global_content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Global content'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );
  
  $form['global_content']['select_region'] = array(
    '#type' => 'radios',
    '#title' => t('Region'),
    '#default_value' => variable_get('extension_settings_whole_state', '0'), 
    '#options' => array(
      '0' => t('Entire State'),
      '1' => t('Selected Regions')
    ),
    '#description' => t('Select if content is pushed to the whole state.'),
    '#required' => TRUE
    );
    
  $form['global_content']['regions'] = array(
    '#type' => 'checkboxes', 
    '#title' => t(''), 
    '#default_value' => variable_get('extension_settings_regions', ''), 
    '#options' => array(
      '1' => 'Region 1',
      '2' => 'Region 2',
      '3' => 'Region 3',
      '4' => 'Region 4',
      '5' => 'Region 5',
      '6' => 'Region 6',
    ), 
    '#description' => t('Select regions to push content to.'),
  );

  $form['global_content']['content'] = array(
    '#type' => 'textarea',
    '#title' => t('Content'),
    '#description' => t('Enter the content to push to sites. (full HTML)'),
    '#default_value' => variable_get('extension_settings_content', ''),
    '#required' => TRUE
  );
  return system_settings_form($form);
}

/**
 * Form validation logic for the config settings.
 */
function extension_settings_global_content_validate($form, &$form_state) {
  if ($form_state['values']['select_region'] == 1) {
    if($form_state['values']['regions']['1'] == 0 && $form_state['values']['regions']['2'] == 0 && $form_state['values']['regions']['3'] == 0 && $form_state['values']['regions']['4'] == 0 && $form_state['values']['regions']['5'] == 0 && $form_state['values']['regions']['6'] == 0) {
      form_set_error('', t('Please select at least one region.'));
    }
  }
}