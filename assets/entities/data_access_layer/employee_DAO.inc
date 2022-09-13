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
        function __construct($employeeID, $password, $employeeName, $address, $email) {
            $this->employeeID = $employeeID;
            $this->password = $password;
            $this->loginStatus = FALSE;
            $this->employeeName = $employeeName;
            $this->address = $address;
            $this->email = $email;
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