<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $_SESSION["Login"] = "true";
        // Include
        require_once dirname(__DIR__).'../interface_layer/employee_facade_remote.inc';
        require_once dirname(__DIR__).'../interface_layer/product_facade_remote.inc';
        require_once dirname(__DIR__).'../interface_layer/member_facade_remote.inc';
        $employee_interface = new EmployeeFacadeRemote();
        $product_interface = new ProductFacadeRemote();  
        $member_interface = new MemberFacadeRemote();

        switch($_POST['CRUD']){
            case 'create-employee':
                if($employee_interface->is_create_valid($_POST)){
                    $employee_interface->set_employee_DTO($employee_interface->get_employee_DTO()->with_post($_POST));
                    if($employee_interface->create_employee_record($employee_interface->get_employee_DTO())){
                        $employee_interface->set_error_message("Record was successfully created.");
                        $employee_interface->print_error();
                    }else{
                        $employee_interface->set_error_message("Record was not created. Please try again.");
                        $employee_interface->print_error();
                    }
                }else{
                    $employee_interface->print_error();
                }
                break;   
            case 'read-employee':
                if($employee_interface->is_empty($_POST['employeeID'])){
                    $employee_interface->print_error();
                }else{
                    $employee_interface->read_employee_record('employeeID', $_POST['employeeID']);
                    if($employee_interface->get_employee_facade()->get_employee_DAO()->get_employeeID() == NULL){
                        $employee_interface->set_error_message("No record with employee ID of ".$_POST['employeeID']." was found.");
                        $employee_interface->print_error();
                    }else{
                        $_SESSION['employee_ID'] = $employee_interface->get_employee_facade()->get_employee_DAO()->get_employeeID();
                        $_SESSION['employee_password'] = $employee_interface->get_employee_facade()->get_employee_DAO()->get_password();
                        $_SESSION['employee_name'] = $employee_interface->get_employee_facade()->get_employee_DAO()->get_employeeName();
                        $_SESSION['employee_address'] = $employee_interface->get_employee_facade()->get_employee_DAO()->get_address();
                        $_SESSION['employee_email'] = $employee_interface->get_employee_facade()->get_employee_DAO()->get_email();
                        header ('location: display_employee.php');
                    }
                }
                break;  
            case 'update-employee':
                if($employee_interface->is_empty($_POST['employeeID'])){
                    $employee_interface->print_error();
                }elseif($employee_interface->is_update_valid($_POST)){
                    $employee_interface->set_employee_DTO($employee_interface->get_employee_DTO()->with_post($_POST));
                    if($employee_interface->update_employee_record($employee_interface->get_employee_DTO())){
                        $employee_interface->set_error_message("Record with employee ID of ".$employee_interface->get_employee_DTO()->get_employeeID()." was updated.");
                        $employee_interface->print_error();
                    }else{
                        $employee_interface->set_error_message("No record with employee ID of ".$employee_interface->get_employee_DTO()->get_employeeID()." was found.");
                        $employee_interface->print_error();
                    }
                }else{
                    $employee_interface->print_error();
                }
                break;
            case 'delete-employee':
                if($employee_interface->is_empty($_POST['employeeID'])){
                    $employee_interface->print_error();
                }else{
                    if($employee_interface->delete_employee_record('employeeID', $_POST['employeeID'])){
                        $employee_interface->set_error_message("Record with employee ID of ".$_POST['employeeID']." was deleted.");
                        $employee_interface->print_error();
                    }else{
                        $employee_interface->set_error_message("No record with employee ID of ".$_POST['employeeID']." was found.");
                        $employee_interface->print_error();
                    }
                }
                break;
            case 'create-member':   
                if($member_interface->is_create_valid($_POST)){
                    $member_interface->set_member_DTO($member_interface->get_member_DTO()->with_post($_POST));
                    if($member_interface->create_member_record($member_interface->get_member_DTO())){
                        $member_interface->set_error_message("Record was successfully created.");
                        $member_interface->print_error();
                    }else{
                        $member_interface->set_error_message("Record was not created. Please try again.");
                        $member_interface->print_error();
                    }
                }else{
                    $member_interface->print_error();
                }
                break;

            case 'create-product':
                if($product_interface->is_create_valid($_POST)){
                    $product_interface->set_product_DTO($product_interface->get_product_DTO()->with_post($_POST));
                    if($product_interface->create_product_record($product_interface->get_product_DTO())){
                        $product_interface->set_error_message("Record was succeddfully created.");
                        $product_interface->print_error();
                    }else{
                        $product_interface->set_error_message("Record was not created. Please try again.");
                        $product_interface->print_error();
                    }
                }else{
                    $product_interface->print_error();
                }
                break;  
        }
    }
?>
