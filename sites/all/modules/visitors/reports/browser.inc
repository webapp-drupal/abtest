<?php

/**
 * @file
 * Browser report for the visitors module.
 */

/**
 * Display browser report.
 *
 * @return
 *   string browser report html source.
 */
function visitors_browser() {
  $items_per_page = variable_get('visitors_lines_per_page', 10);

  $header = array(
    array('data' => t('#')),
    array('data' => t('Browser'), 'field' => 'comment'),
    array('data' => t('Pages'), 'field' => 'count', 'sort' => 'desc'),
    array('data' => t('%')),
  );

  $query = db_select('visitors', 'v')
    ->extend('PagerDefault')
    ->extend('TableSort');

  $query->addExpression('COUNT(*)', 'count');
  $query->innerJoin(
    'visitors_browscap',
    'vb',
    'v.visitors_user_agent=vb.user_agent'
  );
  $query->fields('vb', array('comment'));
  visitors_date_filter_sql_condition($query);
  $query->groupBy('comment');

  $query->orderByHeader($header);
  $query->limit($items_per_page);

  $count_query = db_select('visitors', 'v');
  $count_query->addExpression('COUNT(DISTINCT visitors_user_agent)');
  visitors_date_filter_sql_condition($count_query);
  $query->setCountQuery($count_query);
  $results = $query->execute();

  $rows       = array();
  $page       = isset($_GET['page']) ? (int) $_GET['page'] : '';
  $i          = 0 + ($page  * $items_per_page);
  $count      = 0;
  $hits_count = visitors_get_hits_count();

  foreach ($results as $data) {
    $rows[] = array(
      ++$i,
      $data->comment,
      $data->count,
      round($data->count / $hits_count * 100, 3)
    );
    $count += $data->count;
  }

  $output  = visitors_date_filter();

  if (count($rows) > 1) {
    $output .= sprintf(
      '<img src="%s" alt="%s">',
      url('visitors/browser/chart'),
      t('Browser')
    );
  }

  $output .= theme('table', array('header' => $header, 'rows' => $rows));
  $output .= theme('pager', array('quantity' => $items_per_page));

  return $output;
}

/**
 * Display browser chart report.
 */
function chart_visitors_browser() {
  $query = db_select('visitors', 'v')->extend('TableSort');
  $query->addExpression('COUNT(*)', 'count');
  $query->innerJoin(
    'visitors_browscap',
    'vb',
    'v.visitors_user_agent=vb.user_agent'
  );
  $query->fields('vb', array('comment'));
  visitors_date_filter_sql_condition($query);
  $query->groupBy('comment');

  $results = $query->execute();
  $tmp_rows = array();
  $rows     = array();

  foreach ($results as $data) {
    $rows[$data->comment] = $data->count;
  }

  $browsers = array_unique(array_keys($rows));
  if (count($rows) > 1) {
    visitors_chart($rows, $browsers);
  }
}

