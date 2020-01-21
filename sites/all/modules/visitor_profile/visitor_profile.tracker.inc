<?php

/*
*  Visitor tracking
*  Collecting user ip adress and geolocation via GEOIP2 Lite
*  @file 
*  Functions:
*  V. Charinas
*/
 //drupal_set_message (t('User tracking is Connected... '), 'sucsess');

/**
 * Implements hook_boot().
 */
    
function visitor_profile_boot() {
    // loading GEO IP API preconfigured with third party module
 drupal_load('module', 'geoip');
}

function create_visitor_profile(){
//Visitor Profile entity
$entity = entity_create('visitor', array('type' =>'profile'));
$entity->host = "Host";
//$entity->field_hello = array(LANGUAGE_NONE => array(0 => array('value' => "Howdy Partner!")));
$entity->save();
//Not all entities have a save method, in which case, use entity_save()
//entity_save('vehicle', $entity);


// Collect information like ip url brawser

//Append entity

$entity = entity_load_single('profile', $entity_id);
// make whatever changes
$entity->save();

}

//Current path

$path = current_path();
$path_alias = drupal_lookup_path('alias',$path);

