<?php

    if ($_SERVER["REQUEST_METHOD"] == "POST") {

        session_start();
        
        // Include
        require_once '../interface_layer/employee_facade_remote.inc';

        $interface = new EmployeeFacadeRemote();
        $interface->is_empty($_POST["email"]);


        //Check if email is empty.
        if (empty($_POST["email"])) {
            //Add error message.
            $error_message .= "<li>You must enter your email.</li>";
        } else {
            //Sanitise data before storing it in varible.
            $email = sanitise_input($_POST["email"]);
        }
        
        //Check email matches regex.
        if (!preg_match("/^[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*@[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*$/", $email)){
            //Add error message.
            $error_message .= "<li>Your email doesn't match the required format.</li>";
        }
        //Check if Password is empty.
        if (empty($_POST["password"])) {
            //Add error message.
            $error_message .= "<li>You must enter your password.</li>";
        } else {
            //Sanitise data before storing it in varible.
            $password = sanitise_input($_POST["password"]);
        }
        //Check Password matches regex.
        if (!preg_match("/^\S*(?=\S{8,})(?=\S*[a-z])(?=\S*[A-Z])(?=\S*[\d])(?=\S*[\W])\S*$/", $password)){
            //Add error message.
            $error_message .= "<li>Your password doesn't match the required format.</li>";
        }

        // Check Auth
        $interface->read_employee_record('email', $email);
        if ($interface->get_employee_DTO()->get_password() != $password) {
            //error
            $error_message .= "<li>Access not granted.</li>";
        }

        //Check if error message exsits.
        if ($error_message != "") {
            //Print error message.
            echo "<div id='scrnOverlay' style='display:block;'>
                    <section id='errWin' class='window' style='display:block;'>
                    <ul id='ul-err' style='text-align:center;padding: 0;'>
                        $error_message
                    </ul>
                    <br/>
                    <a href='employee_login.php' style='position:relative;vertical-align:super;'><button type='button' id='errBtn' class='btn'>Okay</button></a>
                    </section>
                </div>";
        }else {
            $_SESSION["Login"] = "true";
            header ("location: home.php");
        }
        //Close DB connection.
        $interface->get_db_conn()->close_conn();
    }
?>
