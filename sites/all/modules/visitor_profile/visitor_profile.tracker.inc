<?php

/*
*  @file
*  visitor_profile.tracker.inc
*  Visitor tracking
*  Collecting user ip adress and geolocation via GEOIP2 Lite
*  @author V. Charinas
*/

 /**
  * Implements hook_entity_info().
  */
 function visitor_profile_entity_info() {
     $info['profile'] = array(
         'label' => t('Visitor profile'),
         'plural label' => t('Visitors profiles'),
         'entity class' => 'Entity',
         'controller class' => 'EntityAPIController',
         'base table' => 'profiles',
         'entity keys' => array(
            'id' => 'pid',
          ),
     );//profile entity
     $info['visits']  = array(
        'label' => t('Profile visits'),
        'plural label' => t('Profile visits'),
        'entity class' => 'Entity',
        'controller class' => 'EntityAPIController',
        'base table' => 'visits',
        'entity keys' => array(
           'id' => 'vid',
         ),

     );//Visits entity
     $info['answers'] = array(
        'label' => t('Profile personal information'),
        'plural label' => t('Visitors profiles information'),
        'entity class' => 'Entity',
        'controller class' => 'EntityAPIController',
        'base table' => 'profile_private_answers',
        'entity keys' => array(
           'id' => 'id',
         ),
     );//Answers entity

     return $info;
   
 }
 
