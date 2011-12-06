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
    
  $form['configuration_settings']['extension_settings_banner_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Banner Link'),
    '#description' => t('Enter the URL for the banner graphic link. Useful for sub-sites. Leave blank to use defaults'),
    '#default_value' => variable_get('extension_settings_banner_link', ''),
    '#required' => FALSE
  );
  
  $form['configuration_settings']['extension_settings_banner_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Banner Link Title'),
    '#description' => t('Enter the html link title if banner link is set above. Leave blank to use defaults'),
    '#default_value' => variable_get('extension_settings_banner_title', ''),
    '#required' => FALSE
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
  
  $form['configuration_settings']['calendar'] = array(
    '#type' => 'fieldset',
    '#title' => t('Calendar Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#attributes' => array('class' => 'calendars')
  );

  $form['configuration_settings']['calendar']['calendar1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Calendar 1'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );

  $form['configuration_settings']['calendar']['calendar1']['extension_settings_calendar1_shortname'] = array(
    '#type' => 'textfield',
    '#title' => t('Short name'),
    '#description' => t('Enter the short name of the site for the calendar to use.'),
    '#default_value' => variable_get('extension_settings_calendar1_shortname', ''),
  );
  
  $form['configuration_settings']['calendar']['calendar1']['extension_settings_calendar1_numdisplay'] = array(
    '#type' => 'select',
    '#title' => t('Events to display'),
    '#description' => t('Select the number of events to display in the calendar.'),
    '#options' => array(
      '1' => t('1'),
      '2' => t('2'),
      '3' => t('3'),
      '4' => t('4'),
      '5' => t('5'),
      '6' => t('6'),
      '7' => t('7'),
      '8' => t('8'),
      '9' => t('9'),
      '10' => t('10'),
    ),
    '#default_value' => variable_get('extension_settings_calendar1_numdisplay', '5'),
  );
  
  $form['configuration_settings']['calendar']['calendar1']['extension_settings_calendar1_teaser'] = array(
    '#type' => 'select',
    '#title' => t('Teaser Length'),
    '#description' => t('Select the number of words to display in the teaser.'),
    '#options' => array(
      '5' => t('5'),
      '10' => t('10'),
      '15' => t('15'),
      '25' => t('20'),
      '25' => t('25'),
      '30' => t('30'),
    ),
    '#default_value' => variable_get('extension_settings_calendar1_teaser', '15'),
  );
  
  $form['configuration_settings']['calendar']['calendar1']['extension_settings_calendar1_lookahead'] = array(
    '#type' => 'select',
    '#title' => t('Look ahead days'),
    '#description' => t('Select the number of days for the calendar to look ahead.'),
    '#options' => array(
      '15' => t('15'),
      '30' => t('30'),
      '60' => t('60'),
      '90' => t('90'),
    ),
    '#default_value' => variable_get('extension_settings_calendar1_lookahead', '90'),
  );
  
  $form['configuration_settings']['calendar']['calendar2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Calendar 2'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );

  $form['configuration_settings']['calendar']['calendar2']['extension_settings_calendar2_shortname'] = array(
    '#type' => 'textfield',
    '#title' => t('Short name'),
    '#description' => t('Enter the short name of the site for the calendar to use.'),
    '#default_value' => variable_get('extension_settings_calendar2_shortname', ''),
  );
  
  $form['configuration_settings']['calendar']['calendar2']['extension_settings_calendar2_numdisplay'] = array(
    '#type' => 'select',
    '#title' => t('Events to display'),
    '#description' => t('Select the number of events to display in the calendar.'),
    '#options' => array(
      '1' => t('1'),
      '2' => t('2'),
      '3' => t('3'),
      '4' => t('4'),
      '5' => t('5'),
      '6' => t('6'),
      '7' => t('7'),
      '8' => t('8'),
      '9' => t('9'),
      '10' => t('10'),
    ),
    '#default_value' => variable_get('extension_settings_calendar2_numdisplay', '5'),
  );
  
  $form['configuration_settings']['calendar']['calendar2']['extension_settings_calendar2_teaser'] = array(
    '#type' => 'select',
    '#title' => t('Teaser Length'),
    '#description' => t('Select the number of words to display in the teaser.'),
    '#options' => array(
      '5' => t('5'),
      '10' => t('10'),
      '15' => t('15'),
      '25' => t('20'),
      '25' => t('25'),
      '30' => t('30'),
    ),
    '#default_value' => variable_get('extension_settings_calendar2_teaser', '15'),
  );
  
  $form['configuration_settings']['calendar']['calendar2']['extension_settings_calendar2_lookahead'] = array(
    '#type' => 'select',
    '#title' => t('Look ahead days'),
    '#description' => t('Select the number of days for the calendar to look ahead.'),
    '#options' => array(
      '15' => t('15'),
      '30' => t('30'),
      '60' => t('60'),
      '90' => t('90'),
    ),
    '#default_value' => variable_get('extension_settings_calendar2_lookahead', '90'),
  );
  
  $form['configuration_settings']['calendar']['calendar3'] = array(
    '#type' => 'fieldset',
    '#title' => t('Calendar 3'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );

  $form['configuration_settings']['calendar']['calendar3']['extension_settings_calendar3_shortname'] = array(
    '#type' => 'textfield',
    '#title' => t('Short name'),
    '#description' => t('Enter the short name of the site for the calendar to use.'),
    '#default_value' => variable_get('extension_settings_calendar3_shortname', ''),
  );
  
  $form['configuration_settings']['calendar']['calendar3']['extension_settings_calendar3_numdisplay'] = array(
    '#type' => 'select',
    '#title' => t('Events to display'),
    '#description' => t('Select the number of events to display in the calendar.'),
    '#options' => array(
      '1' => t('1'),
      '2' => t('2'),
      '3' => t('3'),
      '4' => t('4'),
      '5' => t('5'),
      '6' => t('6'),
      '7' => t('7'),
      '8' => t('8'),
      '9' => t('9'),
      '10' => t('10'),
    ),
    '#default_value' => variable_get('extension_settings_calendar3_numdisplay', '5'),
  );
  
  $form['configuration_settings']['calendar']['calendar3']['extension_settings_calendar3_teaser'] = array(
    '#type' => 'select',
    '#title' => t('Teaser Length'),
    '#description' => t('Select the number of words to display in the teaser.'),
    '#options' => array(
      '5' => t('5'),
      '10' => t('10'),
      '15' => t('15'),
      '25' => t('20'),
      '25' => t('25'),
      '30' => t('30'),
    ),
    '#default_value' => variable_get('extension_settings_calendar3_teaser', '15'),
  );
  
  $form['configuration_settings']['calendar']['calendar3']['extension_settings_calendar3_lookahead'] = array(
    '#type' => 'select',
    '#title' => t('Look ahead days'),
    '#description' => t('Select the number of days for the calendar to look ahead.'),
    '#options' => array(
      '15' => t('15'),
      '30' => t('30'),
      '60' => t('60'),
      '90' => t('90'),
    ),
    '#default_value' => variable_get('extension_settings_calendar3_lookahead', '90'),
  );
  
  $form['configuration_settings']['calendar']['calendar4'] = array(
    '#type' => 'fieldset',
    '#title' => t('Calendar 4'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );

  $form['configuration_settings']['calendar']['calendar4']['extension_settings_calendar4_shortname'] = array(
    '#type' => 'textfield',
    '#title' => t('Short name'),
    '#description' => t('Enter the short name of the site for the calendar to use.'),
    '#default_value' => variable_get('extension_settings_calendar4_shortname', ''),
  );
  
  $form['configuration_settings']['calendar']['calendar4']['extension_settings_calendar4_numdisplay'] = array(
    '#type' => 'select',
    '#title' => t('Events to display'),
    '#description' => t('Select the number of events to display in the calendar.'),
    '#options' => array(
      '1' => t('1'),
      '2' => t('2'),
      '3' => t('3'),
      '4' => t('4'),
      '5' => t('5'),
      '6' => t('6'),
      '7' => t('7'),
      '8' => t('8'),
      '9' => t('9'),
      '10' => t('10'),
    ),
    '#default_value' => variable_get('extension_settings_calendar4_numdisplay', '5'),
  );
  
  $form['configuration_settings']['calendar']['calendar4']['extension_settings_calendar4_teaser'] = array(
    '#type' => 'select',
    '#title' => t('Teaser Length'),
    '#description' => t('Select the number of words to display in the teaser.'),
    '#options' => array(
      '5' => t('5'),
      '10' => t('10'),
      '15' => t('15'),
      '25' => t('20'),
      '25' => t('25'),
      '30' => t('30'),
    ),
    '#default_value' => variable_get('extension_settings_calendar4_teaser', '15'),
  );
  
  $form['configuration_settings']['calendar']['calendar4']['extension_settings_calendar4_lookahead'] = array(
    '#type' => 'select',
    '#title' => t('Look ahead days'),
    '#description' => t('Select the number of days for the calendar to look ahead.'),
    '#options' => array(
      '15' => t('15'),
      '30' => t('30'),
      '60' => t('60'),
      '90' => t('90'),
    ),
    '#default_value' => variable_get('extension_settings_calendar4_lookahead', '90'),
  );
  
  $form['configuration_settings']['extension_settings_region'] = array(
    '#type' => 'radios',
    '#title' => t('Current Site Region'),
    '#description' => t('Select the geographical region of the current website.'),
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