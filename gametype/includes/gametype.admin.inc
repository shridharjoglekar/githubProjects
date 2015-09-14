<?php
/**
 * @file
 * The file for admin forms and functionality for the gametype entity
 */

/**
 * Implements hook_form().
 */
function gametype_form($form, &$form_state, $gametype = NULL) {
    $form = array();

    $form['name'] = array(
        '#title' => t('Name'),
        '#type' => 'textfield',
        '#default_value' => isset($gametype->name) ? $gametype->name : '',
        '#description' => t('Provide gametype name.'),
        '#required' => TRUE,
        '#maxlength' => 255,
    );

    $form['description'] = array(
        '#title' => t('Description'),
        '#type' => 'textfield',
        '#default_value' => isset($gametype->description) ? $gametype->description : '',
        '#required' => TRUE,
        '#maxlength' => 255,
    );


    field_attach_form('gametype', $gametype, $form, $form_state);

    $form['actions'] = array(
        '#type' => 'actions',
        'submit' => array(
            '#type' => 'submit',
            '#value' => isset($gametype->id) ? t('Update Gametype') : t('Save Gametype'),
        ),
        'delete_link' => array(
            '#markup' => isset($gametype->id) ? l(t('Delete'), 'admin/content/gametype/manage/' . $gametype->id . '/delete', array('attributes' => array('id' => array('gametype-delete-' . $gametype->id), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/gametype'))) : ''));
    return $form;
}

/**
 * Implements hook_form_validate().
 */
function gametype_form_validate($form, &$form_state) {
}

/**
 * Implements hook_form_submit().
 */
function gametype_form_submit($form, &$form_state) {
    $gametype = entity_ui_form_submit_build_entity($form, $form_state);
    $gametype->save();
    drupal_set_message(t('@name gametype has been saved.', array('@name' => $gametype->name)));
    // $form_state['redirect'] = 'admin/content/gametype';
    $form_state['redirect'] = 'gametype/' . $gametype->id;
}

/**
 * Confirmation before bulk deleting gametype.
 */
function gametype_bulk_delete($form, &$form_state, $gametype_ids) {
    $gametype_ids = explode('|', $gametype_ids);
    $gametype = gametype_load_multiple($gametype_ids);

    $form = array();
    $form_state['gametype_ids'] = $gametype_ids;

    $variables = array(
        'type' => 'ul',
        'items' => array(),
        'title' => '',
        'attributes' => array(),
    );

    foreach ($gametype as $record) {
        $variables['items'][] = $record->name;
    }

    $form['summary'] = array(
        '#markup' => theme_item_list($variables),
    );

    return confirm_form($form, t('Delete all gametype?'), 'admin/content/gametype', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function gametype_bulk_delete_submit($form, &$form_state) {
    $gametype_ids = $form_state['gametype_ids'];
    gametype_delete_multiple($gametype_ids);

    drupal_set_message(t('gametype deleted'));
    drupal_goto('admin/content/gametype');
}
