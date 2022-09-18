var ele = document.getElementsByTagName('input');             
for(i = 0; i < ele.length; i++) {

  if(ele[i].type=="radio") {
		ele[i].addEventListener("click", change);
  }
}

function change() {
	var val = '';
	var ele = document.getElementsByTagName('input');             
  for(i = 0; i < ele.length; i++) {

    if(ele[i].type=="radio") {
        if(ele[i].checked){
          val = ele[i].value;
        }
      }
  }
  
  switch(val){

    case 'create-employee':
        document.getElementById("employee-details").innerHTML = 
            "<label for='employeeID'></label> "+
                "<input type='hidden' name='employeeID' value='0' />"+

            "<label for='employeeName'>Name</label> "+
                "<input type='text' name='employeeName' placeholder='Employee Name...' /><br /><br />"+
            
            "<label for='employeeAddress'>Address</label> "+
                "<input type='text' name='employeeAddress' placeholder='Employee Address...' /><br /><br />"+
            
            "<label for='employeeEmail'>Email</label> "+
                "<input type='text' name='employeeEmail' placeholder='Employee Email...' /><br /><br />"+
            
            "<label for='employeePassword'>Password</label> "+
            "   <input type='password' name='employeePassword' placeholder='Employee Password...' /><br /><br />";
            document.getElementById("employee-details-btn").innerHTML = "<input form='manage-employee-form' type='submit'/>"
        break;

    case 'read-employee':
        document.getElementById("employee-details").innerHTML = 
                "<label for='employeeID'>ID</label> "+
                    "<input type='text' name='employeeID' placeholder='Employee ID...' /><br /><br />";
        document.getElementById("employee-details-btn").innerHTML = "<input form='manage-employee-form' type='submit'/>"
        break;

    case 'update-employee':
        document.getElementById("employee-details").innerHTML = 
        "<label for='employeeID'>ID</label> "+
            "<input type='text' name='employeeID' placeholder='Employee ID...' /><br /><br />"+

        "<label for='employeeName'>Name</label> "+
            "<input type='text' name='employeeName' placeholder='Employee Name...' /><br /><br />"+
        
        "<label for='employeeAddress'>Address</label> "+
            "<input type='text' name='employeeAddress' placeholder='Employee Address...' /><br /><br />"+
        
        "<label for='employeeEmail'>Email</label> "+
            "<input type='text' name='employeeEmail' placeholder='Employee Email...' /><br /><br />"+
        
        "<label for='employeePassword'>Password</label> "+
        "   <input type='password' name='employeePassword' placeholder='Employee Password...' /><br /><br />";
        document.getElementById("employee-details-btn").innerHTML = "<input form='manage-employee-form' type='submit'/>";
        break;

    case 'delete-employee':
        document.getElementById("employee-details").innerHTML = 
                "<label for='employeeID'>ID</label> "+
                    "<input type='text' name='employeeID' placeholder='Employee ID...' /><br /><br />";
        document.getElementById("employee-details-btn").innerHTML = "<input form='manage-employee-form' type='submit'/>"
        break;
        case 'create-member':
            document.getElementById("member-details").innerHTML = 
                "<label for='memberID'>ID</label> "+
                    "<input type='hidden' name='memberID' value='0'/>"+

                "<label for='memberName'>Name</label> "+
                    "<input type='text' name='memberName' placeholder='Member Name...' /><br /><br />"+

                "<label for='memberAddress'>Address</label> "+
                    "<input type='text' name='memberAddress' placeholder='Member Address...' /><br /><br />"+

                "<label for='memberEmail'>Email</label> "+
                    "<input type='text' name='memberEmail' placeholder='Member Email...' /><br /><br />";
            document.getElementById("member-details-btn").innerHTML = "<input form='manage-member-form' type='submit'/>";
            break;
        case 'read-member':
            document.getElementById("member-details").innerHTML = 
                "<label for='memberID'>ID</label> "+
                    "<input type='text' name='memberID' placeholder='Member ID...' /><br /><br />";
            document.getElementById("member-details-btn").innerHTML = "<input form='manage-member-form' type='submit'/>";
            break;
        case 'update-member':
            document.getElementById("member-details").innerHTML = 
                "<label for='memberID'>ID</label> "+
                    "<input type='text' name='memberID' placeholder='Member ID...' /><br /><br />"+

                "<label for='memberName'>Name</label> "+
                    "<input type='text' name='memberName' placeholder='Member Name...' /><br /><br />"+

                "<label for='memberAddress'>Address</label> "+
                    "<input type='text' name='memberAddress' placeholder='Member Address...' /><br /><br />"+

                "<label for='memberEmail'>Email</label> "+
                    "<input type='text' name='memberEmail' placeholder='Member Email...' /><br /><br />";
            document.getElementById("member-details-btn").innerHTML = "<input form='manage-member-form' type='submit'/>";
            break;
        case 'delete-member':
            document.getElementById("member-details").innerHTML = 
                "<label for='memberID'>ID</label> "+
                    "<input type='text' name='memberID' placeholder='Member ID...' /><br /><br />";
            document.getElementById("member-details-btn").innerHTML = "<input form='manage-member-form' type='submit'/>";
            break;
        case 'create-product':
            document.getElementById("product-details").innerHTML = 
                "<label for='productID'></label> "+
                    "<input type='hidden' name='productID' value='0'/>"+
                
                "<label for='productName'>Name</label> "+
                    "<input type='text' name='productName' placeholder='Product Name...' /><br /><br />"+

                "<label for='productDescription'>Decription</label> "+
                    "<input type='text' name='productDescription' placeholder='Product Description...' /><br /><br />"+

                "<label for='productUnitCost'>Unit Cost</label> "+
                    "<input type='number' name='productUnitCost' placeholder='Product Unit Cost...' step='0.01' value='0.00'/><br /><br />"+

                "<label for='productQuantityOnHand'>Product Quantity in Stock</label> "+
                    "<input type='number' name='productQuantityOnHand' placeholder='Product Quantity in Stock...' step='1' value='0'/><br /><br />"+

                "<label for='productSupplier'>Supplier</label> "+
                    "<input type='text' name='productSupplier' placeholder='Product Supplier...' /><br /><br />";
            document.getElementById("product-details-btn").innerHTML = "<input form='manage-product-form' type='submit'/>";
            break;
        case 'read-product':
            document.getElementById("product-details").innerHTML = 
            "<label for='productID'>ID</label> "+
                "<input type='text' name='productID' placeholder='Product ID...' /><br /><br />";
            document.getElementById("product-details-btn").innerHTML = "<input form='manage-product-form' type='submit'/>";
            break;
        case 'update-product':
            document.getElementById("product-details").innerHTML = 
            "<label for='productID'>ID</label> "+
                "<input type='text' name='productID' placeholder='Product ID...' /><br /><br />"+
            
            "<label for='productName'>Name</label>"+
                "<input type='text' name='productName' placeholder='Product Name...' /><br /><br />"+

            "<label for='productDescription'>Decription</label>"+
                "<input type='text' name='productDescription' placeholder='Product Description...' /><br /><br />"+

            "<label for='productUnitCost'>Unit Cost</label>"+
                "<input type='number' name='productUnitCost' placeholder='Product Unit Cost...' step='0.01' value='0.00'/><br /><br />"+

            "<label for='productQuantityOnHand'>Product Quantity in Stock</label>"+
                "<input type='number' name='productQuantityOnHand' placeholder='Product Quantity in Stock...' step='1' value='0'/><br /><br />"+

            "<label for='productSupplier'>Supplier</label>"+
                "<input type='text' name='productSupplier' placeholder='Product Supplier...' /><br /><br />";
        document.getElementById("product-details-btn").innerHTML = "<input form='manage-product-form' type='submit'/>";
            break;
        case 'delete-product':
            document.getElementById("product-details").innerHTML = 
            "<label for='productID'>ID</label> "+
                "<input type='text' name='productID' placeholder='Product ID...' /><br /><br />";
            document.getElementById("product-details-btn").innerHTML = "<input form='manage-product-form' type='submit'/>";
            break;
  }

}