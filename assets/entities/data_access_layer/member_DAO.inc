 <?php

    class MemberDAO {

	// Private Fields
        private $memberID;
        private $memberName;
        private $memberAddress;
        private $memberEmail;

        // Default Constructor
        function __construct() {
            $this->memberID = "";
            $this->memberName = "";
            $this->memberAddress = "";
            $this->memberEmail = 0;
        }

        // Custom Constructor
        public static function with_row($row) {
            $instance = new self();
            $instance->set_memberID($row['memberID']);
            $instance->set_memberName($row['memberName']);
            $instance->set_memberAddress($row['memberAddress']);
            $instance->set_memberEmail($row['memberEmail']);
            return $instance;
        }

        // Getters
        function get_memberID(){
            return $this->memberID;
        }
        function get_memberName(){
            return $this->memberName;
        }
        function get_memberAddress(){
            return $this->memberAddress;
        }
        function get_memberEmail(){
            return $this->memberEmail;
        }

        // Setters
        function set_memberID($memberID) {
            $this->memberID = $memberID;
        }
        function set_memberName($memberName) {
            $this->memberName = $memberName;
        }
        function set_memberAddress($memberAddress) {
            $this->memberAddress = $memberAddress;
        }
        function set_memberEmail($memberEmail) {
            $this->memberEmail = $memberEmail;
        }
    }
    
?> 
