 <?php

    // Include
    require_once '../config/connect_db.inc';
    require_once '../entities/data_tranfer_layer/employee_DTO.inc';

    class EmployeeFacadeRemote {

        // Private Fields
        private $db_conn;
        private $employee_DTO;

        // Default Constructor
        function __construct(){
            $this->db_conn = new ConnectDB();
            $this->employee_DTO = new EmployeeDTO();
        }

        // Methods
        function create_employee_record(){

        }

        function read_employee_record($attribute, $search_string){
            $command = "SELECT * FROM Employee WHERE $attribute = '$search_string';";
            //Return the result from the query.
            $result = mysqli_query($this->db_conn->get_conn(), $command);
            $row = mysqli_fetch_assoc($result);
            $this->employee_DTO = $this->employee_DTO->with_row($row);
        }

        function update_employee_record(){
            
        }

        function delete_employee_record(){
            
        }

        // Getters
        function get_db_conn(){
            return $this->db_conn;
        }

        function get_employee_DTO(){
            return $this->employee_DTO;
        }

        // Setters
        function set_db_conn($db_conn) {
            $this->db_conn = $db_conn;
        }

        function set_employee_DTO($employee_DTO) {
            $this->employee_DTO = $employee_DTO;
        }

    }

?> 