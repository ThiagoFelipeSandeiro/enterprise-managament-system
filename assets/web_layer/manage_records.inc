<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $_SESSION["Login"] = "true";
        // Include
        require_once dirname(__DIR__).'../interface_layer/employee_facade_remote.inc';
        require_once dirname(__DIR__).'../interface_layer/product_facade_remote.inc';
        require_once dirname(__DIR__).'../interface_layer/member_facade_remote.inc';
        require_once dirname(__DIR__).'../interface_layer/sale_facade_remote.inc';
        $employee_interface = new EmployeeFacadeRemote();
        $product_interface = new ProductFacadeRemote();  
        $member_interface = new MemberFacadeRemote();
        $sale_interface = new SaleFacadeRemote();

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
            case 'export-employee':
                $employee_interface->export_to_csv();
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
            case 'read-member':
                if($member_interface->is_empty($_POST['memberID'])){
                    $member_interface->print_error();
                }else{
                    $member_interface->read_member_record('memberID', $_POST['memberID']);
                    if($member_interface->get_member_facade()->get_member_DAO()->get_memberID() == NULL){
                        $member_interface->set_error_message("No record with member ID of ".$_POST['memberID']." was found.");
                        $member_interface->print_error();
                    }else{
                        $_SESSION['member_ID'] = $member_interface->get_member_facade()->get_member_DAO()->get_memberID();
                        $_SESSION['member_name'] = $member_interface->get_member_facade()->get_member_DAO()->get_memberName();
                        $_SESSION['member_address'] = $member_interface->get_member_facade()->get_member_DAO()->get_memberAddress();
                        $_SESSION['member_email'] = $member_interface->get_member_facade()->get_member_DAO()->get_memberEmail();
                        header ('location: display_member.php');
                    }
                }
                break;  
            case 'update-member':
                if($member_interface->is_empty($_POST['memberID'])){
                    $member_interface->print_error();
                }elseif($member_interface->is_update_valid($_POST)){
                    $member_interface->set_member_DTO($member_interface->get_member_DTO()->with_post($_POST));
                    if($member_interface->update_member_record($member_interface->get_member_DTO())){
                        $member_interface->set_error_message("Record with member ID of ".$member_interface->get_member_DTO()->get_memberID()." was updated.");
                        $member_interface->print_error();
                    }else{
                        $member_interface->set_error_message("No record with member ID of ".$member_interface->get_member_DTO()->get_memberID()." was found.");
                        $member_interface->print_error();
                    }
                }else{
                    $member_interface->print_error();
                }
                break;
            case 'delete-member':
                if($member_interface->is_empty($_POST['memberID'])){
                    $member_interface->print_error();
                }else{
                    if($member_interface->delete_member_record('memberID', $_POST['memberID'])){
                        $member_interface->set_error_message("Record with member ID of ".$_POST['memberID']." was deleted.");
                        $member_interface->print_error();
                    }else{
                        $member_interface->set_error_message("No record with member ID of ".$_POST['memberID']." was found.");
                        $member_interface->print_error();
                    }
                }
                break;
           case 'export-member':
                $member_interface->export_to_csv();
                break;

            case 'create-product':
                if($product_interface->is_create_valid($_POST)){
                    $product_interface->set_product_DTO($product_interface->get_product_DTO()->with_post($_POST));
                    if($product_interface->create_product_record($product_interface->get_product_DTO())){
                        $product_interface->set_error_message("Record was successfully created.");
                        $product_interface->print_error();
                    }else{
                        $product_interface->set_error_message("Record was not created. Please try again.");
                        $product_interface->print_error();
                    }
                }else{
                    $product_interface->print_error();
                }
                break;  
            case 'read-product':
                if($product_interface->is_empty($_POST['productID'])){
                    $product_interface->print_error();
                }else{
                    $product_interface->read_product_record('productID', $_POST['productID']);
                    if($product_interface->get_product_facade()->get_product_DAO()->get_productID() == NULL){
                        $product_interface->set_error_message("No record with product ID of ".$_POST['productID']." was found.");
                        $product_interface->print_error();
                    }else{
                        $_SESSION['product_ID'] = $product_interface->get_product_facade()->get_product_DAO()->get_productID();
                        $_SESSION['product_name'] = $product_interface->get_product_facade()->get_product_DAO()->get_productName();
                        $_SESSION['product_description'] = $product_interface->get_product_facade()->get_product_DAO()->get_productDescription();
                        $_SESSION['product_unitCost'] = $product_interface->get_product_facade()->get_product_DAO()->get_productUnitCost();
                        $_SESSION['product_quantityOnHand'] = $product_interface->get_product_facade()->get_product_DAO()->get_productQuantityOnHand();
                        $_SESSION['product_supplier'] = $product_interface->get_product_facade()->get_product_DAO()->get_productSupplier();
                        header ('location: display_product.php');
                    }
                }
                break; 
            case 'update-product':
                if($product_interface->is_empty($_POST['productID'])){
                    $product_interface->print_error();
                }elseif($product_interface->is_update_valid($_POST)){
                    $product_interface->set_product_DTO($product_interface->get_product_DTO()->with_post($_POST));
                    if($product_interface->update_product_record($product_interface->get_product_DTO())){
                        $product_interface->set_error_message("Record with product ID of ".$product_interface->get_product_DTO()->get_productID()." was updated.");
                        $product_interface->print_error();
                    }else{
                        $product_interface->set_error_message("No record with product ID of ".$product_interface->get_product_DTO()->get_productID()." was found.");
                        $product_interface->print_error();
                    }
                }else{
                    $product_interface->print_error();
                }
                break;
            case 'delete-product':
                if($product_interface->is_empty($_POST['productID'])){
                    $product_interface->print_error();
                }else{
                    if($product_interface->delete_product_record('productID', $_POST['productID'])){
                        $product_interface->set_error_message("Record with product ID of ".$_POST['productID']." was deleted.");
                        $product_interface->print_error();
                    }else{
                        $product_interface->set_error_message("No record with product ID of ".$_POST['productID']." was found.");
                        $product_interface->print_error();
                    }
                }
                break;
            case 'export-product':
                $product_interface->export_to_csv();
                break;

            // Create Sale
            case 'create-sale':
                if($sale_interface->is_create_valid($_POST)){
                    $sale_interface->set_purchase_DTO($sale_interface->get_purchase_DTO()->with_post($_POST));
                    $sale_interface->set_purchase_details_DTO($sale_interface->get_purchase_details_DTO()->with_post($_POST));
                    if($sale_interface->create_sale_record($sale_interface->get_purchase_DTO(), $sale_interface->get_purchase_details_DTO())){
                        $sale_interface->set_error_message("Record was successfully created.");
                        $sale_interface->print_error();
                    }else{
                        $sale_interface->set_error_message("Record was not created. Please try again.");
                        $sale_interface->print_error();
                    }
                }else{
                    $sale_interface->print_error();
                }
                break;

            // Display Sale
            case 'read-sale':
                if($sale_interface->is_empty($_POST['purchaseID'])){
                    $sale_interface->print_error();
                }else{
                    if(!$sale_interface->read_sale_record('purchaseID', $_POST['purchaseID'])){
                        $sale_interface->set_error_message("No record with purchase ID of ".$_POST['purchaseID']." was found.");
                        $sale_interface->print_error();
                    }else{
                        // Get Purchase Details
                        $_SESSION['purchase_ID'] = $sale_interface->get_sale_facade()->get_purchase_DTO()->get_purchaseID();
                        $_SESSION['date'] = $sale_interface->get_sale_facade()->get_purchase_DTO()->get_date();
                        $_SESSION['member_ID'] = $sale_interface->get_sale_facade()->get_purchase_DTO()->get_memberID();
                        
                        // Get Purchased Products Details
                        $new_object = [];
                        $arr = $sale_interface->get_sale_facade()->get_purchase_details_DAO_array();

                        for($i=0;$i<count($arr); $i++){

                            $_SESSION['product_ID'] = $arr[$i]->get_productID();
                            echo $arr[$i]->get_productID();
                            $_SESSION['product_quantity'] = $arr[$i]->get_quantity();
                            $_SESSION['product_sub_total'] = $arr[$i]->get_sub_total();
                            // Get Product Details
                            $product_interface->read_product_record('productID', $_SESSION['product_ID']);
                            echo $_SESSION['product_ID'];
                            echo $product_interface->get_product_facade()->get_product_DAO()->get_productID();
                            $_SESSION['product_name'] = $product_interface->get_product_facade()->get_product_DAO()->get_productName();
                            $_SESSION['product_description'] = $product_interface->get_product_facade()->get_product_DAO()->get_productDescription();
                            $_SESSION['product_unitCost'] = $product_interface->get_product_facade()->get_product_DAO()->get_productUnitCost();
                            // push to array
                            $new_object[$i] = array( $_SESSION['product_ID'], $_SESSION['product_name'],  $_SESSION['product_description'], $_SESSION['product_unitCost'], $_SESSION['product_quantity'], $_SESSION['product_sub_total']);
                        }
                        // Session Array
                        $_SESSION['basket'] = array_values($new_object);

                        // Get Member Details
                        $member_interface->read_member_record('memberID', $_SESSION['member_ID']);
                        $_SESSION['member_name'] = $member_interface->get_member_facade()->get_member_DAO()->get_memberName();
                        $_SESSION['member_address'] = $member_interface->get_member_facade()->get_member_DAO()->get_memberAddress();
                        $_SESSION['member_email'] = $member_interface->get_member_facade()->get_member_DAO()->get_memberEmail();
                        
                        header ('location: display_sale.php');
                    }
                }
                break;

            case 'update-sale':
                 if($sale_interface->is_empty($_POST['purchaseID'])){
                    $sale_interface->print_error();
                }elseif($sale_interface->is_update_valid($_POST)){
                    $sale_interface->set_purchase_DTO($sale_interface->get_purchase_DTO()->with_post($_POST));
                    if($sale_interface->update_sale_record($sale_interface->get_purchase_DTO())){
                        $sale_interface->set_error_message("Record with sale ID of ".$sale_interface->get_purchase_DTO()->get_purchaseID()." was updated.");
                        $sale_interface->print_error();
                    }else{
                        $sale_interface->set_error_message("No record with sale ID of ".$sale_interface->get_purchase_DTO()->get_purchaseID()." was found.");
                        $sale_interface->print_error();
                    }
                }else{
                    $sale_interface->print_error();
                }
                break;

            case 'delete-sale':
                if($sale_interface->is_empty($_POST['purchaseID'])){
                    $sale_interface->print_error();
                }else{
                    if($sale_interface->delete_sale_record('purchaseID', $_POST['purchaseID'])){
                        $sale_interface->set_error_message("Record with purchase ID of ".$_POST['purchaseID']." was deleted.");
                        $sale_interface->print_error();
                    }else{
                        $sale_interface->set_error_message("No record with purchase ID of ".$_POST['purchaseID']." was found.");
                        $sale_interface->print_error();
                    }
                }
                break;

            case 'export-purchase':
                $sale_interface->export_purchase_to_csv();
                break;
            case 'export-purchase-details':
                $sale_interface->export_purchase_details_to_csv();
                break;
        }
    }
?>
