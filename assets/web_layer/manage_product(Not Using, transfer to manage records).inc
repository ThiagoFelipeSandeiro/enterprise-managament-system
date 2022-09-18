<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $_SESSION["Login"] = "true";
        // Include
        require_once dirname(__DIR__).'../interface_layer/product_facade_remote.inc';
        $interface = new ProductFacadeRemote();  
        switch($_POST['productCRUD']){
            case 'create-product':
                if($interface->is_create_valid($_POST)){
                    $interface->set_product_DTO($interface->get_product_DTO()->with_post($_POST));
                    if($interface->create_product_record($interface->get_product_DTO())){
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
            case 'read-product':
                if($interface->is_empty($_POST['productID'])){
                    $interface->print_error();
                }else{
                    $interface->read_product_record('productID', $_POST['productID']);
                    if($interface->get_product_facade()->get_product_DAO()->get_productID() == NULL){
                        $interface->set_error_message("No record with product ID of ".$_POST['productID']." was found.");
                        $interface->print_error();
                    }else{
                        $_SESSION['product_ID'] = $interface->get_product_facade()->get_product_DAO()->get_productID();
                        $_SESSION['product_password'] = $interface->get_product_facade()->get_product_DAO()->get_password();
                        $_SESSION['product_name'] = $interface->get_product_facade()->get_product_DAO()->get_productName();
                        $_SESSION['product_address'] = $interface->get_product_facade()->get_product_DAO()->get_address();
                        $_SESSION['product_email'] = $interface->get_product_facade()->get_product_DAO()->get_email();
                        header ('location: display_product.php');
                    }
                }
                break;  
            case 'update-product':
                if($interface->is_empty($_POST['productID'])){
                    $interface->print_error();
                }elseif($interface->is_update_valid($_POST)){
                    $interface->set_product_DTO($interface->get_product_DTO()->with_post($_POST));
                    if($interface->update_product_record($interface->get_product_DTO())){
                        $interface->set_error_message("Record with product ID of ".$interface->get_product_DTO()->get_productID()." was updated.");
                        $interface->print_error();
                    }else{
                        $interface->set_error_message("No record with product ID of ".$interface->get_product_DTO()->get_productID()." was found.");
                        $interface->print_error();
                    }
                }else{
                    $interface->print_error();
                }
                break;
            case 'delete-product':
                if($interface->is_empty($_POST['productID'])){
                    $interface->print_error();
                }else{
                    if($interface->delete_product_record('productID', $_POST['productID'])){
                        $interface->set_error_message("Record with product ID of ".$_POST['productID']." was deleted.");
                        $interface->print_error();
                    }else{
                        $interface->set_error_message("No record with product ID of ".$_POST['productID']." was found.");
                        $interface->print_error();
                    }
                }
                break;
        }
    }
?>
