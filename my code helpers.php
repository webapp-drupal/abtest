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
