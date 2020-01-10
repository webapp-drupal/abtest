<?php

/* vim: set filetype=php: */

/**
 * @file
 * Implements hook_exit().
 */

/**
 * Verify the syntax of the given ip address.
 *
 * @param ip
 *   A string containing an ip address.
 * @return
 *   TRUE if the ip is in a valid format, FALSE on failure.
 */
function visitors_is_ip_valid($ip) {
  $result = preg_match(
    '/^(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})$/',
    $ip,
    $matches
  );

  return (
    $result &&
    isset($matches[0]) &&
    ($matches[0] === $ip) &&
    ($matches[1] >= 1) && ($matches[1] <= 255) &&
    ($matches[2] >= 0) && ($matches[2] <= 255) &&
    ($matches[3] >= 0) && ($matches[3] <= 255) &&
    ($matches[4] >= 0) && ($matches[4] <= 255)
  );
}

/**
 * Get visitors ip address.
 *
 * @return
 *   A string containing an ip address ('0.0.0.0' on failure).
 */
function visitors_get_ip() {
  if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
    $ip_array = explode(',', $_SERVER['HTTP_X_FORWARDED_FOR']);
    $ip       = trim(reset($ip_array));
  }
  else {
    $ip = $_SERVER['REMOTE_ADDR'];
  }

  return (visitors_is_ip_valid($ip) ? $ip : '0.0.0.0');
}

/**
 * Converts a string containing an visitors (IPv4) Internet Protocol dotted
 * address into a proper address.
 *
 * @return
 *   string
 */
function visitors_get_ip_str() {
  return sprintf("%u", ip2long(visitors_get_ip()));
}

/**
 * Get full path request uri.
 *
 * @return
 *   string full path
 */
function visitors_get_url() {
  return
    urldecode(sprintf('http://%s%s', $_SERVER['HTTP_HOST'], request_uri()));
}

/**
 * Get internal path.
 *
 * @return
 *   string internal path
 */
function visitors_get_path() {
  return $_GET['q'];
}

/**
 * Get the address of the page (if any) which referred the user agent to the
 * current page.
 *
 * @return
 *   string referer, or empty string if referer does not exist
 */
function visitors_get_referer() {
  $referer = '';

  if (isset($_SERVER['HTTP_REFERER'])) {
    if (preg_match('/^(?:[;\/?:@&=+$,]|(?:[^\W_]|[-_.!~*\()\[\] ])|(?:%[\da-fA-F]{2}))*$/', $_SERVER['HTTP_REFERER'])) {
      $referer = rawurldecode($_SERVER['HTTP_REFERER']);
    }
  }

  return $referer;
}

/**
 * Get the title of the current page.
 *
 * @return
 *   string title of the current page
 */
function visitors_get_title() {
  return htmlspecialchars_decode(drupal_get_title(), ENT_QUOTES);
}

/**
 * Get visitor user agent.
 *
 * @return
 *   string user agent, or empty string if user agent does not exist
 */
function visitors_get_user_agent() {
  return isset($_SERVER['HTTP_USER_AGENT']) ? $_SERVER['HTTP_USER_AGENT'] : '';
}

/**
 * Retrieve geoip data for ip.
 *
 * @param ip
 *   A string containing an ip address.
 * @return
 *   array geoip data array.
 */
function visitors_get_geoip_data($ip) {
  if (function_exists('geoip_record_by_name')) {
    $geoip_data = @geoip_record_by_name($ip);
    if ((!is_null($geoip_data)) && ($geoip_data !== FALSE)) {
      /* utf8_encode use for transform city value from iso-8859-1 into the
         utf8. */
      return array(
        'visitors_continent_code' => $geoip_data['continent_code'],
        'visitors_country_code'   => $geoip_data['country_code'],
        'visitors_country_code3'  => $geoip_data['country_code3'],
        'visitors_country_name'   => $geoip_data['country_name'],
        'visitors_region'         => $geoip_data['region'],
        'visitors_city'           => utf8_encode($geoip_data['city']),
        'visitors_postal_code'    => $geoip_data['postal_code'],
        'visitors_latitude'       => $geoip_data['latitude'],
        'visitors_longitude'      => $geoip_data['longitude'],
        'visitors_dma_code'       => $geoip_data['dma_code'],
        'visitors_area_code'      => $geoip_data['area_code'],
      );
    }
  }

  return array(
    'visitors_continent_code' => '',
    'visitors_country_code'   => '',
    'visitors_country_code3'  => '',
    'visitors_country_name'   => '',
    'visitors_region'         => '',
    'visitors_city'           => '',
    'visitors_postal_code'    => '',
    'visitors_latitude'       => '0',
    'visitors_longitude'      => '0',
    'visitors_dma_code'       => '0',
    'visitors_area_code'      => '0'
  );
}

