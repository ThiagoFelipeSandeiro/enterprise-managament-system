 <?php

    // Include
    require_once dirname(__DIR__).'/entities/data_transfer_layer/employee_DTO.inc';
    require_once dirname(__DIR__).'/business_logic_layer/employee_facade.inc';

    class EmployeeFacadeRemote {

        // Private Fields
        private $employee_facade;
        private $employee_DTO;
        private $error_message;

        // Default Constructor
        function __construct(){
            $this->employee_facade = new EmployeeFacade();
            $this->employee_DTO = new EmployeeDTO();
            $this->error_message = "";
        }

        // Default Destructor
        function __destruct() {
            
        }

        // METHODS
        function is_login_valid($post){
            if($this->is_empty($post["employeeEmail"]) || $this->is_empty($post["employeePassword"])){
                $this->print_error();
                return false;
            }elseif(!$this->is_email($post) || !$this->is_password($post)){
                $this->print_error();
                return false;
            }else{
                $this->employee_DTO->set_email($post["employeeEmail"]);
                $this->employee_DTO->set_password($post["employeePassword"]);
                if($this->is_login_auth($this->employee_DTO)){
                    return true;
                }else{
                    $this->print_error();
                    return false;
                }
            }
        }

        function is_login_auth($employee_DTO){
            $this->read_employee_record("email", $this->employee_DTO->get_email());
            // this check has been changed to simply hash the given password using md5 and match it to the stored md5 hash in the database
            if($this->employee_DTO->get_email() == $this->employee_facade->get_employee_DAO()->get_email() &&
                password_verify($this->employee_DTO->get_password(), $this->employee_facade->get_employee_DAO()->get_password())){
                    return true;
            }else{
                //error
                $this->error_message .= "<li>Access not granted.</li>";
                return false;
            }
        }

        function is_update_valid($post){
            if(empty($post['employeePassword']) && empty($post['employeeEmail'])){
                return true;
            }
            if(!empty($post['employeePassword']) && !empty($post['employeeEmail'])){
                return $this->is_password($post) && $this->is_email($post);
            }
            if(empty($post['employeePassword']) && !empty($post['employeeEmail'])){
                return $this->is_email($post);
            }
            if(!empty($post['employeePassword']) && empty($post['employeeEmail'])){
                return $this->is_password($post);
            }
        }

        function is_create_valid($post){
            if($this->is_empty($post['employeeName']) ||
                $this->is_empty($post['employeePassword']) ||
                $this->is_empty($post['employeeAddress']) ||
                $this->is_empty($post['employeeEmail'])){
                    return false;
                }else{
                    return $this->is_password($post) && $this->is_email($post);
                }
        }

        function is_empty($attribute){
            //Check if email is empty.
            if (empty($attribute)) {
                //Add error message.
                $this->error_message .= '<li>Field cannot be blank.</li>';
                return true;
            }
            return false;
        }

        function is_password($post){
            //Check Password matches regex.
            if (!preg_match("/^\S*(?=\S{8,})(?=\S*[a-z])(?=\S*[A-Z])(?=\S*[\d])(?=\S*[\W])\S*$/", $post['employeePassword'])){
                //Add error message.
                $this->error_message .= "<li>Your password doesn't match the required format.</li>";
                return false;
            }
            return true;
        }

        function is_email($post){
            //Check email matches regex.
            if (!preg_match("/^[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*@[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*$/", $post['employeeEmail'])){
                //Add error message.
                $this->error_message .= "<li>Your email doesn't match the required format.</li>";
                return false;
            }
            return true;
        }

        function has_error(){
            //Check if error message exsits.
            if ($this->error_message != "") {
                return true;
            }
            return false;
        }

        function print_error(){
            //Print error message.
            echo "<div id='scrnOverlay' style='display:block;'>
                    <section id='errWin' class='window' style='display:block;'>
                    <ul id='ul-err' style='text-align:center;padding: 0;'>
                    ".$this->error_message."
                    </ul>
                    <br/>
                    <a href='' style='position:relative;vertical-align:super;'><button type='button' id='errBtn' class='btn'>Okay</button></a>
                    </section>
                </div>";
        }

        function create_employee_record($DTO){
            return $this->employee_facade->create_employee_record($DTO);
        }

        function read_employee_record($attribute, $search_string){
            $this->employee_facade->read_employee_record($attribute, $search_string);
        }

        function update_employee_record($DTO){
            return $this->employee_facade->update_employee_record($DTO);
        }

        function delete_employee_record($attribute, $search_string){
            return $this->employee_facade->delete_employee_record($attribute, $search_string);
        }

        // Getters
        function get_employee_DTO(){
            return $this->employee_DTO;
        }
        function get_employee_facade(){
            return $this->employee_facade;
        }

        // Setters
        function set_employee_DTO($employee_DTO) {
            $this->employee_DTO = $employee_DTO;
        }
        function set_error_message($error) {
            $this->error_message .= $error;
        }


    }

?> 