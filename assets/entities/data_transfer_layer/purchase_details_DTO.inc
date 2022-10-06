 <?php
    class PurchaseDetailsDTO {
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
            $instance->set_sub_total($row['sub_total']);
            return $instance;
        }
        // Custom Constructor
        public static function with_post($post) {
            $instance = new self();
            $instance->set_productID($post['productID']);
            $instance->set_purchaseID($post['purchaseID']);
            $instance->set_quantity($post['quantity']);
            $instance->set_sub_total($post['sub_total']);
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
            if(!empty($productID)){
	    	    $this->productID = $this->sanitise_input($productID);
	        }
	    }
        function set_purchaseID($purchaseID) {
            if(!empty($purchaseID)){
	    	    $this->purchaseID = $this->sanitise_input($purchaseID);
	        }
	    }
        function set_quantity($quantity) {
            if(!empty($quantity)){
	    	    $this->quantity = $this->sanitise_input($quantity);
	        }
	    }
        function set_sub_total($sub_total) {
            if(!empty($sub_total)){
	    	    $this->sub_total = $this->sanitise_input($sub_total);
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
