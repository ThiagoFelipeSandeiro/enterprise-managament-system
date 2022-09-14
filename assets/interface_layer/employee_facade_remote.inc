 <?php

    // Include
    require_once '../entities/data_tranfer_layer/employee_DTO.inc';

    class EmployeeFacadeRemote {

        // Private Fields
        private $employee_DTO;
        private $error_message;

        // Default Constructor
        function __construct(){
            $this->employee_DTO = new EmployeeDTO();
            $this->error_message = "";
        }

        // Default Destructor
        function __destruct() {
            
        }

        // METHODS
        function is_valid(){
            
        }


        function is_valid(){

        }

        function is_empty($attribute){
            //Check if email is empty.
            if (empty($attribute)) {
                //Add error message.
                $this->error_message .= "<li>$attribute cannot be blank.</li>";
                return true;
            }
            return false;
        }

        function is_password($post){
            //Check Password matches regex.
            if (!preg_match("/^\S*(?=\S{8,})(?=\S*[a-z])(?=\S*[A-Z])(?=\S*[\d])(?=\S*[\W])\S*$/", $post['password'])){
                //Add error message.
                $this->error_message .= "<li>Your password doesn't match the required format.</li>";
                return true;
            }
            return false;
        }

        function is_email($post){
            //Check email matches regex.
            if (!preg_match("/^[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*@[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*$/", $post['email'])){
                //Add error message.
                $this->error_message .= "<li>Your email doesn't match the required format.</li>";
                return true;
            }
            return false;
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
                    $this->error_message
                    </ul>
                    <br/>
                    <a href='employee_login.php' style='position:relative;vertical-align:super;'><button type='button' id='errBtn' class='btn'>Okay</button></a>
                    </section>
                </div>";
        }

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