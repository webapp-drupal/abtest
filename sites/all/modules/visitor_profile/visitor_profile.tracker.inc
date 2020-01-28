<?php

/*
*  Visitor tracking
*  Collecting user ip adress and geolocation via GEOIP2 Lite
*  @file 
*  Functions:
*  V. Charinas
*/

 /**
  * Implements hook_entity_info().
  */
 function visitor_profile_entity_info() {
     $info['profile'] = array(
         'label' => t('Visitor profile'),
         'plural label' => t('Visitors profiles'),
         'controller class' => 'EntityAPIController',
         'base table' => 'profiles',
         'entity keys' => array(
            'id' => 'pid',
          ),
     );//profile entity
     $info['visits']  = array(
        'label' => t('Profile visits'),
        'plural label' => t('Profile visits'),
        'controller class' => 'EntityAPIController',
        'base table' => 'visits',
        'entity keys' => array(
           'id' => 'vid',
         ),

     );//Visits entity
     $info['answers'] = array(
        'label' => t('Profile personal information'),
        'plural label' => t('Visitors profiles information'),
        'controller class' => 'EntityAPIController',
        'base table' => 'profile_private_answers',
        'entity keys' => array(
           'id' => 'id',
         ),
     );//Answers entity

     return $info;
   
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

