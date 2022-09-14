 <?php

    class EmployeeDAO {

        // Private Fields
        private $employeeID;
        private $password;
        private $loginStatus;
        private $employeeName;
        private $address;
        private $email;

        // Default Constructor
        function __construct() {
            $this->employeeID = "";
            $this->password = "";
            $this->loginStatus = FALSE;
            $this->employeeName = "";
            $this->address = "";
            $this->email = "";
        }

        // Custom Constructor
        public static function with_row($row) {
            $instance = new self();
            $instance->set_employeeID($row['employeeID']);
            $instance->set_password($row['password']);
            $instance->set_loginStatus($row['loginStatus']);
            $instance->set_employeeName($row['employeeName']);
            $instance->set_address($row['address']);
            $instance->set_email($row['email']);
            return $instance;
        }

        // Getters
        function get_employeeID(){
            return $this->employeeID;
        }
        function get_password(){
            return $this->password;
        }
        function get_loginStatus(){
            return $this->loginStatus;
        }
        function get_employeeName(){
            return $this->employeeName;
        }
        function get_address(){
            return $this->address;
        }
        function get_email(){
            return $this->email;
        }

        // Setters
        function set_employeeID($employeeID) {
            $this->employeeID = $employeeID;
        }
        function set_password($password) {
            $this->password = $password;
        }
        function set_loginStatus($loginStatus) {
            $this->loginStatus = $loginStatus;
        }
        function set_employeeName($employeeName) {
            $this->employeeName = $employeeName;
        }
        function set_address($address) {
            $this->address = $address;
        }
        function set_email($email) {
            $this->email = $email;
        }
    }
    
?> 