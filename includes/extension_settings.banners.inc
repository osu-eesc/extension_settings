<?php

/*
 * Global Content form for Extension.
 */
function extension_settings_banners() {
  $default_values = variable_get('extension_settings_banners', '');
  if ($default_values == '') {
    $default_values['1']['display'] = 0;
    $default_values['1']['weight'] = 0;
    $default_values['2']['display'] = 0;
    $default_values['2']['weight'] = 0;
    $default_values['3']['display'] = 0;
    $default_values['3']['weight'] = 0;
  }

  $form = array(
    '#type' => 'fieldset',
    '#title' => t('Banners'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );
  $form['1'] = array();
  $form['1']['display1'] = array(
    '#type' => 'checkbox',
    '#title' => t(''),
    '#default_value' => $default_values['1']['display'],
    '#attributes' => array(
    ),
  );
  $form['1']['banner1'] = array(
    '#value' => '<div><img src="' . base_path() . drupal_get_path('module', 'extension_settings') .'/images/gfx_ico_snake.png" /></div>',
  );
  $form['1']['weight1'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => $default_values['1']['weight'],
    '#description' => t(''),
    '#attributes' => array(
      'class' => 'weight',
    ),
  );
  $form['2'] = array();
  $form['2']['display2'] = array(
    '#type' => 'checkbox',
    '#title' => t(''),
    '#default_value' => $default_values['2']['display'],
    '#attributes' => array(
    ),
  );
  $form['2']['banner2'] = array(
    '#value' => '<div><img src="' . base_path() . drupal_get_path('module', 'extension_settings') .'/images/gfx_ico_spade.png" /></div>',
  );
  $form['2']['weight2'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => $default_values['2']['weight'],
    '#description' => t(''),
    '#attributes' => array(
      'class' => 'weight',
    ),
  );
  $form['3'] = array();
  $form['3']['display3'] = array(
    '#type' => 'checkbox',
    '#title' => t(''),
    '#default_value' => $default_values['3']['display'],
    '#attributes' => array(
    ),
  );
  $form['3']['banner3'] = array(
    '#value' => '<div><img src="' . base_path() . drupal_get_path('module', 'extension_settings') .'/images/gfx_ico_pot.png" /></div>',
  );
  $form['3']['weight3'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => $default_values['3']['weight'],
    '#description' => t(''),
    '#attributes' => array(
      'class' => 'weight',
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}

/**
 * Form submit logic for the global content clear button.
 */
function extension_settings_banners_submit($form, &$form_state) {
  $values['1']['display'] = $form_state['values']['display1'];
  $values['1']['weight'] = $form_state['values']['weight1'];
  $values['2']['display'] = $form_state['values']['display2'];
  $values['2']['weight'] = $form_state['values']['weight2'];
  $values['3']['display'] = $form_state['values']['display3'];
  $values['3']['weight'] = $form_state['values']['weight3'];
  variable_set('extension_settings_banners', $values);
  drupal_set_message('Banner settings have been saved.');
}

function theme_extension_settings_banners($form)  {
  $rows = array();
  foreach (element_children($form) as $key) {
    if (is_numeric($key)) {
      $wt = $form[$key]['weight' . $key]['#value'];
      $display = drupal_render($form[$key]['display' . $key]);
      $row[] = array('data' => $display);
      $banner = drupal_render($form[$key]['banner' . $key]);
      $row[] = array('data' => $banner);
      $weight = drupal_render($form[$key]['weight' . $key]);
      $row[] = array('data' => $weight);
      $rows[$wt] = array('data' => $row, 'class' => 'draggable');
      unset($row);
    }
  }
  // Individual table headers.
  $header = array();
  $header[] = array('data' => t('Display'), 'class' => 'banner-display');
  $header[] = array('data' => t('Banner'), 'class' => 'banner-banner');
  $header[] = array('data' => t('Weight'), 'class' => 'banner-weight');
  ksort($rows);
  $output =   theme('table', $header, $rows, array('id' => 'extension-banners-table'));  
  $output .=  drupal_render($form);

  drupal_add_tabledrag('extension-banners-table', 'order', 'sibling', 'weight');

  return $output;
}