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
        document.getElementById("employee-details-btn").innerHTML = "<input form='manage-employee-form' type='submit'/>"
        break;

    case 'delete-employee':
        document.getElementById("employee-details").innerHTML = 
                "<label for='employeeID'>ID</label> "+
                    "<input type='text' name='employeeID' placeholder='Employee ID...' /><br /><br />";
        document.getElementById("employee-details-btn").innerHTML = "<input form='manage-employee-form' type='submit'/>"
        break;
  }

}