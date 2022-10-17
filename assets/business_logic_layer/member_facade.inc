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
       function create_member_record($DTO){
            $this->set_member_DAO($this->DTO2DAO($DTO));
            $command = "INSERT INTO Member (memberName, address, email) VALUES 
            ('".$this->member_DAO->get_memberName()."',
            '".$this->member_DAO->get_memberAddress()."',
            '".$this->member_DAO->get_memberEmail()."');";
            //Return the result from the query.
            if(mysqli_query($this->db_conn->get_conn(), $command)){
                return true;
            }else{
                return false;
            }
        }

        function read_member_record($attribute, $search_string){
            $command = "SELECT * FROM Member WHERE $attribute = '$search_string';";
            //Return the result from the query.
            $result = mysqli_query($this->db_conn->get_conn(), $command);
            $row = mysqli_fetch_assoc($result);
            if($row != NULL){
                $this->member_DAO = $this->member_DAO->with_row($row);
                return true;
            } else{
                return false;
            }
        }

        function update_member_record($DTO){
            if(!$this->read_member_record('memberID', $DTO->get_memberID())){
                return false;
            }else{
                if(!empty($DTO->get_memberName())){
                    $this->member_DAO->set_memberName($DTO->get_memberName());
                }
                if(!empty($DTO->get_memberAddress())){
                    $this->member_DAO->set_memberAddress($DTO->get_memberAddress());
                }
                if(!empty($DTO->get_memberEmail())){
                    $this->member_DAO->set_memberEmail($DTO->get_memberEmail());
                }
                $command = "UPDATE Member 
                    SET memberName = '".$this->member_DAO->get_memberName()."',
                    address = '".$this->member_DAO->get_memberAddress()."',
                    email = '".$this->member_DAO->get_memberEmail()."'
                    WHERE memberID = '".$this->member_DAO->get_memberID()."';";
                //Return the result from the query.
                if(mysqli_query($this->db_conn->get_conn(), $command)){
                    return true;
                }else{
                    return false;
                }
            }
        }

        function delete_member_record($attribute, $search_string){
            if(!$this->read_member_record($attribute, $search_string)){
                return false;
            }else{
                $command = "DELETE FROM Member WHERE $attribute = '$search_string';";
                //Return the result from the query.
                if(mysqli_query($this->db_conn->get_conn(), $command)){
                    return true;
                }else{
                    return false;
                }
            }
            
	    }

        function export_to_csv(){
            //stack overflow Franksenstein code but it works
            header('Content-Type: text/csv; charset=utf-8');  
            header('Content-Disposition: attachment; filename=member.csv');  
            //cleaning output buffer so whole web page isn't exported
            ob_end_clean();
            $output = fopen("php://output", "w");  
            fputcsv($output, array('Member ID', 'Member Name', 'Member Address', 'Member Email'));  
            $command = "SELECT * FROM member";  
            $result = mysqli_query($this->db_conn->get_conn(), $command); 
            while($row = mysqli_fetch_assoc($result)){  
                fputcsv($output, $row);  
            }  
            fclose($output);  
            exit;
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
            $instance = new MemberDAO();
            $instance->set_memberID($DTO->get_memberID());
            $instance->set_memberName($DTO->get_memberName());
            $instance->set_memberAddress($DTO->get_memberAddress());
            $instance->set_memberEmail($DTO->get_memberEmail());
            return $instance;
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
