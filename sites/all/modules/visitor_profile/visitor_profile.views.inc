<?php

/*
*   Diclares all custom schema to view via hook
*   @file
*   visitor_profile.views.inc 
*   V.Charinas
*   
*/

/**
 * Implements hook_views_data().
 */
function visitor_profile_views_data() {
  //All data for views
  $data = array();

  //Profile data
  $data['profiles'] = array(//Profile table description
    'table' => array(
        'group'=> t('Profiles'),
        'base' => array(
            'field' => 'pid',
            'title' => t('Profiles Table'),
            'help' => t('Profiles table contains visitor information can be related to nodes, visits, answers'),
            //'weight' => -10,
        ),
      ),
    );

    //Profiles Join  
    $data ['profiles']['table']['join'] = array(

        'visits' => array (
            'handler' => 'views_join',
            'left_table' => 'visits',
            'left_field' => 'pid',
            'field' => 'pid',
        ),

        'answers' => array (
            'handler' => 'views_join',
            'left_table' => 'profile_private_answers',
            'left_field' => 'pid',
            'field' => 'pid',
        ),
    );

      

    $data ['profiles'] = array( //fields description for profiles

        'pid' => array(
            'title' => t('Profile ID'),
            'help' => t('The ID of the Profile.'),
            'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => TRUE,
            ),
            'sort' => array(
              'handler' => 'views_handler_sort',
            ),
            'filter' => array(
              'handler' => 'views_handler_filter_numeric',
            ),
            // 'argument' => array(
            //   'handler' => 'visitor_profile_handler_argument_pid',
            //   'name field' => 'test_name',
            //   'numeric' => TRUE,
            //   'validate type' => 'numeric',
            // ),
        ),//end id

        'profile_host' => array(
            'title' => t('IP Host'),
            'help' => t('The unique string that identifies Ip address.'),
            'field' => array(
                'handler' => 'views_handler_field',
                'click sortable' => FALSE,
            ),
            'sort' => array(
            'handler' => 'views_handler_sort',
            ),
            'filter' => array(
                'handler' => 'views_handler_filter_string',
            ),
            'argument' => array(
                'handler' => 'views_handler_argument_string',
            ),
        ),//end host
         
        'created' => array (
            'title' => t('Timestamp field'),
            'help' => t('Just a timestamp field.'),
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
        ),//end created

        'country_name' => array(
            'title' => t('Country Name'),
            'help' => t('Country name visitor from.'),
            'field' => array(
                'handler' => 'views_handler_field',
                'click sortable' => TRUE,
            ),
            'sort' => array(
            'handler' => 'views_handler_sort',
            ),
            'filter' => array(
                'handler' => 'views_handler_filter_string',
            ),
            'argument' => array(
                'handler' => 'views_handler_argument_string',
            ),
        ),//end country_name

        'country_code' => array(
            'title' => t('Country code'),
            'help' => t('Country code visitor is from.'),
            'field' => array(
                'handler' => 'views_handler_field',
                'click sortable' => TRUE,
            ),
            'sort' => array(
            'handler' => 'views_handler_sort',
            ),
            'filter' => array(
                'handler' => 'views_handler_filter_string',
            ),
            'argument' => array(
                'handler' => 'views_handler_argument_string',
            ),
        ),//end country_code

        'city' => array(
            'title' => t('City Name'),
            'help' => t('City name visitor is from.'),
            'field' => array(
                'handler' => 'views_handler_field',
                'click sortable' => TRUE,
            ),
            'sort' => array(
            'handler' => 'views_handler_sort',
            ),
            'filter' => array(
                'handler' => 'views_handler_filter_string',
            ),
            'argument' => array(
                'handler' => 'views_handler_argument_string',
            ),
        ),//end city

        'postal_code' => array(
            'title' => t('Post code'),
            'help' => t('Aproximate post code of the visitor.'),
            'field' => array(
                'handler' => 'views_handler_field',
                'click sortable' => TRUE,
            ),
            'sort' => array(
            'handler' => 'views_handler_sort',
            ),
            'filter' => array(
                'handler' => 'views_handler_filter_string',
            ),
            'argument' => array(
                'handler' => 'views_handler_argument_string',
            ),
        ),//end postal_code

        'latitude' => array(
            'title' => t('Latitude field'),
            'help' => t('Just a numeric field, showing latitude value '),
            'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => FALSE,
            ),
            'filter' => array(
              'handler' => 'views_handler_filter_numeric',
            ),
            'sort' => array(
              'handler' => 'views_handler_sort',
            ),
        ),//end latitude

        'longitude' => array(
            'title' => t('Longitude'),
            'help' => t('Just a numeric field. showing longitude'),
            'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => FALSE,
            ),
            'filter' => array(
              'handler' => 'views_handler_filter_numeric',
            ),
            'sort' => array(
              'handler' => 'views_handler_sort',
            ),
        ),//end longitude
    );// fields end
    //Visits data
    $data['visits'] = array( //Visits table base with primary keys description

        'table' => array(
            'group'=> t('Profiles'),
            'base' => array(
                'field' => 'vid',
                'title' => t('Visits Table'),
                'help' => t('Profiles table contains visitor information can be related to nodes, visits, answers'),
                //'weight' => -10,
            ),
          ),


    );
    //Visits JOIN
    $data ['visits']['table']['join'] = array(

        'profiles' => array (
            'handler' => 'views_join',
            'left_table' => 'visits',
            'left_field' => 'pid',
            'field' => 'pid',
        ),

        'node' => array (
            'handler' => 'views_join',
            'left_table' => 'profile_private_answers',
            'left_field' => 'nid',
            'field' => 'visited_nid',
        ),
    );
    //Visits fields
    $data['visits'] = array( //Visits table fields description
        'vid' => array(
            'title' => t('Visit ID'),
            'help' => t('The ID of the Visit record.'),
            'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => TRUE,
            ),
            'sort' => array(
              'handler' => 'views_handler_sort',
            ),
            'filter' => array(
              'handler' => 'views_handler_filter_numeric',
            ),
        ),//end vid

        'pid' => array(
            'title' => t('Visitor Profile ID'),
            'help' => t('The Visitors profile ID '),
            'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => TRUE,
            ),
            'sort' => array(
              'handler' => 'views_handler_sort',
            ),
            'filter' => array(
              'handler' => 'views_handler_filter_numeric',
            ),
        ),//end pid

        'visited_nid' => array(
            'title' => t('Node id'),
            'help' => t('The Node ID visited by profile holder.'),
            'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => TRUE,
            ),
            'sort' => array(
              'handler' => 'views_handler_sort',
            ),
            'filter' => array(
              'handler' => 'views_handler_filter_numeric',
            ),
        ),//end visited_nid

        'visit_time' => array (
            'title' => t('Timestamp for visit'),
            'help' => t('Just a timestamp field.'),
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
        ),//end visit_time

        
    );
    //profile_private_answers data

    $data['profile_private_answers'] = array(
        'table' => array(
            'group'=> t('Profiles'),
            'base' => array(
                'field' => 'id',
                'title' => t('Profile private answers Table'),
                'help' => t('Profiles table contains visitor information can be related to nodes, visits, answers'),
                //'weight' => -10,
            ),
          ),

    );

    


  return $data;

}
 


