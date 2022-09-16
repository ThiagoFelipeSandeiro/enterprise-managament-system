 <?php

    class ProductDTO {

	// Private Fields
        private $productID;
        private $productName;
        private $productDescription;
        private $unitCost;
	private $quantityOnHand;
	private $supplier;

        // Default Constructor
        function __construct() {
            $this->productID = "";
            $this->productName = "";
            $this->productDescription = "";
            $this->unitCost = 0;
	    $this->quantityOnHand = 0;
	    $this->supplier = "";
        }

        // Custom Constructor
        public static function with_row($row) {
            $instance = new self();
            $instance->set_productID($row['productID']);
            $instance->set_productName($row['productName']);
            $instance->set_productDescription($row['productDescription']);
            $instance->set_unitCost($row['unitCost']);
	    $instance->set_quantityOnHand($row['quantityOnHand']);
	    $instance->set_supplier($row['supplier']);
            return $instance;
        }

        // Custom Constructor
        public static function with_post($post) {
            $instance = new self();
            $instance->set_productID($post['productID']);
            $instance->set_productName($post['productName']);
            $instance->set_productDescription($post['productDescription']);
            $instance->set_unitCost($post['unitCost']);
	    $instance->set_quantityOnHand($post['quantityOnHand']);
	    $instance->set_supplier($post['supplier']);
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
        function get_unitCost(){
            return $this->unitCost;
        }
        function get_quantityOnHand(){
            return $this->quantityOnHand;
	}
	function get_supplier(){
		return $this->supplier;
	}

        // Setters
        function set_productID($productID) {
            if($productID != NULL){
	    	$this->productID = $this->sanitise_input($productID);
	    }
	}
        function set_productName($productName) {
            if($productName != NULL){
	    	$this->productName = $this->sanitise_input($productName);
	    }
	}
        function set_productDescription($productDescription) {
            if($productDescription != NULL){
	    	$this->productDescription = $this->sanitise_input($productDescription);
	    }
	}
        function set_unitCost($unitCost) {
            if($unitCost != NULL){
	    	$this->unitCost = $this->sanitise_input($unitCost);
	    }
	}
        function set_quantityOnHand($quantityOnHand) {
            if($quantityOnHand != NULL){
	    	$this->quantityOnHand = $this->sanitise_input($quantityOnHand);
	    }
	}
        function set_supplier($supplier) {
            if($supplier != NULL){
	    	$this->supplier = $this->sanitise_input($supplier);
	    }
	}

	//Sanitise function
	function sanitise_input($data) {
		$data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);
		return $data;
	}
    }
    
?> 
