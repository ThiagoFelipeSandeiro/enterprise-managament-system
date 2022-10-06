 <?php
    class PurchaseDTO {
        // Private Fields
        private $purchaseID;
        private $date;
        private $memberID;
        // Default Constructor
        function __construct() {
            $this->purchaseID = "";
            $this->date = "";
            $this->memberID = "";
        }
        // Custom Constructor
        public static function with_row($row) {
            $instance = new self();
            $instance->set_purchaseID($row['purchaseID']);
            $instance->set_date($row['date']);
            $instance->set_memberID($row['memberID']);
            return $instance;
        }
        // Custom Constructor
        public static function with_post($post) {
            $instance = new self();
            $instance->set_purchaseID($post['purchaseID']);
            $instance->set_date($post['date']);
            $instance->set_memberID($post['memberID']);
            return $instance;
	    }
        // Getters
        function get_purchaseID(){
            return $this->purchaseID;
        }
        function get_date(){
            return $this->date;
        }
        function get_memberID(){
            return $this->memberID;
        }
        // Setters
        function set_purchaseID($purchaseID) {
            if(!empty($purchaseID)){
	    	    $this->purchaseID = $this->sanitise_input($purchaseID);
	        }
	    }
        function set_date($date) {
            if(!empty($date)){
	    	    $this->date = $this->sanitise_input($date);
	        }
	    }
        function set_memberID($memberID) {
            if(!empty($memberID)){
	    	    $this->memberID = $this->sanitise_input($memberID);
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
