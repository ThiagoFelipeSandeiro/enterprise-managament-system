 <?php

    class ConnectDB {

        // Private Fields
        private $conn;

        // Default Constructor
        function __construct(){

            // Include
            require_once 'settings.inc';

            // Create connection
            $this->conn = new mysqli($servername, $username, $password, $dbname);

            // Check connection
            if ($this->conn->connect_error) {
                die("Connection failed: " . $this->conn->connect_error);
            }
        }

        // METHODS
        // Close connection
        function close_conn(){
            $this->conn->close();
        }
        // Create connection
        function create_conn(){
            $this->conn = new mysqli($servername, $username, $password, $dbname);
        }
        // Check connection
        function check_conn(){
            if ($this->conn->connect_error) {
                die("Connection failed: " . $this->connconn->connect_error);
            }
        }

        // Getters
        function get_conn(){
            return $this->conn;
        }

        // Setters
        function set_conn($conn) {
            $this->conn = $conn;
        }

    }

?> 