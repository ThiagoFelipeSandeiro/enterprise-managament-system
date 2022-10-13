 <?php
    class PurchaseDetailsDAO {
	    // Private Fields
        private $productID;
        private $purchaseID;
        private $quantity;
        private $sub_total;
        // Default Constructor
        function __construct() {
            $this->productID = "";
            $this->purchaseID = "";
            $this->quantity = "";
            $this->sub_total = "";
        }
        // Custom Constructor
        public static function with_row($row) {
            $instance = new self();
            $instance->set_productID($row['productID']);
            $instance->set_purchaseID($row['purchaseID']);
            $instance->set_quantity($row['quantity']);
            $instance->set_sub_total($row['subTotal']);
            return $instance;
        }
        // Custom Constructor
        public static function with_row_all($row) {
            $instance = new self();
            $instance->set_purchaseID($row[0]);
            $instance->set_productID($row[1]);
            $instance->set_quantity($row[2]);
            $instance->set_sub_total($row[3]);
            return $instance;
        }
        // Getters
        function get_productID(){
            return $this->productID;
        }
        function get_purchaseID(){
            return $this->purchaseID;
        }
        function get_quantity(){
            return $this->quantity;
        }
        function get_sub_total(){
            return $this->sub_total;
        }
        // Setters
        function set_productID($productID) {
            $this->productID = $productID;
        }
        function set_purchaseID($purchaseID) {
            $this->purchaseID = $purchaseID;
        }
        function set_quantity($quantity) {
            $this->quantity = $quantity;
        }
        function set_sub_total($sub_total) {
            $this->sub_total = $sub_total;
        }
    }
?> 