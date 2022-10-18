 <?php

    // Include
    require_once dirname(__DIR__).'/entities/data_transfer_layer/purchase_DTO.inc';
    require_once dirname(__DIR__).'/entities/data_transfer_layer/purchase_details_DTO.inc';
    require_once dirname(__DIR__).'/business_logic_layer/sale_facade.inc';

    class SaleFacadeRemote {

        // Private Fields
        private $sale_facade;
        private $purchase_DTO;
        private $purchase_details_DTO;
        private $error_message;

        // Default Constructor
        function __construct(){
            $this->sale_facade = new SaleFacade();
            $this->purchase_DTO = new PurchaseDTO();
            $this->purchase_details_DTO = new PurchaseDetailsDTO();
            $this->error_message = "";
        }

        // Default Destructor
        function __destruct() {
            
        }

        // METHODS

        function is_update_valid($post){
            if(empty($post['purchaseID'])){
                return false;
            }else{
                return true;
                }
        }

        function is_create_valid($post){
            foreach ($post as $input){
                if($this->is_empty($input)){
                    return false;
                }else{
                    return true;
                }
            }
        }

        //basic number checking function to make sure price and quantity are positive
         function not_positive_number($attribute){
       
            if (! is_numeric($attribute)) {
                //Add error message.
                $this->error_message .= '<li>Price and/or quantity needs to be a number.</li>';
                return true;
            } elseif($attribute <= 0){
                $this->error_message .= '<li>Price and/or quantity needs to be positive.</li>';
                return true;
            }
            return false;
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

        function create_sale_record($purchase_DTO, $purchase_details_DTO){
            return $this->sale_facade->create_sale_record($purchase_DTO, $purchase_details_DTO);
        }

        function read_sale_record($attribute, $search_string){
            return $this->sale_facade->read_sale_record($attribute, $search_string);
        }

        function update_sale_record($purchase_DTO, $purchase_details_DTO){
            return $this->sale_facade->update_sale_record($purchase_DTO, $purchase_details_DTO);
        }

        function delete_sale_record($attribute, $search_string){
            return $this->sale_facade->delete_sale_record($attribute, $search_string);
        }

        function export_purchase_to_csv(){
            return $this->sale_facade->export_purchase_to_csv();
        }

         function export_purchase_details_to_csv(){
            return $this->sale_facade->export_purchase_details_to_csv();
        }

        // Getters
        function get_purchase_DTO(){
            return $this->purchase_DTO;
        }
        function get_purchase_details_DTO(){
            return $this->purchase_details_DTO;
        }
        function get_sale_facade(){
            return $this->sale_facade;
        }
        function get_error_message(){
            return $this->error_message;
        }
        // Setters
        function set_purchase_DTO($purchase_DTO){
            $this->purchase_DTO = $purchase_DTO;
        }
        function set_purchase_details_DTO($purchase_details_DTO){
            $this->purchase_details_DTO = $purchase_details_DTO;
        }
        function set_sale_facade($sale_facade){
            $this->sale_facade = $sale_facade;
        }
        function set_error_message($error) {
            $this->error_message .= $error;
        }
    }

?> 