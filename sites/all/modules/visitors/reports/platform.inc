<?php

/**
 * @file
 * Platform report for the visitors module.
 */

/**
 * Get hits count from current data range.
 *
 * @return
 *   int hits count
 */
function visitors_get_hits_count() {
  $query = db_select('visitors', 'v');
  $query->addExpression('COUNT(*)', 'count');
  visitors_date_filter_sql_condition($query);
  $result = $query->execute();

  return (int) $result->fetchColumn();
}

/**
 * Get data for platform report order the query based on a header array.
 *
 * @param header
 *   Table header array. If header is NULL - data is not sorted.
 *
 * @return
 *   platforms data array
 */
function visitors_platform_data($header) {
  $query = db_select('visitors', 'v');
  $query->addExpression('COUNT(*)', 'count');
  $query->innerJoin(
    'visitors_browscap',
    'vb',
    'v.visitors_user_agent=vb.user_agent'
  );
  $query->fields('vb', array('platform'));
  visitors_date_filter_sql_condition($query);
  $query->groupBy('platform');

  if (!is_null($header)) {
    $query->extend('TableSort')->orderByHeader($header);
  }

  return $query->execute();
}

/**
 * Display platform report.
 *
 * @return
 *   string platform report html source
 */
function visitors_platform() {
  $header = array(
    array('data' => t('#')),
    array(
      'data' => t('Platform'),
      'field' => 'platform',
    ),
    array(
      'data' => t('Pages'),
      'field' => 'count',
      'sort' => 'desc'
    ),
    array('data' => t('%')),
  );

  $hits_count = visitors_get_hits_count();
  $results = visitors_platform_data($header);
  $rows = array();
  $i = 0;
  $count = 0;

  foreach ($results as $data) {
    $rows[] = array(
      ++$i,
      $data->platform,
      $data->count,
      round($data->count / $hits_count * 100, 3)
    );
    $count += $data->count;
  }

  $output  = visitors_date_filter();

  if (count($rows) > 1) {
    $output .= sprintf(
      '<img src="%s" alt="%s">',
      url('visitors/platform/chart'),
      t('Platform')
    );
  }

  $output .= theme('table', array('header' => $header, 'rows' => $rows));

  return $output;
}

/**
 * Display platform chart report.
 */
function chart_visitors_platform() {
  $results  = visitors_platform_data(NULL);
  $tmp_rows = array();
  $rows     = array();

  foreach ($results as $data) {
    $rows[$data->platform] = $data->count;
  }

  $platforms = array_unique(array_keys($rows));
  visitors_chart($rows, $platforms);
}

