<?php

/**
 * @file
 * __loader class
 */
class __loader {
    public static function loadLibrary($class_name) {

        $searchdir = array();
        $profile = drupal_get_path('profile', drupal_get_profile());
        $config = conf_path();

        // Similar to 'modules' and 'themes' directories in the root directory,
        // certain distributions may want to place libraries into a 'libraries'
        // directory in Drupal's root directory.
        $searchdir[] = 'libraries';

        // Similar to 'modules' and 'themes' directories inside an installation
        // profile, installation profiles may want to place libraries into a
        // 'libraries' directory.
        $searchdir[] = "$profile/libraries";

        // Always search sites/all/libraries.
        $searchdir[] = 'sites/all/libraries';

        // Also search sites/<domain>/*.
        $searchdir[] = "$config/libraries";

        foreach ($searchdir as $dir) {
            $library_path = $_SERVER["DOCUMENT_ROOT"] . "/" . $dir . "/" . $class_name . "/" . $class_name . ".php";
            if (file_exists($library_path)) {
                require_once($library_path);
                return TRUE;
            }
        }
        return FALSE;
    }
}