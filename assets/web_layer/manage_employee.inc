<?php

    if ($_SERVER["REQUEST_METHOD"] == "POST") {

        // Continue session
        //session_start();
        $_SESSION["Login"] = "true";

        // Include
        require_once dirname(__DIR__).'../interface_layer/employee_facade_remote.inc';

        $interface = new EmployeeFacadeRemote();
        

        //if($interface->is_empty($_POST['employeeID'])){
            //$interface->print_error();
        //}else{
            
        switch($_POST['employeeCRUD']){

            case 'create-employee':
                if($interface->is_create_valid($_POST)){
                    $interface->set_employee_DTO($interface->get_employee_DTO()->with_post($_POST));
                    if($interface->create_employee_record($interface->get_employee_DTO())){
                        $interface->set_error_message("Record was succeddfully created.");
                        $interface->print_error();
                    }else{
                        $interface->set_error_message("Record was not created. Please try again.");
                        $interface->print_error();
                    }
                }else{
                    $interface->print_error();
                }
                break;   

            case 'read-employee':
                if($interface->is_empty($_POST['employeeID'])){
                    $interface->print_error();
                }else{
                    $interface->read_employee_record('employeeID', $_POST['employeeID']);
                    if($interface->get_employee_facade()->get_employee_DAO()->get_employeeID() == NULL){
                        $interface->set_error_message("No record with employee ID of ".$_POST['employeeID']." was found.");
                        $interface->print_error();
                    }else{
                        $_SESSION['employee_ID'] = $interface->get_employee_facade()->get_employee_DAO()->get_employeeID();
                        $_SESSION['employee_password'] = $interface->get_employee_facade()->get_employee_DAO()->get_password();
                        $_SESSION['employee_name'] = $interface->get_employee_facade()->get_employee_DAO()->get_employeeName();
                        $_SESSION['employee_address'] = $interface->get_employee_facade()->get_employee_DAO()->get_address();
                        $_SESSION['employee_email'] = $interface->get_employee_facade()->get_employee_DAO()->get_email();
                        header ('location: display_employee.php');
                    }
                }
                break;  

            case 'update-employee':
                if($interface->is_empty($_POST['employeeID'])){
                    $interface->print_error();
                }elseif($interface->is_update_valid($_POST)){
                    $interface->set_employee_DTO($interface->get_employee_DTO()->with_post($_POST));
                    if($interface->update_employee_record($interface->get_employee_DTO())){
                        $interface->set_error_message("Record with employee ID of ".$interface->get_employee_DTO()->get_employeeID()." was updated.");
                        $interface->print_error();
                    }else{
                        $interface->set_error_message("No record with employee ID of ".$interface->get_employee_DTO()->get_employeeID()." was found.");
                        $interface->print_error();
                    }
                }else{
                    $interface->print_error();
                }
                break;

            case 'delete-employee':
                if($interface->is_empty($_POST['employeeID'])){
                    $interface->print_error();
                }else{
                    if($interface->delete_employee_record('employeeID', $_POST['employeeID'])){
                        $interface->set_error_message("Record with employee ID of ".$_POST['employeeID']." was deleted.");
                        $interface->print_error();
                    }else{
                        $interface->set_error_message("No record with employee ID of ".$_POST['employeeID']." was found.");
                        $interface->print_error();
                    }
                }
                break;
        }
        //header ("location: assets/web_layer/read-employee.php");
    //}

    }
?>
