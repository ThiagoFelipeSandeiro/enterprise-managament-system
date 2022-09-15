<?php
  session_start();
  if ($_SESSION["Login"] == 'false') {
    header ("location: ../../index.php");
  }
?>
<!DOCTYPE html>
<html lang="en" dir="ltr">

<head>
    <meta charset="utf-8" />
    <title>Go-to-Gro EMS | Home Page</title>
    <meta name="description" content="Go-to-Gro EMS | Home Page" />
    <meta name="keywords" content="" />
    <meta name="author" content="James Sanders" />
    <meta name="author" content="Michael " />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
</head>

<body>
    <!-- Screen overlay (used for displaying messages)-->
    <div id='scrnOverlay'></div>

    <!-- Main -->
    <main id="manage-main">
        <article id="manage-article">

            <!-- Section 1 -->
            <section id="manage">
              <div style="display: flex;flex-direction: row;"><h1 id="h1" style="width: 95%;">Home Page</h1>
                <div style="align-items: center;display: grid;">
                    <button><a style='text-decoration:none;' href='logout.php'>Logout</a></button>
                </div>
              </div>
              <hr /><br />

                <!-- Form -->
                <div id="manage-employee">

                  <form id='manage-employee-form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>
                    <?php include 'manage_employee.inc';?>

                    <section>

                      <!-- Employee Details -->
                      <fieldset>
                        <legend>Employee Details</legend>
                        <div id='employee-details'>
                          <!--<label for='employeeID'>ID</label> 
                            <input type='text' name='employeeID' placeholder='Employee ID...' /><br /><br />

                          <label for='employeeName'>Name</label> 
                            <input type='text' name='employeeName' placeholder='Employee Name...' /><br /><br />

                          <label for='employeeAddress'>Address</label> 
                            <input type='text' name='employeeAddress' placeholder='Employee Address...' /><br /><br />

                          <label for='employeeEmail'>Email</label> 
                            <input type='text' name='employeeEmail' placeholder='Employee Email...' /><br /><br />

                          <label for='employeePassword'>Password</label> 
                            <input type='password' name='employeePassword' placeholder='Employee Password...' /><br /><br />-->
                        </div>
                        <label for='employeeCRUD'></label>
                          <input type='radio' name='employeeCRUD' value='create-employee' />Add
                          <input type='radio' name='employeeCRUD' value='read-employee' />Display
                          <input type='radio' name='employeeCRUD' value='update-employee' />Update
                          <input type='radio' name='employeeCRUD' value='delete-employee' />Delete<br /><br />

                          <div id='employee-details-btn'></div>
                          <!--input form='manage-employee-form' type='submit'/-->

                      </fieldset>
                      <br />

                    </section>

                  </form>

                </div>

                <hr /><br />

                <!-- Form -->
                <div id="manage-member">
                  <form id='manage-member-form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>

                    <section>

                      <!-- Member Details -->
                      <fieldset id='member-details'>
                        <legend>Member Details</legend>
                        <div>
                        <label for='memberName'>Name</label>
                          <input type='text' name='memberName' placeholder='Member Name...' /><br /><br />

                        <label for='memberAddress'>Address</label>
                          <input type='text' name='memberAddress' placeholder='Member Address...' /><br /><br />

                        <label for='memberEmail'>Email</label>
                          <input type='text' name='memberEmail' placeholder='Member Email...' /><br /><br />
                        </div>
                        <label for='memberCRUD'></label>
                          <input type='radio' name='memberCRUD' value='create' />Add
                          <input type='radio' name='memberCRUD' value='read' />Display
                          <input type='radio' name='memberCRUD' value='update' />Update
                          <input type='radio' name='memberCRUD' value='delete' />Delete<br /><br />

                          <button form='manage-member-form' type='submit'>Submit</button>
                      </fieldset>
                      <br />
                    </section>
                  </form>
                </div>

                <hr /><br />

                <!-- Form -->
                <div id="manage-product">
                  <form id='manage-product-form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>
                    
                    <section>

                      <!-- Product Details -->
                      <fieldset id='product-details'>
                        <legend>Product Details</legend>

                        <label for='productName'>Name</label>
                          <input type='text' name='productName' placeholder='Product Name...' /><br /><br />

                        <label for='productDescription'>Decription</label>
                          <input type='text' name='productDescription' placeholder='Product Description...' /><br /><br />

                        <label for='productUnitCost'>Unit Cost</label>
                          <input type='number' name='productUnitCost' placeholder='Product Unit Cost...' step="0.01" value="0.00"/><br /><br />

                        <label for='productQuantityOnHand'>Product Quantity in Stock</label>
                          <input type='number' name='productQuantityOnHand' placeholder='Product Quantity in Stock...' step="1" value="0"/><br /><br />

                        <label for='productSupplier'>Supplier</label>
                          <input type='text' name='productSupplier' placeholder='Product Supplier...' /><br /><br />

                        <label for='productCRUD'></label>
                          <input type='radio' name='productCRUD' value='create' />Add
                          <input type='radio' name='productCRUD' value='read' />Display
                          <input type='radio' name='productCRUD' value='update' />Update
                          <input type='radio' name='productCRUD' value='delete' />Delete<br /><br />

                          <button form='manage-product-form' type='submit'>Submit</button>
                      </fieldset>
                      <br />
                    </section>
                  </form>
                </div>

            </section>
        </article>
    </main>

    <!-- JS -->
    <script src='../js/main.js'></script>

  </body>

</html>
