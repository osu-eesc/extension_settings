<?php

/*
 * Global Content form for Extension.
 */
function extension_settings_global_emergency() {
  $notifications = variable_get('extension_settings_global_content_1', '');
  $form['global_content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Emergency Information global content'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );
  if ($notifications != NULL) {
    $form['global_content']['notifications'] = array(
      '#type' => 'fieldset',
      '#title' => t('Emergency Notifications'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE
    );
    foreach (array_keys($notifications) as $key) {
      $form['global_content']['notifications'][$key] = array();
      $form['global_content']['notifications'][$key]['title'] = array(
        '#value' => '<div class="notification-title">' . $notifications[$key]['title'] . '</div>',
      );
      $notifications[$key]['regions'] = extension_settings_remove_item_by_value($notifications[$key]['regions'], '0');
      $form['global_content']['notifications'][$key]['regions'] = array(
        '#value' => '<div class="notification-regions">' . implode(', ', $notifications[$key]['regions']) . '</div>',
      );
      $form['global_content']['notifications'][$key]['remove'] = array(
        '#value' => '<div class="notification-remove"><a href="global/remove/' . $key . '">remove</a></div>',
      );
    }
  }
  $form['global_content']['regions'] = array(
    '#type' => 'checkboxes', 
    '#title' => t('Regions'), 
    '#default_value' => array(
      '1' => '1',
      '2' => '2',
      '3' => '3',
      '4' => '4',
      '5' => '5',
      '6' => '6',
    ), 
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
  $form['global_content']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Enter the title of the notification'),
    '#default_value' => '',
    '#required' => TRUE
  );
  $form['global_content']['content'] = array(
    '#type' => 'textarea',
    '#title' => t('Content'),
    '#description' => t('Enter the content of the notification. (full HTML)'),
    '#default_value' => '',
    '#required' => TRUE
  );
  $form['global_content']['add'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
    '#submit' => array('extension_settings_global_emergency_submit')
  );
  return $form;
}


/**
 * Form validation logic for the global content settings.
 */
function extension_settings_global_emergency_submit($form, &$form_state) {
  $values['regions'] = $form_state['values']['regions'];
  $values['title'] = $form_state['values']['title'];
  $values['content'] = $form_state['values']['content'];

  $notifications = variable_get('extension_settings_global_content_1', '');
  $notifications[] = $values;

  variable_set('extension_settings_global_content_1', $notifications);
  drupal_set_message('Global content for Emergency Information has been saved.');  
}

function extension_settings_global_emergency_remove() {
  $notifications = variable_get('extension_settings_global_content_1', NULL);
  $key = arg(5);
  if (isset($key) && is_numeric($key) && in_array($key, array_keys($notifications))) {
    $form['verify_remove'] = array(
      '#value' => '<div class="form-item"><strong>Are you sure you want to delete the notification <em>' . $notifications[$key]['title'] . '</em>?</strong></div>',
    );
    $form['actions'] = array(
      '#prefix' => '<div class="container-inline">',
      '#suffix' => '</div>'
    );
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('extension_settings_global_emergency_remove_submit')
    );
    $form['actions']['cancel'] = array(
      '#value' => '<a href="/admin/settings/extension/global">Cancel</a>',
    );
  } else {
    $form = '';
  }
  return $form;
}

function extension_settings_global_emergency_remove_submit(&$form, &$form_state) {
    $notifications = variable_get('extension_settings_global_content_1', NULL);
    $key = arg(5);
    $message = 'The notification <em>' . $notifications[$key]['title'] . '</em> has been removed.';
    unset($notifications[$key]);
    $notifications = array_merge($notifications);
    variable_set('extension_settings_global_content_1', $notifications);
    drupal_set_message($message);
    $form['#redirect'] = '/admin/settings/extension/global';
}

function theme_extension_settings_global_emergency($form)  {
  $rows = array();  
  foreach (element_children($form['global_content']['notifications']) as $key) {
    if (is_numeric($key)) {
      $ntitle = drupal_render($form['global_content']['notifications'][$key]['title']);
      $row[] = array('data' => $ntitle);
      $nregions = drupal_render($form['global_content']['notifications'][$key]['regions']);
      $row[] = array('data' => $nregions);
      $nremove = drupal_render($form['global_content']['notifications'][$key]['remove']);
      $row[] = array('data' => $nremove);
      $rows[] = array('data' => $row);
      unset($row);
    }
  }  
  // Individual table headers.
  $header = array();
  $header[] = array('data' => t('Title'), 'class' => 'title-notification');
  $header[] = array('data' => t('Regions'), 'class' => 'regions-notification');
  $header[] = array('data' => t('Remove'), 'class' => 'remove-notification');
  if (isset($rows[0])) {
    $form['global_content']['notifications']['#children'] = theme('table', $header, $rows, array('id' => 'extension-notifications-table'));  
  }
  $output =  drupal_render($form);

//  drupal_add_tabledrag('extension-banners-table', 'order', 'sibling', 'weight');

  return $output;
}