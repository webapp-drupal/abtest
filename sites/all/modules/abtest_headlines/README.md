# BEFORE TESTS #
  
     Create fields for the default Article content type machine name Blogs
    1. field type bolean field_ab_test
    2. field type text   field_headline_a
    3. field type text   field_headline_a
     probably needs to be implemented in .install file - this is posible upgrade
 
# MODULE FUNCTIONALITY #
 
    module depends on:
    name = "A/B test (core)
    description = An A/B testing API for creating tests quickly in code. 
    name ="A/B Test Reporting dashboard"
    description = A simple reporting dashboard for A/B tests.web.
  
    
# IN MODULE #
 
    WE do call all nodes in required conditions by EntityFieldQuery 
    with checking all required conditions
    before performing any tests and checking does it have to be tested and required information is entered 
    it is filtred by query but to test fields are not empty will be extra care and helpfull ! Headline A and Headline B not empty !
 
    1 geting nodes in a loop we are fetching title and url of the filtered Node
    2 set the test id for each node required testing
    3 run test and modify url to provide GA access to results
    4 collect results 
    5 display results for node in node tab no additional permissions required
    6 display page with all tests results performed on admin accessable page (requires permission view results page)
 