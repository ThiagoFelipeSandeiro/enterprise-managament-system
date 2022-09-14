 <?php

    class EmployeeDTO {

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
            $this->employeeID = sanitise_input($employeeID);
        }
        function set_password($password) {
            $this->password = sanitise_input($password);
        }
        function set_loginStatus($loginStatus) {
            $this->loginStatus = sanitise_input($loginStatus);
        }
        function set_employeeName($employeeName) {
            $this->employeeName = sanitise_input($employeeName);
        }
        function set_address($address) {
            $this->address = sanitise_input($address);
        }
        function set_email($email) {
            $this->email = sanitise_input($email);
        }

        // Sanitise data function.
        function sanitise_input($data) {
            $data = trim($data);
            $data = stripslashes($data);
            $data = htmlspecialchars($data);
            return $data;
        }
    }
    
?> 