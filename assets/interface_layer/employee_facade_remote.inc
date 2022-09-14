 <?php

    // Include
    require_once '../entities/data_tranfer_layer/employee_DTO.inc';

    class EmployeeFacadeRemote {

        // Private Fields
        private $employee_DTO;

        // Default Constructor
        function __construct(){
            $this->employee_DTO = new EmployeeDTO();
        }

        // Default Destructor
        function __destruct() {
            
        }

        // METHODS
        function create_employee_record(){

        }

        function read_employee_record($attribute, $search_string){

        }

        function update_employee_record(){
            
        }

        function delete_employee_record(){
            
        }

        // Getters
        function get_employee_DTO(){
            return $this->employee_DTO;
        }

        // Setters
        function set_employee_DTO($employee_DTO) {
            $this->employee_DTO = $employee_DTO;
        }

        

    }

?> 