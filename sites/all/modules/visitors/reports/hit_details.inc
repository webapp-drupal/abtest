<?php

/**
 * @file
 * Hit details report for the visitors module.
 */

/**
 * Menu callback; Displays recent page accesses.
 *
 * @param visitors_id
 *   int visitors id from visitors table
 *
 * @return
 *   string hit details report or 404 error if visitors_id not found
 */
function visitors_hit_details($visitors_id) {
  $hit_details = visitors_hit_details_get_data($visitors_id);

  if ($hit_details) {
    $url     = urldecode($hit_details->visitors_url);
    $referer = $hit_details->visitors_referer;
    $date    = format_date(
      $hit_details->visitors_date_time,
      'large',
      visitors_get_timezone()
    );

    $whois_enable = module_exists('whois');
    $attr = array(
      'attributes' => array(
        'target' => '_blank',
        'title' => t('Whois lookup')
      )
    );
    $ip = long2ip($hit_details->visitors_ip);
    $array = array(
      'URL'        => l($url, $url),
      'Title'      => check_plain($hit_details->visitors_title),
      'Referer'    => $referer ? l($referer, $referer) : '',
      'Date'       => $date,
      'User'       => theme('username', array('account' => $hit_details)),
      'IP'         => $whois_enable ? l($ip, 'whois/' . $ip, $attr) : $ip,
      'User Agent' => check_plain($hit_details->visitors_user_agent)
    );

    if (module_exists('visitors_geoip')) {
      $geoip_data = visitors_hit_details_get_geoip_data($hit_details);
      $array = array_merge($array, $geoip_data);
    }

    if (module_exists('visitors_browscap')) {
      $user_agent    = $hit_details->visitors_user_agent;
      $browscap_data = visitors_hit_details_get_browscap_data($user_agent);

      if ($browscap_data !== FALSE) {
        $array = array_merge($array, $browscap_data);
      }
    }

    $rows = array();
    foreach ($array as $key => $value) {
      $rows[] = array(array('data' => t($key), 'header' => TRUE), $value);
    }

    drupal_set_title(t('Details'));
    return theme('table', array('rows' => $rows));
  }

  drupal_not_found();
}

/**
 * Get hit details data from visitors table.
 *
 * @param visitors_id
 *   int visitors id
 *
 * @return
 *   stdObject
 */
function visitors_hit_details_get_data($visitors_id) {
  $query = db_select('visitors', 'v');
  $query->leftJoin('users', 'u', 'u.uid=v.visitors_uid');
  $query->fields('v');
  $query->fields('u', array('name', 'uid'));
  $query->condition('v.visitors_id', (int) $visitors_id);
  return $query->execute()->fetch();
}

/**
 * Get geoip data from hit details.
 *
 * @param $hit_details
 *   stdObject
 *
 * @return
 *   array geoip data
 */
function visitors_hit_details_get_geoip_data($hit_details) {
  $geoip_data_array = array(
    'Country'        => check_plain($hit_details->visitors_country_name),
    'Region'         => check_plain($hit_details->visitors_region),
    'City'           => check_plain($hit_details->visitors_city),
    'Postal Code'    => check_plain($hit_details->visitors_postal_code),
    'Latitude'       => check_plain($hit_details->visitors_latitude),
    'Longitude'      => check_plain($hit_details->visitors_longitude),
    'DMA Code'       => check_plain($hit_details->visitors_dma_code),
    'PSTN Area Code' => check_plain($hit_details->visitors_area_code),
  );

  return $geoip_data_array;
}

/**
 * Get browscap data from hit details.
 *
 * @param $user_agent
 *   string
 *
 * @return
 *   array browscap data
 */
function visitors_hit_details_get_browscap_data($user_agent) {
  $query = db_select('visitors_browscap', 'v');
  $query->fields('v');
  $query->condition('v.user_agent', $user_agent);
  $browscap_data = $query->execute()->fetch();
  if ($browscap_data === FALSE) {
    return FALSE;
  }

  return array(
    'Browser Name Regex'           => check_plain($browscap_data->browser_name_regex),
    'Browser Name Pattern'         => check_plain($browscap_data->browser_name_pattern),
    'Parent'                       => check_plain($browscap_data->parent),
    'Platform'                     => check_plain($browscap_data->platform),
    'Win32'                        => check_plain($browscap_data->win32),
    'Comment'                      => check_plain($browscap_data->comment),
    'Browser'                      => check_plain($browscap_data->browser),
    'Version'                      => check_plain($browscap_data->version),
    'Major Version'                => check_plain($browscap_data->majorver),
    'Minor Version'                => check_plain($browscap_data->minorver),
    'Frames'                       => check_plain($browscap_data->frames),
    'IFrames'                      => check_plain($browscap_data->iframes),
    'Tables'                       => check_plain($browscap_data->tables),
    'Cookies'                      => check_plain($browscap_data->cookies),
    'Java Script'                  => check_plain($browscap_data->javascript),
    'Java Applets'                 => check_plain($browscap_data->javaapplets),
    'CSS Version'                  => check_plain($browscap_data->cssversion),
    'Rendering Engine Name'        => check_plain($browscap_data->renderingengine_name),
    'Rendering Engine Description' => check_plain($browscap_data->renderingengine_description),
    'Platform Version'             => check_plain($browscap_data->platform_version),
    'Platform Description'         => check_plain($browscap_data->platform_description),
    'Alpha'                        => check_plain($browscap_data->alpha),
    'Beta'                         => check_plain($browscap_data->beta),
    'Win16'                        => check_plain($browscap_data->win16),
    'Win64'                        => check_plain($browscap_data->win64),
    'Background Sounds'            => check_plain($browscap_data->backgroundsounds),
    'VBScript'                     => check_plain($browscap_data->vbscript),
    'Activex Controls'             => check_plain($browscap_data->activexcontrols),
    'Is Mobile Device'             => check_plain($browscap_data->ismobiledevice),
    'Is Syndication Reader'        => check_plain($browscap_data->issyndicationreader),
    'Crawler'                      => check_plain($browscap_data->crawler),
    'AOL Version'                  => check_plain($browscap_data->aolversion),
    'Device Name'                  => check_plain($browscap_data->device_name),
    'Device Maker'                 => check_plain($browscap_data->device_maker),
    'Rendering Engine Version'     => check_plain($browscap_data->renderingengine_version)
  );
}

