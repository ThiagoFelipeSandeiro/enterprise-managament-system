 <?php
    class PurchaseDAO {
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
            $this->purchaseID = $purchaseID;
        }
        function set_date($date) {
            $this->date = $date;
        }
        function set_memberID($memberID) {
            $this->memberID = $memberID;
        }
    }
?> 