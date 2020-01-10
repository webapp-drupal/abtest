# BEFORE TESTS #

    IMPORTANT : required module installation 

    A/B tests (core)
    https://www.drupal.org/project/abtest
    https://www.drupal.org/project/views_flipped_table
    https://www.drupal.org/project/views_conditional


    CMS Configuration
    Create fields for the Default Article content type machine name Blogs
    1. field type bolean field_ab_test
    2. field type text   field_headline_a
    3. field type text   field_headline_a
    Add fields in Front Page views for the blocks:

    1  field_headline_a
    2  field_headline_b
    3  Content Path
    4  View conditional - with configuration
    Views: Views Conditional (If field_promo_title is Contains [field_headline_a], output [field_headline_a], else output [field_headline_b])

    Output for the [field_headline_a]
    <h3><a href="[path]?utm_source=Home%20Page&utm_medium=website&utm_campaign=AB%20Test&utm_content=HeadlineA">[field_headline_a]</a></h3>

    Output for the [field_headline_b]
    <h3><a href="[path]?utm_source=Home%20Page&utm_medium=website&utm_campaign=AB%20Test&utm_content=HeadlineB">[field_headline_b]</a></h3>

    5  Views for the Admin page conversion report

            $view = new view();
            $view->name = 'abtest_listing';
            $view->description = '';
            $view->tag = 'abtest';
            $view->base_table = 'abtest';
            $view->human_name = 'A/B test listing';
            $view->core = 7;
            $view->api_version = '3.0';
            $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

            /* Display: Master */
            $handler = $view->new_display('default', 'Master', 'default');
            $handler->display->display_options['title'] = 'Article A/B test Results';
            $handler->display->display_options['use_more_always'] = FALSE;
            $handler->display->display_options['access']['type'] = 'perm';
            $handler->display->display_options['access']['perm'] = 'access abtest dashboard';
            $handler->display->display_options['cache']['type'] = 'none';
            $handler->display->display_options['query']['type'] = 'views_query';
            $handler->display->display_options['exposed_form']['type'] = 'basic';
            $handler->display->display_options['pager']['type'] = 'full';
            $handler->display->display_options['pager']['options']['items_per_page'] = '10';
            $handler->display->display_options['style_plugin'] = 'table';
            $handler->display->display_options['style_options']['columns'] = array(
            'test_name' => 'test_name',
            'conversion_name' => 'conversion_name',
            'created' => 'created',
            );
            $handler->display->display_options['style_options']['default'] = 'test_name';
            $handler->display->display_options['style_options']['info'] = array(
            'test_name' => array(
                'sortable' => 1,
                'default_sort_order' => 'asc',
                'align' => '',
                'separator' => '',
                'empty_column' => 0,
            ),
            'conversion_name' => array(
                'sortable' => 1,
                'default_sort_order' => 'asc',
                'align' => '',
                'separator' => '',
                'empty_column' => 0,
            ),
            'created' => array(
                'sortable' => 1,
                'default_sort_order' => 'asc',
                'align' => '',
                'separator' => '',
                'empty_column' => 0,
            ),
            );
            /* Field: A/B test: Test ID */
            $handler->display->display_options['fields']['test_id']['id'] = 'test_id';
            $handler->display->display_options['fields']['test_id']['table'] = 'abtest';
            $handler->display->display_options['fields']['test_id']['field'] = 'test_id';
            $handler->display->display_options['fields']['test_id']['exclude'] = TRUE;
            $handler->display->display_options['fields']['test_id']['separator'] = '';
            /* Field: A/B test: Name */
            $handler->display->display_options['fields']['test_name']['id'] = 'test_name';
            $handler->display->display_options['fields']['test_name']['table'] = 'abtest';
            $handler->display->display_options['fields']['test_name']['field'] = 'test_name';
            $handler->display->display_options['fields']['test_name']['alter']['make_link'] = TRUE;
            $handler->display->display_options['fields']['test_name']['alter']['path'] = 'abtest/[test_id]/view';
            /* Field: A/B test: Total participants */
            $handler->display->display_options['fields']['total_participants']['id'] = 'total_participants';
            $handler->display->display_options['fields']['total_participants']['table'] = 'abtest';
            $handler->display->display_options['fields']['total_participants']['field'] = 'total_participants';
            $handler->display->display_options['fields']['total_participants']['label'] = 'Participants';
            /* Field: A/B test: Total conversions */
            $handler->display->display_options['fields']['total_conversions']['id'] = 'total_conversions';
            $handler->display->display_options['fields']['total_conversions']['table'] = 'abtest';
            $handler->display->display_options['fields']['total_conversions']['field'] = 'total_conversions';
            $handler->display->display_options['fields']['total_conversions']['label'] = 'Conversions';
            /* Field: A/B test: Conversion name */
            $handler->display->display_options['fields']['conversion_name']['id'] = 'conversion_name';
            $handler->display->display_options['fields']['conversion_name']['table'] = 'abtest';
            $handler->display->display_options['fields']['conversion_name']['field'] = 'conversion_name';
            /* Field: A/B test: Created date */
            $handler->display->display_options['fields']['created']['id'] = 'created';
            $handler->display->display_options['fields']['created']['table'] = 'abtest';
            $handler->display->display_options['fields']['created']['field'] = 'created';
            $handler->display->display_options['fields']['created']['label'] = 'Created';
            $handler->display->display_options['fields']['created']['date_format'] = 'custom';
            $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';

            /* Display: Page */
            $handler = $view->new_display('page', 'Page', 'page');
            $handler->display->display_options['enabled'] = FALSE;
            $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
            $handler->display->display_options['path'] = 'abtest/dashboard';
            $handler->display->display_options['menu']['type'] = 'normal';
            $handler->display->display_options['menu']['title'] = 'A/B tests';
            $handler->display->display_options['menu']['weight'] = '0';
            $handler->display->display_options['menu']['context'] = 0;
            $handler->display->display_options['menu']['context_only_inline'] = 0;

            /* Display: Dashboard Page */
            $handler = $view->new_display('page', 'Dashboard Page', 'page_1');
            $handler->display->display_options['defaults']['fields'] = FALSE;
            /* Field: A/B test: Test ID */
            $handler->display->display_options['fields']['test_id']['id'] = 'test_id';
            $handler->display->display_options['fields']['test_id']['table'] = 'abtest';
            $handler->display->display_options['fields']['test_id']['field'] = 'test_id';
            $handler->display->display_options['fields']['test_id']['exclude'] = TRUE;
            $handler->display->display_options['fields']['test_id']['separator'] = '';
            /* Field: A/B test: Name */
            $handler->display->display_options['fields']['test_name']['id'] = 'test_name';
            $handler->display->display_options['fields']['test_name']['table'] = 'abtest';
            $handler->display->display_options['fields']['test_name']['field'] = 'test_name';
            $handler->display->display_options['fields']['test_name']['alter']['make_link'] = TRUE;
            $handler->display->display_options['fields']['test_name']['alter']['path'] = 'admin/reports/abtests/[test_id]/view';
            /* Field: A/B test: Total participants */
            $handler->display->display_options['fields']['total_participants']['id'] = 'total_participants';
            $handler->display->display_options['fields']['total_participants']['table'] = 'abtest';
            $handler->display->display_options['fields']['total_participants']['field'] = 'total_participants';
            $handler->display->display_options['fields']['total_participants']['label'] = 'Participants';
            /* Field: A/B test: Total conversions */
            $handler->display->display_options['fields']['total_conversions']['id'] = 'total_conversions';
            $handler->display->display_options['fields']['total_conversions']['table'] = 'abtest';
            $handler->display->display_options['fields']['total_conversions']['field'] = 'total_conversions';
            $handler->display->display_options['fields']['total_conversions']['label'] = 'Conversions';
            /* Field: A/B test: Conversion name */
            $handler->display->display_options['fields']['conversion_name']['id'] = 'conversion_name';
            $handler->display->display_options['fields']['conversion_name']['table'] = 'abtest';
            $handler->display->display_options['fields']['conversion_name']['field'] = 'conversion_name';
            /* Field: A/B test: Created date */
            $handler->display->display_options['fields']['created']['id'] = 'created';
            $handler->display->display_options['fields']['created']['table'] = 'abtest';
            $handler->display->display_options['fields']['created']['field'] = 'created';
            $handler->display->display_options['fields']['created']['label'] = 'Created';
            $handler->display->display_options['fields']['created']['date_format'] = 'custom';
            $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
            $handler->display->display_options['path'] = 'admin/reports/abtests';
            $handler->display->display_options['menu']['type'] = 'normal';
            $handler->display->display_options['menu']['title'] = 'A/B Test Results';
            $handler->display->display_options['menu']['weight'] = '0';
            $handler->display->display_options['menu']['name'] = 'management';
            $handler->display->display_options['menu']['context'] = 0;
            $handler->display->display_options['menu']['context_only_inline'] = 0;
            $handler->display->display_options['tab_options']['weight'] = '0';



