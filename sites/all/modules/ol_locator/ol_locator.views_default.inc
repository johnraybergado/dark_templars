<?php
/**
 * @file
 * ol_locator.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ol_locator_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ol_locator_proximity_search';
  $view->description = 'Displays geocoded locations on a dynamic map for users to do proximity searches.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OpenLayers Locator proximity search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Locations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Find a location near you. You can search using your <strong>City, Province/State</strong> or your <strong>Postal/Zip code.</strong>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = '<strong>Sorry, no results found:</strong>

1. Verify the accuracy of your postal/zip code;
2. Check the spelling of your city, province or state; or 
3. Increase the proximity distance.
';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_ol_locator_address']['id'] = 'field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['table'] = 'field_data_field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['field'] = 'field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['label'] = '';
  $handler->display->display_options['fields']['field_ol_locator_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_address']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_ol_locator_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_ol_locator_geofield']['id'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['table'] = 'field_data_field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ol_locator_geofield']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Geofield - proximity */
  $handler->display->display_options['fields']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['fields']['field_geofield_distance']['table'] = 'field_data_field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['fields']['field_geofield_distance']['label'] = 'Distance';
  $handler->display->display_options['fields']['field_geofield_distance']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['field_geofield_distance']['precision'] = '2';
  $handler->display->display_options['fields']['field_geofield_distance']['suffix'] = 'Km';
  $handler->display->display_options['fields']['field_geofield_distance']['source'] = 'exposed_geofield_filter';
  $handler->display->display_options['fields']['field_geofield_distance']['geofield_proximity_manual'] = array(
    'lat' => '',
    'lon' => '',
  );
  $handler->display->display_options['fields']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_geofield_distance']['radius_of_earth'] = '6371';
  /* Sort criterion: Content: Geofield - proximity */
  $handler->display->display_options['sorts']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['table'] = 'field_data_field_ol_locator_geofield';
  $handler->display->display_options['sorts']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['source'] = 'exposed_geofield_filter';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_manual'] = array(
    'lat' => '',
    'lon' => '',
  );
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'field_ol_locator_geofield';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ol_locator_location' => 'ol_locator_location',
  );
  /* Filter criterion: Content: Geofield - proximity */
  $handler->display->display_options['filters']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['table'] = 'field_data_field_ol_locator_geofield';
  $handler->display->display_options['filters']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['operator'] = '<=';
  $handler->display->display_options['filters']['field_geofield_distance']['value'] = array(
    'distance' => '',
    'distance2' => 200,
    'unit' => '6371',
    'origin' => ' ',
  );
  $handler->display->display_options['filters']['field_geofield_distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['operator_id'] = 'field_geofield_distance_op';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['label'] = 'Proximity';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['operator'] = 'field_geofield_distance_op';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['identifier'] = 'field_geofield_distance';
  $handler->display->display_options['filters']['field_geofield_distance']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_geofield_distance']['source'] = 'geocoder';
  $handler->display->display_options['filters']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['filters']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'field_ol_locator_geofield';

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_ol_locator_geofield',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => '',
    'description_field' => '#row',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'ol_locator_proximity_search_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['path'] = 'locator';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Locator';
  $handler->display->display_options['menu']['description'] = 'Find a location near you.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_ol_locator_address' => 'field_ol_locator_address',
    'field_ol_locator_geofield' => 'field_ol_locator_geofield',
    'distance' => 'distance',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_ol_locator_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_ol_locator_geofield' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'distance' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_ol_locator_address']['id'] = 'field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['table'] = 'field_data_field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['field'] = 'field_ol_locator_address';
  $handler->display->display_options['fields']['field_ol_locator_address']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_ol_locator_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_ol_locator_geofield']['id'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['table'] = 'field_data_field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ol_locator_geofield']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ol_locator_geofield']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_ol_locator_geofield']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Geofield - proximity */
  $handler->display->display_options['fields']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['fields']['field_geofield_distance']['table'] = 'field_data_field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['fields']['field_geofield_distance']['label'] = 'Distance';
  $handler->display->display_options['fields']['field_geofield_distance']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['field_geofield_distance']['precision'] = '2';
  $handler->display->display_options['fields']['field_geofield_distance']['suffix'] = 'Km';
  $handler->display->display_options['fields']['field_geofield_distance']['source'] = 'exposed_geofield_filter';
  $handler->display->display_options['fields']['field_geofield_distance']['geofield_proximity_manual'] = array(
    'lat' => '',
    'lon' => '',
  );
  $handler->display->display_options['fields']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'field_ol_locator_geofield';
  $handler->display->display_options['fields']['field_geofield_distance']['radius_of_earth'] = '6371';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'block_1' => 'block_1',
    'default' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;
  $handler->display->display_options['render_pager'] = TRUE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'ol_locator_proximity_search_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['ol_locator_proximity_search'] = $view;

  return $export;
}
