 <?php
    class ProductDAO {
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
            $instance->set_productDescription($row['description']);
            $instance->set_productUnitCost($row['unitCost']);
	        $instance->set_productQuantityOnHand($row['quantityOnHand']);
	        $instance->set_productSupplier($row['supplier']);
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
            $this->productID = $productID;
        }
        function set_productName($productName) {
            $this->productName = $productName;
        }
        function set_productDescription($productDescription) {
            $this->productDescription = $productDescription;
        }
        function set_productUnitCost($productUnitCost) {
            $this->productUnitCost = $productUnitCost;
        }
        function set_productQuantityOnHand($productQuantityOnHand) {
            $this->productQuantityOnHand = $productQuantityOnHand;
        }
        function set_productSupplier($productSupplier){
            $this->productSupplier = $productSupplier;
        }
    }
?> 