<?php

/*
*   Diclares all custom schema to view via hook
*   @file
*   visitor_profile.views.inc 
*   V.Charinas
*   
*/

/**
 * Implements  hook_views_data_alter(&$data).
 */
function visitor_profile_views_data_alter(&$data) {
  //All data for views
  $data ['profiles']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the record was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  //Visits time date and relationships 
  $data ['visits']['visit_time'] = array(
    'title' => t('Date/Time'),
    'help' => t('The date profile visited.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['visits']['pid'] = array(
    'title' => t('Profile ID'),
    'help' => t('Visit Profile id.'),
    'relationship' => array(
        'base' => 'profiles',
        'base field' => 'pid',
        'relationship field' => 'pid',
      'handler' => 'views_handler_relationship',
      'label' => t('Node ID'),
    ),
  );

  $data['visits']['visited_nid'] = array(
    'title' => t('Visited Node ID'),
    'help' => t('Visited node id by profile.'),
    'relationship' => array(
        'base' => 'node',
        'base field' => 'nid',
        'relationship field' => 'visited_nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Profile ID'),
    ),
);

  return $data;
}
  



