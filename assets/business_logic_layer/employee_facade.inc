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
        // password hashing function changed to be simple md5 as password_hash creates a salt every time it is run
        function create_employee_record($DTO){
            $this->set_employee_DAO($this->DTO2DAO($DTO));
            $command = "INSERT INTO Employee (password, employeeName, address, email) VALUES    
            ('".hash('md5', $this->employee_DAO->get_password())."',
            '".$this->employee_DAO->get_employeeName()."',
            '".$this->employee_DAO->get_address()."',
            '".$this->employee_DAO->get_email()."');";
            //Return the result from the query.
            if(mysqli_query($this->db_conn->get_conn(), $command)){
                return true;
            }else{
                return false;
            }
        }

        function read_employee_record($attribute, $search_string){
            $command = "SELECT * FROM Employee WHERE $attribute = '$search_string';";
            //Return the result from the query.
            $result = mysqli_query($this->db_conn->get_conn(), $command);
            $row = mysqli_fetch_assoc($result);
            if($row != NULL){
                $this->employee_DAO = $this->employee_DAO->with_row($row);
                return true;
            }else{
                return false;
            }
        }

        function update_employee_record($DTO){
            if(!$this->read_employee_record('employeeID', $DTO->get_employeeID())){
                return false;
            }else{
                if(!empty($DTO->get_password())){
                    $this->employee_DAO->set_password($DTO->get_password());
                }
                if(!empty($DTO->get_employeeName())){
                    $this->employee_DAO->set_employeeName($DTO->get_employeeName());
                }
                if(!empty($DTO->get_address())){
                    $this->employee_DAO->set_address($DTO->get_address());
                }
                if(!empty($DTO->get_email())){
                    $this->employee_DAO->set_email($DTO->get_email());
                }
                $command = "UPDATE Employee 
                    SET password = '".password_hash($this->employee_DAO->get_password(), PASSWORD_DEFAULT)."',
                    employeeName = '".$this->employee_DAO->get_employeeName()."',
                    address = '".$this->employee_DAO->get_address()."',
                    email = '".$this->employee_DAO->get_email()."'
                    WHERE employeeID = '".$this->employee_DAO->get_employeeID()."';";
                //Return the result from the query.
                if(mysqli_query($this->db_conn->get_conn(), $command)){
                    return true;
                }else{
                    return false;
                }
            }
        }

        function delete_employee_record($attribute, $search_string){
            if(!$this->read_employee_record($attribute, $search_string)){
                return false;
            }else{
                $command = "DELETE FROM Employee WHERE $attribute = '$search_string';";
                //Return the result from the query.
                if(mysqli_query($this->db_conn->get_conn(), $command)){
                    return true;
                }else{
                    return false;
                }
            }
        }

        function DAO2DTO($DAO){
            $instance = new EmployeeDTO();
            $instance->set_employeeID($DAO->get_employeeID());
            $instance->set_password($DAO->get_password());
            $instance->set_employeeName($DAO->get_employeeName());
            $instance->set_address($DAO->get_address());
            $instance->set_email($DAO->get_email());
            return $instance;
        }

        function DTO2DAO($DTO){
            $instance = new EmployeeDAO();
            $instance->set_employeeID($DTO->get_employeeID());
            $instance->set_password($DTO->get_password());
            $instance->set_employeeName($DTO->get_employeeName());
            $instance->set_address($DTO->get_address());
            $instance->set_email($DTO->get_email());
            return $instance;
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