<?php

/* vim: set filetype=php: */

/**
 * @file
 * Checks visitors browscap module requirements.
 */

/**
 * Implements hook_requirements().
 */
function visitors_browscap_requirements($phase) {
  $requirements = array();
  // Ensure translations don't break at install time.
  $t = get_t();

  $requirements['visitors_browscap'] = array(
    'title' => $t('Browser capabilities file'),
  );

  $result = ini_get('browscap');
  if ($result !== '') {
    $requirements['visitors_browscap']['value'] = $t(
      '%file',
      array('%file' => $result)
    );

    return $requirements;
  }

  $requirements['visitors_browscap']['severity'] = REQUIREMENT_ERROR;
  $requirements['visitors_browscap']['value'] = $t('No value');

  $requirements['visitors_browscap']['description'] = $t(
      'Browscap configuration setting in php.ini must point to the correct ' .
      'location of the browscap.ini file.'
  );

  return $requirements;
}

