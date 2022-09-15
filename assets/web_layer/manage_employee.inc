<?php

    if ($_SERVER["REQUEST_METHOD"] == "POST") {

        // Continue session
        //session_start();
        $_SESSION["Login"] = "true";

        // Include
        require_once dirname(__DIR__).'../interface_layer/employee_facade_remote.inc';

        $interface = new EmployeeFacadeRemote();

        if($interface->is_empty($_POST['employeeID'])){
            $interface->print_error();
        }else{
            
            switch($_POST['employeeCRUD']){
    
                case 'create-employee':
    
                    break;   
    
                case 'read-employee':
                    $interface->read_employee_record('employeeID', $_POST['employeeID']);
                    $_SESSION['employee_ID'] = $interface->get_employee_facade()->get_employee_DAO()->get_employeeID();
                    $_SESSION['employee_password'] = $interface->get_employee_facade()->get_employee_DAO()->get_password();
                    $_SESSION['employee_name'] = $interface->get_employee_facade()->get_employee_DAO()->get_employeeName();
                    $_SESSION['employee_address'] = $interface->get_employee_facade()->get_employee_DAO()->get_address();
                    $_SESSION['employee_email'] = $interface->get_employee_facade()->get_employee_DAO()->get_email();
                    header ('location: display_employee.php');
                    break;  
    
                case 'update-employee':
    
                    break;
    
                case 'delete-employee':
    
                    break;
            }
            //header ("location: assets/web_layer/read-employee.php");
        }

    }
?>
