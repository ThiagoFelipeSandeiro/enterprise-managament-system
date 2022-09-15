<?php

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        
        // Include
        require_once './assets/interface_layer/employee_facade_remote.inc';

        $interface = new EmployeeFacadeRemote();
        $_SESSION["interface"] = $interface;
        if($interface->is_login_valid($_POST)){
            $_SESSION["Login"] = "true";
            header ("location: assets/web_layer/home.php");
        }
    }
?>
