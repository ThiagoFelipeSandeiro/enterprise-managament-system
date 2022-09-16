 <?php

    class ProductDAO {

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
            $this->productID = $productID;
        }
        function set_productName($productName) {
            $this->productName = $productName;
        }
        function set_productDescription($productDescription) {
            $this->productDescription = $productDescription;
        }
        function set_unitCost($unitCost) {
            $this->unitCost = $unitCost;
        }
        function set_quantityOnHand($quantityOnHand) {
            $this->quantityOnHand = $quantityOnHand;
	}
	function set_supplier($supplier){
		$this->supplier = $supplier;
	}
    }
    
?> 
