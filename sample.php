<?php
// utm_source=Home%20Page&utm_medium=website&utm_campaign=AB%20Test&utm_content=HeadlineA"

$options = array (
    'query' => array (
      'utm_source'=>'Home%20Page',
      'utm_medium'=>'website',
      'utm_campaign'=>'AB%20Test',
      'utm_content'=>'HeadlineA'),
      'absolute' => TRUE,

    );





l('Title', 'url', array('query' => array('destination' => 'destination_url')));


global $base_url;

        print l(
          '', 
          $base_url . $node_url, 
            array(
              'attributes' => array(
                'id' => 'my-id', 
                'class' => 'my-class'
              ), 
              'query' => array(
                'foo' => 'bar'
              ), 
              'fragment' => 'refresh',
              'html' => TRUE
            )
        );
// Creates:

// <a href="http://www.example.com/node/1?foo=bar#refresh" id="my-id" class="my-class"><img src="http://www.example.com/files/image.jpg"/></a>
// https://drupal.stackexchange.com/questions/171026/how-to-programmatically-set-node-alias-on-node-save


/**
* Basic Node Creation Example for Drupal 7
*
* This example:
* - Assumes a standard Drupal 7 installation
* - Does not verify that the field values are correct
*/
$body_text = 'This is the body text I want entered with the node.';
$node = new stdClass();
$node->type = 'article';
node_object_prepare($node);
$node->title    = 'Node Created Programmatically on ' . date('c');
$node->language = LANGUAGE_NONE;
$node->body[$node->language][0]['value']   = $body_text;
$node->body[$node->language][0]['summary'] = text_summary($body_text);
$node->body[$node->language][0]['format']  = 'filtered_html';
$path = 'content/programmatically_created_node_' . date('YmdHis');
$node->path = array('alias' => $path);
node_save($node);


?>