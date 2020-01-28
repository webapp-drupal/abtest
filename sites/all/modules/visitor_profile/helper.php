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
  