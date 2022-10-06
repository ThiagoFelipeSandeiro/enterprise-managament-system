 <?php

    // Include
    require_once dirname(__DIR__).'/config/settings.inc';
    require_once dirname(__DIR__).'/entities/data_access_layer/purchase_DAO.inc';
    require_once dirname(__DIR__).'/entities/data_access_layer/purchase_details_DAO.inc';
    require_once dirname(__DIR__).'/entities/data_transfer_layer/purchase_DTO.inc';
    require_once dirname(__DIR__).'/entities/data_transfer_layer/purchase_details_DTO.inc';

    class SaleFacade {

        // Private Fields
        private $db_conn;
        private $purchase_DAO;
        private $purchase_details_DAO;

        // Default Constructor
        function __construct(){
            $this->db_conn = new ConnectDB();
            $this->product_DAO = new PurchaseDAO();
            $this->purchase_details_DAO = new PurchaseDetailsDAO();
        }

        // Default Destructor
        function __destruct() {
            //$this->db_conn->close_conn();
        }

        // METHOD
        function create_sale_record($purchase_DTO, $purchase_details_DTO){
            $bool = [false,false];
            $this->set_purchase_DAO($this->purchase_DTO2DAO($purchase_DTO));
            $command = "INSERT INTO purchase (memberID) VALUES ('".$this->purchase_DAO->get_memberID()."');";
            // get result from the query.
            if(mysqli_query($this->db_conn->get_conn(), $command)){
                $this->purchase_details_DAO->set_purchaseID($this->db_conn->get_conn()->insert_id);
                $bool[0] = true;

                $this->set_purchase_details_DAO($this->purchase_details_DTO2DAO($purchase_details_DTO));
                $command = "INSERT INTO purchased_products (purchaseID, productID, quantity, subTotal) VALUES ('
                ".$this->purchase_details_DAO->get_purchaseID()."',
                ".$this->purchase_details_DAO->get_productID()."',
                ".$this->purchase_details_DAO->get_quantity()."',
                ".$this->purchase_details_DAO->get_sub_total()."'
                );";
                // get result from the query.
                if(mysqli_query($this->db_conn->get_conn(), $command)){
                    $bool[1] = true;
                }
            }

            //Return the result from the query.
            return $bool[0] && $bool[1];
        }

        function read_product_record($attribute, $search_string){
            $command = "SELECT * FROM product WHERE $attribute = '$search_string';";
            //Return the result from the query.
            $result = mysqli_query($this->db_conn->get_conn(), $command);
            $row = mysqli_fetch_assoc($result);
            if($row != NULL){
                $this->product_DAO = $this->product_DAO->with_row($row);
                return true;
            }else{
                return false;
            }
        }

        function update_product_record($DTO){
            if(!$this->read_product_record('productID', $DTO->get_productID())){
                return false;
            }else{
                if(!empty($DTO->get_productName())){
                    $this->product_DAO->set_productName($DTO->get_productName());
                }
                if(!empty($DTO->get_productDescription())){
                    $this->product_DAO->set_productDescription($DTO->get_productDescription());
                }
                if($DTO->get_productUnitCost() > 0){
                    $this->product_DAO->set_productUnitCost($DTO->get_productUnitCost());
                }
                if($DTO->get_productQuantityOnHand() >= 0){
                    $this->product_DAO->set_productQuantityOnHand($DTO->get_productQuantityOnHand());
                }
                if(!empty($DTO->get_productSupplier())){
                    $this->product_DAO->set_productSupplier($DTO->get_productSupplier());
                }
                $command = "UPDATE Product 
                    SET productName = '".$this->product_DAO->get_productName()."',
                    description = '".$this->product_DAO->get_productDescription()."',
                    unitCost = '".$this->product_DAO->get_productUnitCost()."',
                    quantityOnHand = '".$this->product_DAO->get_productQuantityOnHand()."',
                    supplier = '".$this->product_DAO->get_productSupplier()."'
                    WHERE productID = '".$this->product_DAO->get_productID()."';";
                //Return the result from the query.
                if(mysqli_query($this->db_conn->get_conn(), $command)){
                    return true;
                }else{
                    return false;
                }
            }
        }

        function delete_product_record($attribute, $search_string){
            if(!$this->read_product_record($attribute, $search_string)){
                return false;
            }else{
                $command = "DELETE FROM Product WHERE $attribute = '$search_string';";
                //Return the result from the query.
                if(mysqli_query($this->db_conn->get_conn(), $command)){
                    return true;
                }else{
                    return false;
                }
            }
            
	    }

        function purchase_DAO2DTO($DAO){
            $instance = new PurchaseDTO();
            $instance->set_purchaseID($DAO->get_purchaseID());
            $instance->set_date($DAO->get_date());
            $instance->set_memberID($DAO->get_memberID());
            return $instance;
        }
        function purchase_DTO2DAO($DTO){
            $instance = new PurchaseDAO();
            $instance->set_purchaseID($DTO->get_purchaseID());
            $instance->set_date($DTO->get_date());
            $instance->set_memberID($DTO->get_memberID());
            return $instance;
        }

        function purchase_details_DAO2DTO($DAO){
            $instance = new PurchaseDetailsDTO();
            $instance->set_productID($DAO->get_productID());
            $instance->set_purchaseID($DAO->get_purchaseID());
            $instance->set_quantity($DAO->get_quantity());
            $instance->set_sub_total($DAO->get_sub_total());
            return $instance;
        }
        function purchase_details_DTO2DAO($DTO){
            $instance = new PurchaseDetailsDAO();
            $instance->set_productID($DTO->get_productID());
            $instance->set_purchaseID($DTO->get_purchaseID());
            $instance->set_quantity($DTO->get_quantity());
            $instance->set_sub_total($DTO->get_sub_total());
            return $instance;
        }

        // Getters
        function get_db_conn(){
            return $this->db_conn;
        }
        function get_purchase_DAO(){
            return $this->purchase_DAO;
        }
        function get_purchase_details_DAO(){
            return $this->purchase_details_DAO;
        }
        // Setters
        function set_db_conn($db_conn) {
            $this->db_conn = $db_conn;
        }
        function set_purchase_DAO($purchase_DAO) {
            $this->purchase_DAO = $purchase_DAO;
        }
        function set_purchase_details_DAO($purchase_details_DAO) {
            $this->purchase_details_DAO = $purchase_details_DAO;
        }
    }

?> 
