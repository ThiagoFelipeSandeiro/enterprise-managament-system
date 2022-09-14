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
    <!-- Header -->

    <!-- Nav Bar -->


    <!-- Screen overlay (used for displaying messages)-->
    <div id='scrnOverlay'></div>

    <!-- Main -->
    <main id="manage-main">
        <article id="manage-article">

            <!-- Section 1 -->
            <section id="manage">
                <h1 id="h1">Home Page</h1>
                <hr /><br />

                <!-- Form -->
                <div id="manage-employee">
                  <form id='manage-employee-form' class='form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>
                    <?php require './login.inc';?>
                    <section>

                      <!-- Employee Details -->
                      <fieldset>
                        <legend>Employee Details</legend>

                        <label for='employeeName'>Name</label>
                          <input type='text' name='employeeName' placeholder='Employee Name...' /><br /><br />

                        <label for='employeeAddress'>Address</label>
                          <input type='text' name='employeeAddress' placeholder='Employee Address...' /><br /><br />

                        <label for='employeeEmail'>Email</label>
                          <input type='text' name='employeeEmail' placeholder='Employee Email...' /><br /><br />

                        <label for='employeePassword'>Password</label>
                          <input type='password' name='employeePassword' placeholder='Employee Password...' /><br /><br />

                        <label for='employeeCRUD'></label>
                          <input type='radio' name='employeeCRUD' value='create' />Add
                          <input type='radio' name='employeeCRUD' value='read' />Display
                          <input type='radio' name='employeeCRUD' value='update' />Update
                          <input type='radio' name='employeeCRUD' value='delete' />Delete<br /><br />

                          <button form='manage-employee-form' type='submit'>Submit</button>
                      </fieldset>
                      <br />
                    </section>
                  </form>
                </div>

                <hr /><br />

                <!-- Form -->
                <div id="manage-member">
                  <form id='manage-member-form' class='form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>
                    <?php require './login.inc';?>
                    <section>

                      <!-- Member Details -->
                      <fieldset>
                        <legend>Member Details</legend>

                        <label for='memberName'>Name</label>
                          <input type='text' name='memberName' placeholder='Member Name...' /><br /><br />

                        <label for='memberAddress'>Address</label>
                          <input type='text' name='memberAddress' placeholder='Member Address...' /><br /><br />

                        <label for='memberEmail'>Email</label>
                          <input type='text' name='memberEmail' placeholder='Member Email...' /><br /><br />

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
                  <form id='manage-product-form' class='form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>
                    <?php require './login.inc';?>
                    <section>

                      <!-- Product Details -->
                      <fieldset>
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

    <!-- Footer -->


  </body>

</html>
