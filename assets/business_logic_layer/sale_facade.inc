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
        private $purchase_details_DAO_array;

        // Default Constructor
        function __construct(){
            $this->db_conn = new ConnectDB();
            $this->purchase_DAO = new PurchaseDAO();
            $this->purchase_details_DAO = new PurchaseDetailsDAO();
            $this->purchase_details_DAO_array = array();
        }

        // Default Destructor
        function __destruct() {
            //$this->db_conn->close_conn();
        }

        // METHOD
        function create_sale_record($purchase_DTO, $purchase_details_DTO){

            // Set DAOs
            $this->set_purchase_DAO($this->purchase_DTO2DAO($purchase_DTO));
            $this->set_purchase_details_DAO($this->purchase_details_DTO2DAO($purchase_details_DTO));

            // Get Stock Level for product
            $command = "SELECT IF(productQuantityOnHand > ".$this->purchase_details_DAO->get_quantity().", TRUE, FALSE) AS bool FROM product WHERE productID = ".$this->purchase_details_DAO->get_productID().";";
            $result = mysqli_query($this->db_conn->get_conn(), $command);
            if(!$result){
                return false;
            }
            $row = $result->fetch_assoc();

            if(!$row["bool"]){
                $result->free_result();
                //Stock too low
                echo '<script type="text/javascript">alert("Stock too low");</script>';
                return false;
            }
            
            // Turn autocommit off
            $this->db_conn->get_conn()->autocommit(FALSE);
            // Start Transaction
            $this->db_conn->get_conn()->begin_transaction();

            // Insert into purchase.
            $command = "INSERT INTO purchase (memberID) VALUES ('".$this->purchase_DAO->get_memberID()."');";
            if(!mysqli_query($this->db_conn->get_conn(), $command)){
                $this->db_conn->get_conn()->rollback();
                // Turn autocommit on
                $this->db_conn->get_conn()->autocommit(TRUE);
                return false;
            }
                        
            // Set purchaseID.
            $command = "INSERT INTO purchased_products (purchaseID, productID, quantity, subTotal) VALUES
                ( ".$this->db_conn->get_conn()->insert_id.",
                ".$this->purchase_details_DAO->get_productID()." ,
                ".$this->purchase_details_DAO->get_quantity()." ,
                (select p.productUnitCost from product AS p WHERE p.productID = 1)*".$this->purchase_details_DAO->get_quantity().");";
            if(!mysqli_query($this->db_conn->get_conn(), $command)){
                $this->db_conn->get_conn()->rollback();
                // Turn autocommit on
                $this->db_conn->get_conn()->autocommit(TRUE);
                return false;
            }

            // Get current stock level.
            $command = "SET @stock_level = (select productQuantityOnHand from product WHERE productID = ".$this->purchase_details_DAO->get_productID().");";
            if(!mysqli_query($this->db_conn->get_conn(), $command)){
                $this->db_conn->get_conn()->rollback();
                // Turn autocommit on
                $this->db_conn->get_conn()->autocommit(TRUE);
                return false;
            }
            // Set new stock level.
            $command = "UPDATE product AS p SET p.productQuantityOnHand = @stock_level - ".$this->purchase_details_DAO->get_quantity()." WHERE p.productID = ".$this->purchase_details_DAO->get_productID().";";
            if(!mysqli_query($this->db_conn->get_conn(), $command)){
                $this->db_conn->get_conn()->rollback();
                // Turn autocommit on
                $this->db_conn->get_conn()->autocommit(TRUE);
                return false;
            }
        
            /* If code reaches this point without errors then commit the data in the database */
            $this->db_conn->get_conn()->commit();
            // Turn autocommit on
            $this->db_conn->get_conn()->autocommit(TRUE);
            return true;
        }

        function read_sale_record($attribute, $search_string){
            $command = "SELECT * FROM purchase WHERE $attribute = '$search_string';";
            //Return the result from the query.
            $result = mysqli_query($this->db_conn->get_conn(), $command);
            $row = mysqli_fetch_assoc($result);
            if($row != NULL){
                
                $this->set_purchase_DAO($this->purchase_DAO->with_row($row));

                $command = "SELECT * FROM purchased_products WHERE $attribute = '$search_string';";
                //Return the result from the query.
                $result = mysqli_query($this->db_conn->get_conn(), $command);
                $row = mysqli_fetch_all($result);
                if($row != NULL){
                    for($i = 0; $i < count($row); $i++){
                        $this->purchase_details_DAO_array[$i] = new PurchaseDetailsDAO();
                        $this->purchase_details_DAO_array[$i] = $this->purchase_details_DAO->with_row_all($row[$i]);
                    }

                    return true;
                }else{
                    return false;
                }
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

        function export_to_csv(){
            echo "Placeholder. Function will export sales related tables to CSV";
            return true;
        }

        private function purchase_DAO2DTO($DAO){
            $instance = new PurchaseDTO();
            $instance->set_purchaseID($DAO->get_purchaseID());
            $instance->set_date($DAO->get_date());
            $instance->set_memberID($DAO->get_memberID());
            return $instance;
        }
        private function purchase_DTO2DAO($DTO){
            $instance = new PurchaseDAO();
            $instance->set_purchaseID($DTO->get_purchaseID());
            $instance->set_date($DTO->get_date());
            $instance->set_memberID($DTO->get_memberID());
            return $instance;
        }

        private function purchase_details_DAO2DTO($DAO){
            $instance = new PurchaseDetailsDTO();
            $instance->set_productID($DAO->get_productID());
            $instance->set_purchaseID($DAO->get_purchaseID());
            $instance->set_quantity($DAO->get_quantity());
            $instance->set_sub_total($DAO->get_sub_total());
            return $instance;
        }
        private function purchase_details_DTO2DAO($DTO){
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
        function get_purchase_DTO(){
            return $this->purchase_DAO2DTO($this->purchase_DAO);
        }
        function get_purchase_details_DTO(){
            return $this->purchase_details_DAO2DTO($this->purchase_details_DAO);
        }
        function get_purchase_details_DAO_array(){
            return $this->purchase_details_DAO_array;
        }
        function get_array_size(){
            return count($this->get_purchase_details_DAO_array());
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
