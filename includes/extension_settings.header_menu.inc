<?php

/*
 * Global Content form for Extension.
 */
function extension_settings_header_menu() {
  $default_values = variable_get('extension_settings_header_menu', '');
  if ($default_values == '') {
    $site_type = variable_get('extension_settings_site_type', '1');
    switch ($site_type) {
      case '2':
        $default_values = array(
          '0' => array(
            'title' => 'College of Agricultural Science',
            'href' => 'http://agsci.oregonstate.edu',
          ),
          '1' => array(
            'title' => 'OSU Extension',
            'href' => 'http://extension.oregonstate.edu',
          ),
          '2' => array(
            'title' => 'Donate',
            'href' => 'https://osufoundation.org/giving/online_gift.shtml?first_designation=College%20of%20Agricultural%20Sciences',
          ),
        );
        break;
      case '3':
        $default_values = array(
          '0' => array(
            'title' => 'College of Agricultural Science',
            'href' => 'http://agsci.oregonstate.edu',
          ),
          '1' => array(
            'title' => 'OSU Extension',
            'href' => 'http://extension.oregonstate.edu',
          ),
          '2' => array(
            'title' => 'Donate',
            'href' => 'http://extension.oregonstate.edu/get-involved/donate',
          ),
        );
        break;
      default:
        $default_values = array(
          '0' => array(
            'title' => 'Outreach & Engagement',
            'href' => 'http://outreach.oregonstate.edu',
          ),
          '1' => array(
            'title' => 'OSU Extension',
            'href' => 'http://extension.oregonstate.edu',
          ),
          '2' => array(
            'title' => 'Donate',
            'href' => 'http://extension.oregonstate.edu/get-involved/donate',
          ),
        );
        break;
    }
  }

  $form = array(
    '#type' => 'fieldset',
    '#title' => t('Header Top Menu'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );
  foreach (array_keys($default_values) as $key) {
    $form[$key] = array();
    $form[$key]['title' . $key] = array(
      '#value' =>'<div class="menu-title">' . $default_values[$key]['title'] . '</div>',
    );
    $form[$key]['title' . $key . '-hidden'] = array(
      '#type' => 'hidden',
      '#default_value' => $default_values[$key]['title'],
    );
    $form[$key]['href' . $key] = array(
      '#value' =>'<div class="menu-href">' . $default_values[$key]['href'] . '</div>',

    );
    $form[$key]['href' . $key . '-hidden'] = array(
      '#type' => 'hidden',
      '#default_value' => $default_values[$key]['href'],
    );
    $form[$key]['weight' . $key] = array(
      '#type' => 'weight',
      '#title' => t('Weight'),
      '#default_value' => $key,
      '#attributes' => array(
        'class' => 'weight',
      ),
    );
    $form[$key]['remove' . $key] = array(
      '#value' =>'<div class="menu-remove"><a href="' . base_path() . 'admin/settings/extension/header-menu/remove/' . $key . '">' . t('remove') . '</a></div>',
    );
  }
  $form['add'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add new menu item'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#attributes' => array(
      'class' => 'add-new',
    ),

  );
  $form['add']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
  );
  $form['add']['href'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
  );
  $form['help_text'] = array(
    '#value' =>'<div class="help-text">' . t('Enter the links for the header top menu as well as the order in which they will display.') . '</div>'
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Form submit logic for the header menu submit button.
 */
function extension_settings_header_menu_submit($form, &$form_state) {
  unset($new_item);
  if ($form_state['values']['title'] != '' && $form_state['values']['href'] != '') {
    $new_item['title'] = $form_state['values']['title'];
    $new_item['href'] = link_cleanup_url($form_state['values']['href']);
  }
  foreach (array_keys($form) as $key) {
    if (is_numeric($key)) {
      $header_menu[$form_state['values']['weight' . $key]]['title'] = $form_state['values']['title' . $key . '-hidden'];
      $header_menu[$form_state['values']['weight' . $key]]['href'] = $form_state['values']['href' . $key . '-hidden'];
    }
  }
  if (isset($new_item)) {
    $header_menu[] = $new_item;
  }
  variable_set('extension_settings_header_menu', $header_menu);
  drupal_set_message('Header menu items have been saved.');
}

function extension_settings_header_menu_remove() {
  $menu_items = variable_get('extension_settings_header_menu', NULL);
  $key = arg(5);  
  if (isset($key) && is_numeric($key) && in_array($key, array_keys($menu_items))) {
    $form['verify_remove'] = array(
      '#value' => '<div class="form-item"><strong>Are you sure you want to delete the menu item <em>' . $menu_items[$key]['title'] . '</em>?</strong></div>',
    );
    $form['actions'] = array(
      '#prefix' => '<div class="container-inline">',
      '#suffix' => '</div>'
    );
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('extension_settings_header_menu_remove_submit')
    );
    $form['actions']['cancel'] = array(
      '#value' => '<a href="' . base_path() . 'admin/settings/extension/header-menu">Cancel</a>',
    );
  } else {
    $form = '';
  }
  return $form;
}

function extension_settings_header_menu_remove_submit(&$form, &$form_state) {
    $menu_items = variable_get('extension_settings_header_menu', NULL);
    $key = arg(5);
    $message = 'The notification <em>' . $menu_items[$key]['title'] . '</em> has been removed.';
    unset($menu_items[$key]);
    $menu_items = array_merge($menu_items);
    variable_set('extension_settings_header_menu', $menu_items);
    drupal_set_message($message);
    $form['#redirect'] = 'admin/settings/extension/header-menu';
}

function theme_extension_settings_header_menu($form) {
  $rows = array();
  foreach (element_children($form) as $key) {
    if (is_numeric($key)) {
      $wt = $form[$key]['weight' . $key]['#value'];
      $menu_title = drupal_render($form[$key]['title' . $key]);
      $row[] = array('data' => $menu_title);
      $href = drupal_render($form[$key]['href' . $key]);
      $row[] = array('data' => $href);
      $weight = drupal_render($form[$key]['weight' . $key]);
      $row[] = array('data' => $weight);
      $remove = drupal_render($form[$key]['remove' . $key]);
      $row[] = array('data' => $remove);
      $rows[$wt] = array('data' => $row, 'class' => 'draggable');
      unset($row);
    }
  }
  // Individual table headers.
  $header = array();
  $header[] = array('data' => t('Title'), 'class' => 'menu-title');
  $header[] = array('data' => t('URL'), 'class' => 'menu-href');
  $header[] = array('data' => t('Weight'), 'class' => 'menu-weight');
  $header[] = array('data' => t('Remove'), 'class' => 'menu-remove');
  ksort($rows);
  $output =   theme('table', $header, $rows, array('id' => 'extension-header-menu-table'));  
  $output .=  drupal_render($form);

  drupal_add_tabledrag('extension-header-menu-table', 'order', 'sibling', 'weight');

  return $output;
}