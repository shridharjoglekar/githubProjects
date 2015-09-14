<?php
/**
 * @file
 * gametype.theme.inc
 */

/**
 * Theme gametype full page.
 */
function theme_gametype_full($variables) {
    $output = '';
    $gametype = $variables['gametype'];


    $output .= '<div class="gametype_meta">';

    // Lazy...

    $output .= '<div class="gametype-name">' . trim($gametype->name) . '</div>';
    if (!empty($gametype->description)) {
        $output .= '<div class="description">' . $gametype->description . '</div>';
    }


    if (user_access('administer gametype entities') && isset($gametype->id)) {
        $edit_link = '<ul class="tabs primary"><li>';
        $edit_link .= l(t('Edit'), 'admin/content/gametype/manage/' . $gametype->id, array('attributes' => array('class' => 'admin-edit-link')));
        $edit_link .= '</li></ul>';
        $output .= $edit_link;
    }

    $output .= '</div>';

    return $output;
}
