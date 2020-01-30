<?php
//https://maxmind.github.io/GeoIP2-php/
//conditional fieldset
function MYMODULE_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'FORM_ID_node_form') {
    // programmatically create a conditional fieldset
    $form['MYFIELDSET'] = array( // do NOT name the same as a 'Field group' fieldset or problems will occur
      '#type' => 'fieldset',
      '#title' => t('Conditional fieldset'),
      '#weight' => intval($form['field_PARENT']['#weight'])+1, // put this fieldset right after it's "parent" field
      '#states' => array(
        'visible' => array(
          ':input[name="field_PARENT[und]"]' => array('value' => 'Yes'), // only show if field_PARENT == 'Yes'
        ),  
      ),  
    );

    // add existing fields (created with the Field UI) to the
    // conditional fieldset
    $fields = array('field_MYFIELD1', 'field_MYFIELD2', 'field_MYFIELD3');
    $form = MYMODULE_addToFieldset($form, 'MYFIELDSET', $fields);
  }
}

/**
 * Adds existing fields to the specified fieldset.
 *
 * @param  array   $form Nested array of form elements that comprise the form.
 * @param  string  $fieldset The machine name of the fieldset.
 * @param  array   $fields An array of the machine names of all fields to
 *                   be included in the fieldset.
 * @return array   $form The updated form.
 */
function MYMODULE_addToFieldSet($form, $fieldset, $fields) {
  foreach($fields as $field) {
    $form[$fieldset][$field] = $form[$field]; // copy existing field into fieldset
    unset($form[$field]); // destroy the original field or duplication will occur
  }

  return $form;
}

