 <?php

    // Include
    require_once dirname(__DIR__).'/config/connect_db.inc';
    require_once dirname(__DIR__).'/entities/data_transfer_layer/member_DTO.inc';
    require_once dirname(__DIR__).'/entities/data_access_layer/member_DAO.inc';

    class MemberFacade {

        // Private Fields
        private $db_conn;
        private $member_DAO;

        // Default Constructor
        function __construct(){
            $this->db_conn = new ConnectDB();
            $this->member_DAO = new MemberDAO();
        }

        // Default Destructor
        function __destruct() {
            $this->db_conn->close_conn();
        }

        // METHOD
        function create_member_record(){

        }

        function read_member_record($attribute, $search_string){
            $command = "SELECT * FROM Member WHERE $attribute = '$search_string';";
            //Return the result from the query.
            $result = mysqli_query($this->db_conn->get_conn(), $command);
            $row = mysqli_fetch_assoc($result);
            if($row != NULL)
                $this->member_DAO = $this->member_DAO->with_row($row);
        }

        function update_member_record(){
            
        }

        function delete_member_record(){
            
	}

        function DAO2DTO($DAO){
            $instance = new MemberDTO();
	    $instance->set_memberID($DAO->get_memberID());
	    $instance->set_memberName($DAO->get_memberName());
	    $instance->set_memberAddress($DAO->get_memberAddress());
	    $instance->set_memberEmail($DAO->get_memberEmail());
            return $instance;
        }

        function DTO2DAO($DTO){
            
        }

        // Getters
        function get_db_conn(){
            return $this->db_conn;
        }

        function get_member_DAO(){
            return $this->member_DAO;
        }

        // Setters
        function set_db_conn($db_conn) {
            $this->db_conn = $db_conn;
        }

        function set_member_DAO($member_DAO) {
            $this->member_DAO = $member_DAO;
        }

    }

?> 
