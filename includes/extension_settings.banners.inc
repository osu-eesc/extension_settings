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
  $form['1']['display'] = array(
    '#type' => 'checkbox',
    '#title' => t(''),
    '#default_value' => $default_values['1']['display'],
    '#attributes' => array(
    ),
  );
  $form['1']['banner'] = array(
    '#value' => '<div><img src="/' . drupal_get_path('module', 'extension_settings') .'/images/gfx_ico_snake.png" /></div>',
  );
  $form['1']['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => $default_values['1']['weight'],
    '#description' => t(''),
    '#attributes' => array(
    ),
  );
  $form['2'] = array();
  $form['2']['display'] = array(
    '#type' => 'checkbox',
    '#title' => t(''),
    '#default_value' => $default_values['2']['display'],
    '#attributes' => array(
    ),
  );
  $form['2']['banner'] = array(
    '#value' => '<div><img src="/' . drupal_get_path('module', 'extension_settings') .'/images/gfx_ico_spade.png" /></div>',
  );
  $form['2']['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => $default_values['2']['weight'],
    '#description' => t(''),
    '#attributes' => array(
    ),
  );
  $form['3'] = array();
  $form['3']['display'] = array(
    '#type' => 'checkbox',
    '#title' => t(''),
    '#default_value' => $default_values['3']['display'],
    '#attributes' => array(
    ),
  );
  $form['3']['banner'] = array(
    '#value' => '<div><img src="/' . drupal_get_path('module', 'extension_settings') .'/images/gfx_ico_pot.png" /></div>',
  );
  $form['3']['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => $default_values['3']['weight'],
    '#description' => t(''),
    '#attributes' => array(
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
  $values['1']['display'] = $form_state['values']['1']['display'];
  $values['1']['weight'] = $form_state['values']['1']['weight'];
  $values['2']['display'] = $form_state['values']['2']['display'];
  $values['2']['weight'] = $form_state['values']['2']['weight'];
  $values['3']['display'] = $form_state['values']['3']['display'];
  $values['3']['weight'] = $form_state['values']['3']['weight'];

  variable_set('extension_settings_banners', $values);
  drupal_set_message('Banner settings have been saved.');
}

function theme_extension_settings_banners($form)  {
  $rows = array();
  foreach (element_children($form) as $key) {
    if (is_numeric($key)) {
      $display = drupal_render($form[$key]['display']);
      $row[] = array('data' => $display, 'class' => 'banner-display');
      $banner = drupal_render($form[$key]['banner']);
      $row[] = array('data' => $banner, 'class' => 'banner-image');
      $weight = drupal_render($form[$key]['weight']);
      $row[] = array('data' => $weight, 'class' => 'banner-weight');

      $rows[] = array('data' => $row, 'class' => 'draggable');
      unset($row);
    }
  }
  // Individual table headers.
  $header = array();
  $header[] = array('data' => t('Display'), 'class' => 'banner-display');
  $header[] = array('data' => t('Banner'), 'class' => 'banner-banner');
  $header[] = array('data' => t('Weight'), 'class' => 'banner-weight');

  $output =   theme('table', $header, $rows, array('id' => 'extension-banners-table'));
  $output .=  drupal_render($form);

  drupal_add_tabledrag('extension-banners-table', 'order', 'sibling', 'banner-weight');

  return $output;
}