/**
 * Retrieve capabilities of the browser for $user_agent.
 *
 * @param user_agent
 *   A string containing the User Agent to be analyzed.
 * @return
 *   array browser capabilities data array.
 */
function visitors_get_browscap_data($user_agent) {
  $result = get_browser($user_agent);

  return array(
    'user_agent'                  => $user_agent,
    'browser_name_regex'          => utf8_encode($result->browser_name_regex),
    'browser_name_pattern'        => $result->browser_name_pattern,
    'parent'                      => isset($result->parent) ? $result->parent : '',
    'platform'                    => $result->platform,
    'win32'                       => $result->win32,
    'comment'                     => $result->comment,
    'browser'                     => $result->browser,
    'version'                     => $result->version,
    'majorver'                    => $result->majorver,
    'minorver'                    => $result->minorver,
    'frames'                      => ($result->frames == '') ? NULL : $result->frames,
    'iframes'                     => ($result->iframes == '') ? NULL : $result->iframes,
    'tables'                      => ($result->tables == '') ? NULL : $result->tables,
    'cookies'                     => ($result->cookies == '') ? NULL : $result->cookies,
    'javascript'                  => ($result->javascript == '') ? NULL : $result->javascript,
    'javaapplets'                 => ($result->javaapplets == '') ? NULL : $result->javaapplets,
    'cssversion'                  => $result->cssversion,
    'renderingengine_name'        => $result->renderingengine_name,
    'renderingengine_description' => $result->renderingengine_description,
    'platform_version'            => $result->platform_version,
    'platform_description'        => $result->platform_description,
    'alpha'                       => $result->alpha,
    'beta'                        => $result->beta,
    'win16'                       => $result->win16,
    'win64'                       => $result->win64,
    'backgroundsounds'            => $result->backgroundsounds,
    'vbscript'                    => $result->vbscript,
    'activexcontrols'             => $result->activexcontrols,
    'ismobiledevice'              => $result->ismobiledevice,
    'issyndicationreader'         => $result->issyndicationreader,
    'crawler'                     => ($result->crawler == '') ? NULL : $result->crawler,
    'aolversion'                  => $result->aolversion,
    'device_name'                 => $result->device_name,
    'device_maker'                => $result->device_maker,
    'renderingengine_version'     => $result->renderingengine_version,
  );
}

/**
 * Implements hook_exit().
 */
function visitors_exit() {
  drupal_bootstrap(DRUPAL_BOOTSTRAP_SESSION);
  drupal_load('module', 'user');

  global $user;
  $not_admin = !in_array('administrator', $user->roles);
  $log_admin = !variable_get('visitors_exclude_administer_users', 0);

  if ($log_admin || $not_admin) {
    $ip_str     = visitors_get_ip_str();
    $user_agent = visitors_get_user_agent();

    $fields = array(
      'visitors_uid'            => $user->uid,
      'visitors_ip'             => $ip_str,
      'visitors_date_time'      => time(),
      'visitors_url'            => visitors_get_url(),
      'visitors_referer'        => visitors_get_referer(),
      'visitors_path'           => visitors_get_path(),
      'visitors_title'          => visitors_get_title(),
      'visitors_user_agent'     => $user_agent
    );

    if (module_exists('visitors_geoip')) {
      if (!isset($_SESSION['visitors_geoip'][$ip_str])) {
        $_SESSION['visitors_geoip'][$ip_str] =
          visitors_get_geoip_data($ip_str);
      }

      $geoip_data = $_SESSION['visitors_geoip'][$ip_str];
      $fields     = array_merge($fields, $geoip_data);
    }

    visitors_browscap_save_user_agent($user_agent);

    db_insert('visitors')
      ->fields($fields)
      ->execute();
  }
}

/**
 * Store user agent info to visitors_browscap table.
 *
 * @param user_agent
 *   A string containing the User Agent to be analyzed.
 */
function visitors_browscap_save_user_agent($user_agent) {
  if (
    module_exists('visitors_browscap') &&
    !isset($_SESSION['visitors_browscap'][$user_agent]) &&
    !visitors_browscap_check_is_user_agent_exist($user_agent)
  ) {
    $_SESSION['visitors_browscap'][$user_agent] =
      visitors_get_browscap_data($user_agent);
    $browscap_data = $_SESSION['visitors_browscap'][$user_agent];

    db_insert('visitors_browscap')
      ->fields($browscap_data)
      ->execute();
  }
}

/**
 * Check is user agent already exist to visitors_browscap table.
 *
 * @param user_agent
 *   A string containing the User Agent to be analyzed.
 * @return
 *   bool TRUE on success, FALSE on failure.
 */
function visitors_browscap_check_is_user_agent_exist($user_agent) {
  $query = db_select('visitors_browscap', 'v');
  $query->fields('v', array('id'));
  $query->condition('v.user_agent', $user_agent);
  return ($query->execute()->fetch() !== FALSE);
}

