 <?php
    class ProductDTO {
        // Private Fields
        private $productID;
        private $productName;
        private $productDescription;
        private $productUnitCost;
        private $productQuantityOnHand;
        private $productSupplier;
        // Default Constructor
        function __construct() {
            $this->productID = "";
            $this->productName = "";
            $this->productDescription = "";
            $this->productUnitCost = 0;
	        $this->productQuantityOnHand = 0;
	        $this->productSupplier = "";
        }
        // Custom Constructor
        public static function with_row($row) {
            $instance = new self();
            $instance->set_productID($row['productID']);
            $instance->set_productName($row['productName']);
            $instance->set_productDescription($row['productDescription']);
            $instance->set_productUnitCost($row['productUnitCost']);
	        $instance->set_productQuantityOnHand($row['productQuantityOnHand']);
	        $instance->set_productSupplier($row['productSupplier']);
            return $instance;
        }
        // Custom Constructor
        public static function with_post($post) {
            $instance = new self();
            $instance->set_productID($post['productID']);
            $instance->set_productName($post['productName']);
            $instance->set_productDescription($post['productDescription']);
            $instance->set_productUnitCost($post['productUnitCost']);
	        $instance->set_productQuantityOnHand($post['productQuantityOnHand']);
	        $instance->set_productSupplier($post['productSupplier']);
            return $instance;
	    }
        // Getters
        function get_productID(){
            return $this->productID;
        }
        function get_productName(){
            return $this->productName;
        }
        function get_productDescription(){
            return $this->productDescription;
        }
        function get_productUnitCost(){
            return $this->productUnitCost;
        }
        function get_productQuantityOnHand(){
            return $this->productQuantityOnHand;
	    }
	    function get_productSupplier(){
		    return $this->productSupplier;
	    }
        // Setters
        function set_productID($productID) {
            if(!empty($productID)){
	    	    $this->productID = $this->sanitise_input($productID);
	        }
	    }
        function set_productName($productName) {
            if(!empty($productName)){
	    	    $this->productName = $this->sanitise_input($productName);
	        }
	    }
        function set_productDescription($productDescription) {
            if(!empty($productDescription)){
	    	    $this->productDescription = $this->sanitise_input($productDescription);
	        }
	    }
        function set_productUnitCost($productUnitCost) {
            if(!empty($productUnitCost)){
	    	    $this->productUnitCost = $this->sanitise_input($productUnitCost);
	        }
	    }
        function set_productQuantityOnHand($productQuantityOnHand) {
            if(!empty($productQuantityOnHand)){
	    	    $this->productQuantityOnHand = $this->sanitise_input($productQuantityOnHand);
	        }
	    }
        function set_productSupplier($productSupplier) {
            if(!empty($productSupplier)){
	    	    $this->productSupplier = $this->sanitise_input($productSupplier);
	        }
	    }
	    // Sanitise Data Function
	    private function sanitise_input($data) {
            $data = trim($data);
            $data = stripslashes($data);
            $data = htmlspecialchars($data);
            return $data;
	    }
    }
?> 
