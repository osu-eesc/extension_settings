<?php

/*
 * Admin Settings form for Extension.
 */
function extension_settings_admin_settings() {
  $form['configuration_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );

  $form['configuration_settings']['extension_settings_sitename'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Name'),
    '#description' => t('Enter the name of the site.'),
    '#default_value' => variable_get('extension_settings_sitename', 'OSU Extension Service'),
    '#required' => TRUE
  );

  $form['configuration_settings']['extension_settings_webmaster_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Webmaster Link'),
    '#description' => t('Enter the link for this site\'s webmaster. This is generally in the form of http://extension.oregonstate.edu/employee/firstname-lastname. This needs be a valid link, not an email address.'),
    '#default_value' => variable_get('extension_settings_webmaster_link', 'http://extension.oregonstate.edu/employee/extension-webmaster'),
    '#required' => TRUE
  );

  $siteTypes = array('0' => t('Extension Website'), '1' => t('Extension County/Program Website'), '2' => t('Branch Experiment Station Website'), '3' => t('Combined Extension & Experiment Station Center Website'), '4' => t('Other Website') );

  $form['configuration_settings']['extension_settings_site_type'] = array(
    '#type' => 'radios',
    '#title' => t('Site Type'),
    '#default_value' => variable_get('extension_settings_site_type', '1'), 
    '#options' => $siteTypes,
    '#required' => TRUE
    );

  $form['configuration_settings']['extension_settings_header_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Header Text'),
    '#description' => t('Enter the header text if website is of type <em>Other Website</em>.'),
    '#default_value' => variable_get('extension_settings_header_text', ''),
    '#required' => FALSE
  );
  
  $form['configuration_settings']['extension_settings_server_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Server Path'),
    '#description' => t('Change path to <em>/Users/username/Sites</em> when using on localhost sites.'),
    '#default_value' => variable_get('extension_settings_server_path', '/www/virtual/extension/'),
    '#required' => TRUE
  );
  
  $form['configuration_settings']['extension_settings_region'] = array(
    '#type' => 'radios',
    '#title' => t('Region'),
    '#description' => t('Select the geographical region of the website.'),
    '#options' => array(
      '1' => '<span class="radio-label">North West</span>',
      '2' => '<span class="radio-label">North Central</span>',
      '3' => '<span class="radio-label">North East</span>',
      '4' => '<span class="radio-label">South West</span>',
      '5' => '<span class="radio-label">South Central</span>',
      '6' => '<span class="radio-label">South East</span>',
    ), 
    '#default_value' => variable_get('extension_settings_region', '1'),
    '#prefix' => '<div id="oregon-region">',
    '#suffix' => '</div>',
    '#required' => TRUE
  );  

  return system_settings_form($form);
}

/**
 * Form validation logic for the config settings.
 */
function extension_settings_admin_settings_validate($form, &$form_state) {
if (!valid_url($form_state['values']['extension_settings_webmaster_link'])) {
  form_set_error('extension_settings_webmaster_link', t('Please enter a valid URL.'));
}
  if ($form_state['values']['extension_settings_site_type'] == '4' && !$form_state['values']['extension_settings_header_text']) {
    form_set_error('extension_settings_header_text', t('Header text is required if site is of type <em>Other Website</em> '));
  }
}