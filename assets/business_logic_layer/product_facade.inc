 <?php

    // Include
    require_once dirname(__DIR__).'\config\settings.inc';
    require_once dirname(__DIR__).'/entities/data_transfer_layer/product_DTO.inc';
    require_once dirname(__DIR__).'/entities/data_access_layer/product_DAO.inc';

    class ProductFacade {

        // Private Fields
        private $db_conn;
        private $product_DAO;

        // Default Constructor
        function __construct(){
            $this->db_conn = new ConnectDB();
            $this->product_DAO = new ProductDAO();
        }

        // Default Destructor
        function __destruct() {
            //$this->db_conn->close_conn();
        }

        // METHOD
        function create_product_record($DTO){
            $this->set_product_DAO($this->DTO2DAO($DTO));
            $command = "INSERT INTO Product (productName, description, unitCost, quantityOnHand, supplier) VALUES 
            ('".$this->product_DAO->get_productName()."',
            '".$this->product_DAO->get_productDescription()."',
            ".$this->product_DAO->get_productUnitCost().",
            ".$this->product_DAO->get_productQuantityOnHand().",
            '".$this->product_DAO->get_productSupplier()."');";
            //Return the result from the query.
            if(mysqli_query($this->db_conn->get_conn(), $command)){
                return true;
            }else{
                return false;
            }
        }

        function read_product_record($attribute, $search_string){
            $command = "SELECT * FROM Product WHERE $attribute = '$search_string';";
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

        function DAO2DTO($DAO){
            $instance = new ProductDTO();
            $instance->set_productID($DAO->get_productID());
            $instance->set_productName($DAO->get_productName());
            $instance->set_productDescription($DAO->get_productDescription());
            $instance->set_productUnitCost($DAO->get_productUnitCost());
            $instance->set_productQuantityOnHand($DAO->get_productQuantityOnHand());
            $instance->set_productSupplier($DAO->get_productSupplier());
            return $instance;
        }

        function DTO2DAO($DTO){
            $instance = new ProductDAO();
            $instance->set_productID($DTO->get_productID());
            $instance->set_productName($DTO->get_productName());
            $instance->set_productDescription($DTO->get_productDescription());
            $instance->set_productUnitCost($DTO->get_productUnitCost());
            $instance->set_productQuantityOnHand($DTO->get_productQuantityOnHand());
            $instance->set_productSupplier($DTO->get_productSupplier());
            return $instance;
        }

        // Getters
        function get_db_conn(){
            return $this->db_conn;
        }

        function get_product_DAO(){
            return $this->product_DAO;
        }

        // Setters
        function set_db_conn($db_conn) {
            $this->db_conn = $db_conn;
        }

        function set_product_DAO($product_DAO) {
            $this->product_DAO = $product_DAO;
        }

    }

?> 
