 <?php

    // Include
    require_once dirname(__DIR__).'/config/connect_db.inc';
    require_once dirname(__DIR__).'/entities/data_transfer_layer/employee_DTO.inc';
    require_once dirname(__DIR__).'/entities/data_access_layer/employee_DAO.inc';

    class EmployeeFacade {

        // Private Fields
        private $db_conn;
        private $employee_DAO;

        // Default Constructor
        function __construct(){
            $this->db_conn = new ConnectDB();
            $this->employee_DAO = new EmployeeDAO();
        }

        // Default Destructor
        function __destruct() {
            $this->db_conn->close_conn();
        }

        // METHOD
        function create_employee_record(){

        }

        function read_employee_record($attribute, $search_string){
            $command = "SELECT * FROM Employee WHERE $attribute = '$search_string';";
            //Return the result from the query.
            $result = mysqli_query($this->db_conn->get_conn(), $command);
            $row = mysqli_fetch_assoc($result);
            if($row != NULL)
                $this->employee_DAO = $this->employee_DAO->with_row($row);
        }

        function update_employee_record(){
            
        }

        function delete_employee_record(){
            
        }

        function DAO2DTO($DAO){
            $instance = new EmployeeDTO();
            $instance->set_employeeID($DAO->get_employeeID());
            $instance->set_password($DAO->get_employeeID());
            $instance->set_employeeName($DAO->get_employeeID());
            $instance->set_address($DAO->get_employeeID());
            $instance->set_email($DAO->get_employeeID());
            return $instance;
        }

        function DTO2DAO($DTO){
            
        }

        // Getters
        function get_db_conn(){
            return $this->db_conn;
        }

        function get_employee_DAO(){
            return $this->employee_DAO;
        }

        // Setters
        function set_db_conn($db_conn) {
            $this->db_conn = $db_conn;
        }

        function set_employee_DAO($employee_DAO) {
            $this->employee_DAO = $employee_DAO;
        }

    }

?> 