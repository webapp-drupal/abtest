<?php

/*
*  @file
*  visitor_profile.entity.inc
*  Visitor tracking
*  Collecting user ip adress and geolocation via GEOIP2 Lite
*  @author V. Charinas
*/

 /**
  * Implements hook_entity_info().
  */
 function visitor_profile_entity_info() {
     $info['profile'] = array(
         'label' => t('Profile'),
         'plural label' => t('Profiles'),
         'entity class' => 'Entity',
         'controller class' => 'EntityAPIController',
         'views controller class' =>'EntityDefaultViewsController',
         'base table' => 'profiles',
         'entity keys' => array(
            'id' => 'pid',
          ),
     );//profile entity
     $info['visits']  = array(
        'label' => t('Profile Visit'),
        'plural label' => t('Profiles visits'),
        'entity class' => 'Entity',
        'controller class' => 'EntityAPIController',
        'views controller class' =>'EntityDefaultViewsController',
        'base table' => 'visits',
        'entity keys' => array(
           'id' => 'vid',
         ),

     );//Visits entity
     $info['answers'] = array(
        'label' => t('Profile answer'),
        'plural label' => t('Profiles answers'),
        'entity class' => 'Entity',
        'controller class' => 'EntityAPIController',
        'views controller class' =>'EntityDefaultViewsController',
        'base table' => 'profile_private_answers',
        'entity keys' => array(
           'id' => 'id',
         ),
     );//Answers entity

     return $info;
   
 }

 
