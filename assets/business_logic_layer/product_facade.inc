 <?php

    // Include
    require_once dirname(__DIR__).'/config/connect_db.inc';
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
            $this->db_conn->close_conn();
        }

        // METHOD
        function create_product_record(){

        }

        function read_product_record($attribute, $search_string){
            $command = "SELECT * FROM Product WHERE $attribute = '$search_string';";
            //Return the result from the query.
            $result = mysqli_query($this->db_conn->get_conn(), $command);
            $row = mysqli_fetch_assoc($result);
            if($row != NULL)
                $this->product_DAO = $this->product_DAO->with_row($row);
        }

        function update_product_record(){
            
        }

        function delete_product_record(){
            
	}

        function DAO2DTO($DAO){
            $instance = new ProductDTO();
	    $instance->set_productID($DAO->get_productID());
	    $instance->set_productName($DAO->get_productName());
	    $instance->set_productDescription($DAO->get_productDescription());
	    $instance->set_unitCost($DAO->get_unitCost());
	    $instance->set_quantityOnHand($DAO->get_quantityOnHand());
	    $instance->set_supplier($DAO->get_supplier());
            return $instance;
        }

        function DTO2DAO($DTO){
            
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