/*
  * Custom function to get query from Profiles table  
  * DB queries for the reuse purpose
  */
  function get_visitor_profiles(){
    //here we  getting all profiles but likely we no need them 
    
   }
  
   //
  
   //Here should be entity
  
  // function create_visitor_profile($host){
  // //Visitor Profile entity
  // $entity = entity_create('profile', array('type' =>'profile'));
  // $entity->profiles_host = $host;
  // $entity->created = $time;
  // $entity->save();
  // }
  // //Not all entities have a save method, in which case, use entity_save()
  // //entity_save('vehicle', $entity);
  
  
  // // Collect information like ip url brawser
  
  // //Append entity
  
  // $entity = entity_load_single('profile', $entity_id);
  // // make whatever changes
  // $entity->save();
  
  // }
  
  // //Current path
  
  // $path = current_path();
  // $path_alias = drupal_lookup_path('alias',$path);
  
          //dpm($record->city->name); // 'London'
          //dpm($record->postal->code); //  'NW4'
          //dpm($record->country->isoCode);//GB 
          //dpm($record->country->name);//Great Britan
          //dpm ($record->location->latitude);
          //dpm ($record->location->longitude);
  
  
  // $result = db_select('profiles', 'p') 
      // ->fields('p')
      // ->condition('profile_host', $host, '=')
      // ->execute()
      // ->fetchAssoc();
      // if (empty($result) || $result ) {
      //     //some code
      // }
  

      //=========================================


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
        // $data['visits'] = array( //Visits table base with primary keys description
    
        //     'table' => array(
        //         'group'=> t('Profiles'),
        //         'base' => array(
        //             'field' => 'vid',
        //             'title' => t('Visits Table'),
        //             'help' => t('Profiles table contains visitor information can be related to nodes, visits, answers'),
        //             //'weight' => -10,
        //         ),
        //       ),
    
    
        // );
        // //Visits JOIN
        // $data ['visits']['table']['join'] = array(
    
        //     'profiles' => array (
        //         'handler' => 'views_join',
        //         'left_table' => 'visits',
        //         'left_field' => 'pid',
        //         'field' => 'pid',
        //     ),
    
        //     'node' => array (
        //         'handler' => 'views_join',
        //         'left_table' => 'profile_private_answers',
        //         'left_field' => 'nid',
        //         'field' => 'visited_nid',
        //     ),
        // );
        // //Visits fields
        // $data['visits'] = array( //Visits table fields description
        //     'vid' => array(
        //         'title' => t('Visit ID'),
        //         'help' => t('The ID of the Visit record.'),
        //         'field' => array(
        //           'handler' => 'views_handler_field_numeric',
        //           'click sortable' => TRUE,
        //         ),
        //         'sort' => array(
        //           'handler' => 'views_handler_sort',
        //         ),
        //         'filter' => array(
        //           'handler' => 'views_handler_filter_numeric',
        //         ),
        //     ),//end vid
    
        //     'pid' => array(
        //         'title' => t('Visitor Profile ID'),
        //         'help' => t('The Visitors profile ID '),
        //         'field' => array(
        //           'handler' => 'views_handler_field_numeric',
        //           'click sortable' => TRUE,
        //         ),
        //         'sort' => array(
        //           'handler' => 'views_handler_sort',
        //         ),
        //         'filter' => array(
        //           'handler' => 'views_handler_filter_numeric',
        //         ),
        //     ),//end pid
    
        //     'visited_nid' => array(
        //         'title' => t('Node id'),
        //         'help' => t('The Node ID visited by profile holder.'),
        //         'field' => array(
        //           'handler' => 'views_handler_field_numeric',
        //           'click sortable' => TRUE,
        //         ),
        //         'sort' => array(
        //           'handler' => 'views_handler_sort',
        //         ),
        //         'filter' => array(
        //           'handler' => 'views_handler_filter_numeric',
        //         ),
        //     ),//end visited_nid
    
        //     'visit_time' => array (
        //         'title' => t('Timestamp for visit'),
        //         'help' => t('Just a timestamp field.'),
        //         'field' => array(
        //             'handler' => 'views_handler_field_date',
        //             'click sortable' => TRUE,
        //         ),
        //         'sort' => array(
        //             'handler' => 'views_handler_sort_date',
        //         ),
        //         'filter' => array(
        //             'handler' => 'views_handler_filter_date',
        //         ),
        //     ),//end visit_time
    
            
        // );
        // //profile_private_answers data
    
        // $data['profile_private_answers'] = array(
        //     'table' => array(
        //         'group'=> t('Profiles'),
        //         'base' => array(
        //             'field' => 'id',
        //             'title' => t('Profile private answers Table'),
        //             'help' => t('Profiles table contains visitor information can be related to nodes, visits, answers'),
        //             //'weight' => -10,
        //         ),
        //       ),
    
        // );
        // // JOIN
        // $data ['profile_private_answers']['table']['join'] = array(
    
        //     'profiles' => array (
        //         'handler' => 'views_join',
        //         'left_table' => 'visits',
        //         'left_field' => 'pid',
        //         'field' => 'pid',
        //     ),
    
        //     'node' => array (
        //         'handler' => 'views_join',
        //         'left_table' => 'profile_private_answers',
        //         'left_field' => 'nid',
        //         'field' => 'poll_nid',
        //     ),
        // );
        // // Fields defenition
        // $data ['porfile_private_answers'] = array(
    
        //     'id' => array(
        //         'title' => t('Answer record ID'),
        //         'help' => t('The ID of the Private answer.'),
        //         'field' => array(
        //           'handler' => 'views_handler_field_numeric',
        //           'click sortable' => TRUE,
        //         ),
        //         'sort' => array(
        //           'handler' => 'views_handler_sort',
        //         ),
        //         'filter' => array(
        //           'handler' => 'views_handler_filter_numeric',
        //         ),
        //     ),//end vid
    
        //     'pid' => array(
        //         'title' => t('Visitor Profile ID answered'),
        //         'help' => t('The Visitors profile ID who answered the private question '),
        //         'field' => array(
        //           'handler' => 'views_handler_field_numeric',
        //           'click sortable' => TRUE,
        //         ),
        //         'sort' => array(
        //           'handler' => 'views_handler_sort',
        //         ),
        //         'filter' => array(
        //           'handler' => 'views_handler_filter_numeric',
        //         ),
        //     ),//end pid
    
        //     'answer_time' => array (
        //         'title' => t('Timestamp for visit'),
        //         'help' => t('Just a timestamp field.'),
        //         'field' => array(
        //             'handler' => 'views_handler_field_date',
        //             'click sortable' => TRUE,
        //         ),
        //         'sort' => array(
        //             'handler' => 'views_handler_sort_date',
        //         ),
        //         'filter' => array(
        //             'handler' => 'views_handler_filter_date',
        //         ),
        //     ),//end answer_time
    
        //     'poll_nid' => array(
        //         'title' => t('Node id'),
        //         'help' => t('The Node ID visited by profile holder.'),
        //         'field' => array(
        //           'handler' => 'views_handler_field_numeric',
        //           'click sortable' => TRUE,
        //         ),
        //         'sort' => array(
        //           'handler' => 'views_handler_sort',
        //         ),
        //         'filter' => array(
        //           'handler' => 'views_handler_filter_numeric',
        //         ),
        //     ),//end poll_nid
    
        //     'question' => array(
        //         'title' => t('Private Question'),
        //         'help' => t('Privatew question asked to visitor after poll vote.'),
        //         'field' => array(
        //             'handler' => 'views_handler_field',
        //         // This is use by the table display plugin.
        //             'click sortable' => TRUE,
        //          ),
        //         'sort' => array(
        //             'handler' => 'views_handler_sort',
        //         ),
        //         'filter' => array(
        //             'handler' => 'views_handler_filter_string',
        //         ),
        //         'argument' => array(
        //             'handler' => 'views_handler_argument_string',
        //         ),
        //     ),//end question
    
        //     'answer' => array(
        //         'title' => t('Answer'),
        //         'help' => t('The answer for the private question'),
        //         'field' => array(
        //             'handler' => 'views_handler_field',
        //         // This is use by the table display plugin.
        //             'click sortable' => TRUE,
        //          ),
        //         'sort' => array(
        //             'handler' => 'views_handler_sort',
        //         ),
        //         'filter' => array(
        //             'handler' => 'views_handler_filter_string',
        //         ),
        //         'argument' => array(
        //             'handler' => 'views_handler_argument_string',
        //         ),
        //     ),//end question
    
    
    
       // );
    
    