# IN MODULE #
 
    WE do call all nodes in required conditions by EntityFieldQuery with conditions that the node is used to perform the A/B test and required fielsds are filled
    
1. Geting nodes in a loop we are fetching headlines 
2. Set the test id for each node required A/B testing
3. Run multiple test in core (More info in A/B test functionality)
4. Collecting results on page callback on node full view mode 
5. Display results of the Tests in Reports admin/reports/abtests
6. Providing results on node tab about exact node A/B Test
7. Collect the Campaign results via the utm code in node Url


# A/B TEST FUNCTIONALITY #

    ABTEST MODULE function abtest('TEST ID'); and abtest_track_conversion('TEST CONVERSION ID'); performs the test itself
    ABTEST HEADLINES module gets the nodes of the Default Article (machine name 'blogs')and setting them for the test 
    ABTEST DASHBOARD in views fetching results and displays to the user

# TESTING THE ABTEST_HEADLINES MODULE #

    After successful installation and cms configuration create or edit Default Article with A/B test checkbox checked and all fields to be filled
    Than as our frontpage made from views blocks we are running the tests on abtest_headlines module load and checking wholle the content which meets requirements listed earlier   
1. Go to the front page from differend browsers and defferent ip addresses you should be able to see Headlines you are settuped for testing 
2. Go to reports in Admin -> Reports -> A/B Tests Results check the All results
3. Go in top the Article where A/B test is enaibled in Article tabs find A/B test tab with the particular Article test results
    