<?php

    if ($_SERVER["REQUEST_METHOD"] == "POST") {

        session_start();
        
        // Include
        require_once './assets/interface_layer/employee_facade_remote.inc';

        $interface = new EmployeeFacadeRemote();
        if($interface->is_login_valid($_POST)){
            $_SESSION["Login"] = "true";
            header ("location: home.php");
        }
    }
?>
