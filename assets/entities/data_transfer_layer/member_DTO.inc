 <?php

    class MemberDTO {

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

        // Custom Constructor
        public static function with_post($post) {
            $instance = new self();
            $instance->set_memberID($post['memberID']);
            $instance->set_memberName($post['memberName']);
            $instance->set_memberAddress($post['memberAddress']);
            $instance->set_memberEmail($post['memberEmail']);
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
            if($memberID != NULL){
	    	    $this->memberID = $this->sanitise_input($memberID);
	        }
	    }
        function set_memberName($memberName) {
            if($memberName != NULL){
                $this->memberName = $this->sanitise_input($memberName);
            }
        }
        function set_memberAddress($memberAddress) {
            if($memberAddress != NULL){
                $this->memberAddress = $this->sanitise_input($memberAddress);
            }
        }
        function set_memberEmail($memberEmail) {
            if($memberEmail != NULL){
                $this->memberEmail = $this->sanitise_input($memberEmail);
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