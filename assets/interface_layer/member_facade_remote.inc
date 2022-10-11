 <?php

    // Include
    require_once dirname(__DIR__).'/entities/data_transfer_layer/member_DTO.inc';
    require_once dirname(__DIR__).'/business_logic_layer/member_facade.inc';

    class MemberFacadeRemote {

        // Private Fields
        private $member_facade;
        private $member_DTO;
        private $error_message;

        // Default Constructor
        function __construct(){
            $this->member_facade = new MemberFacade();
            $this->member_DTO = new MemberDTO();
            $this->error_message = "";
        }

        // Default Destructor
        function __destruct() {
            
        }

        // METHODS

        function is_update_valid($post){
            if(empty($post['memberAddress']) && empty($post['memberEmail'])){
                return true;
            }
            if(!empty($post['memberAddress']) && !empty($post['memberEmail'])){
                return $this->is_email($post);
            }
            if(empty($post['memberAddress']) && !empty($post['memberEmail'])){
                return $this->is_email($post);
            }
 
        }

        function is_create_valid($post){
            if($this->is_empty($post['memberName']) ||
                $this->is_empty($post['memberAddress']) ||
                $this->is_empty($post['memberEmail'])){
                    return false;
                }else{
                    return $this->is_email($post);
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


        function is_email($post){
            //Check email matches regex.
            if (!preg_match("/^[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*@[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*$/", $post['memberEmail'])){
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

        function create_member_record($DTO){
            return $this->member_facade->create_member_record($DTO);
        }

        function read_member_record($attribute, $search_string){
            $this->member_facade->read_member_record($attribute, $search_string);
        }

        function update_member_record($DTO){
            return $this->member_facade->update_member_record($DTO);
        }

        function delete_member_record($attribute, $search_string){
            return $this->member_facade->delete_member_record($attribute, $search_string);
        }

        function export_to_csv(){
            return $this->member_facade->export_to_csv();
        }

        // Getters
        function get_member_DTO(){
            return $this->member_DTO;
        }
        function get_member_facade(){
            return $this->member_facade;
        }

        // Setters
        function set_member_DTO($member_DTO) {
            $this->member_DTO = $member_DTO;
        }
        function set_error_message($error) {
            $this->error_message .= $error;
        }


    }

?> 