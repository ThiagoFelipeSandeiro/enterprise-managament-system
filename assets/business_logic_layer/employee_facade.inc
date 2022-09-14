 <?php

    // Include
    require_once './assets/config/connect_db.inc';
    require_once './assets/entities/data_transfer_layer/employee_DTO.inc';
    require_once './assets/entities/data_access_layer/employee_DAO.inc';

    class EmployeeFacade {

        // Private Fields
        private $db_conn;
        private $employee_DTO;
        private $employee_DAO;

        // Default Constructor
        function __construct(){
            $this->db_conn = new ConnectDB();
            $this->employee_DTO = new EmployeeDTO();
            $this->employee_DAO = new EmployeeDAO();
        }

        // Default Destructor
        function __destruct() {
            $this->db_conn->close_conn();
        }

        // Methods
        function is_login_auth($employee_DTO){
            $this->employee_DTO = $employee_DTO; 
            $this->read_employee_record("email", $this->employee_DTO->get_email());
            if($this->employee_DTO->get_email() == $this->employee_DAO->get_email() && 
                $this->employee_DTO->get_password() == $this->employee_DAO->get_password()){
                    return true;
                }else{
                    return false;
                }
        }

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

        // Getters
        function get_db_conn(){
            return $this->db_conn;
        }

        function get_employee_DAO(){
            return $this->employee_DTO;
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