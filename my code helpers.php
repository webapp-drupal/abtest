<?php


    $nid = 453; // The node to update
    $node = node_load($nid); // ...where $nid is the node id
    $node->title    = "Let's set a new title for this node";
    $node->body[$node->language][0]['value']   = "And a new body text, too.";

    node_save($node);
    echo "Node with nid " . $node->nid . " updated!\n";



    //WE do call all nodes in required conditions by 
        $query = new EntityFieldQuery;
        $result = $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'blogs')
        ->propertyCondition('status', 1)
        ->fieldCondition('field_', 'value', 2, '=')
        ->execute();
//         before performing any tests and checking does it have to be tested and required information is entered 
  //       Headline A and Headline B
    //     as well we have to get the URL and add the 


    //For loop fetched nopdes and set the test id fetch headlines ammend title and url and perform A/b test 


   // PATH is PROBLEM!!!!!!


   $nid = 453; // The node to update
   $node = node_load($nid); // ...where $nid is the node id
   $node->title    = "Let's set a new title for this node";
   $node->body[$node->language][0]['value']   = "And a new body text, too.";

   node_save($node);
   echo "Node with nid " . $node->nid . " updated!\n";



// THIS IS NODE DISPLAY

   //   $output = array();//lets display them
  //   if (!empty($result['node'])) {
  //     $output['nodes'] = node_view_multiple(node_load_multiple(array_keys($result['node'])), 'teaser');
  //     $output['pager']['#markup'] = theme('pager', $query->pager);
  //   }
  
  //   else {
  //           $output['status']['#markup'] = t('No results were returned.');
  //       }
  // return $output;



  // HOW WE ALTER THE TITLE

  function mythemename_preprocess_page(&$variables) {
    if(isset($variables['node']) && $variables['node']->type == "your content type") {
      drupal_set_title("your_title");    //ITS A PAGE TITLE
    }
  }
  
  /**
   * Override or insert variables into the node template.
   */
  function mythemename_preprocess_node(&$variables) {
    if($variables['type'] == "your content type") {
      $variables['title'] = "your title"; // IT'S A NODE TITLE ON FUUL PAGE
    }
  }

  //NODES URL 

  // module_node_view($node, $view_mode, $langcode) {
  //   if ($view_mode == 'full' && "Conditions") {
  //     // Change $node->url to what works.
  //     // Use the devel module and krumo() to check the contents of $node.
  //     drupal_goto($node->url);
  //   }
  // }

  //$nodes = node_load_multiple ($nids);
    
    //dpr($nids); // not displaing debug information
    // $node_title ='';
    // $headingA = '';
    // $headingB = '';
    // $Url = '';
    
    //return $nodes;

    //THIS IS NODE DISPLAY

    //  $output = array();//lets display them
    //   if (!empty($result['node'])) {
    //   $output['nodes'] = node_view_multiple(node_load_multiple(array_keys($result['node'])), 'teaser');
    //   $output['pager']['#markup'] = theme('pager', $query->pager);
     
    
    // }
  
    // else {
    //         $output['status']['#markup'] = t('No results were returned.');
    //     }
    

    // dpr ($output); //not displaing debug information
    // return $output;

     //   $nodes = entity_load('node', array_keys($result['node']));

  //   return node_view_multiple($nodes, 'teaser'); // how do i display or use nodes to edit and change the title for the nodes in query

   
   
  // }
  
 /**
  * Generates A/B test for the Node 
  */

 
//  function abtest_headlines_node() {

//     $output = '';
//     $output .= 'Test fired';
//     // test variations in core WOW  SOLUTION 
//     if (abtest('abtest_headlines')){

//         //Variation Headline A

//     }
//     else{

//         //Variation Headline B


//     }

//     return $output;

//  }



/**
   *  Getting nodes with required conditions
   */

  //  function abtest_headlines_test () {
  //   $node_id = '';
  //   $node_title ='';
  //   $headingA = '';
  //   $headingB = '';
  //   $Url = '';
  //   $ga_tracking_path_A = "?utm_source=Home%20Page&utm_medium=website&utm_campaign=AB%20Test&utm_content=HeadlineA";
  //   $ga_tracking_path_B = "?utm_source=Home%20Page&utm_medium=website&utm_campaign=AB%20Test&utm_content=HeadlineB";
  //   //Query the nodes    
  //   $query = new EntityFieldQuery;
  //   $result = $query
  //   ->entityCondition('entity_type', 'node')
  //   ->entityCondition('bundle', 'blogs')
  //   ->propertyCondition('status', 1)
  //   ->fieldCondition('field_ab_test_boolean', 'value', 1, '=')
  //   ->fieldCondition('field_headline_a', 'value', '', '!=')
  //   ->fieldCondition('field_headline_b', 'value', '', '!=')
  //   ->execute();
  //   $nodes = array_keys($result['node']);

  //   foreach ($nodes as $node){

  //     $node = node_load($node);
      
  //     //dpr($node);
  //     global $base_url;
  //     $node_title = "ORIGINAL TITLE: ".$node->title;
  //     $node_id = $node->nid;
  //     $headingA = "TEST TITLE VARIANT A: ".$node->field_headline_a[LANGUAGE_NONE] [0] ['value']; // string to be removed
  //     $headingB = "TEST TITLE VARIANT B: ".$node->field_headline_b[LANGUAGE_NONE] [0] ['value']; // string to be removed
  //     $Url = url(drupal_get_path_alias('node/' . $node->nid), array('absolute' => TRUE));
      
     
  //     dpr ($node_id);
  //     dpr($node_title);
  //     dpr($Url);
  //     //dpr ($node);
      
  //     //dpr($headingA);
  //     //dpr($headingB);
      
  //     //it is not real test
  //     if ((int)$node_id < 7) {
  //       //dpr ((int)$node_id);

  //       $node_title = $headingA;
  //       $Url = $Url.$ga_tracking_path_A;
  //       dpr($node_title);
  //       dpr($Url);
  //     }
  //     else {
  //       //dpr ((int)$node_id);
  //       $node_title = $headingB;
  //       $Url = $Url.$ga_tracking_path_B;
  //       dpr($node_title);
  //       dpr($Url);
  //     }

      

  //   }

    

  // }