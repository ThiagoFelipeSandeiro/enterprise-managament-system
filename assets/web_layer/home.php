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
            <!-- Header & Logout Button -->
            <section id="manage">
              <div style="display: flex;flex-direction: row;"><h1 id="h1" style="width: 95%;">Go-to-Gro EMS | Home Page</h1>
                <div style="align-items: center;display: grid;">
                    <button><a style='text-decoration:none;' href='logout.php'>Logout</a></button>
                </div>
              </div>
              <hr/><br/>
                <!-- Employee Form -->
                <div id="manage-employee">
                  <form id='manage-employee-form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>
                    <?php include 'manage_records.inc';?>
                    <section>
                      <!-- Employee Details -->
                      <fieldset>
                        <legend>Employee Details</legend>
                        <div id='employee-details'></div>
                        <label for='CRUD'></label>
                          <input type='radio' name='CRUD' value='create-employee' />Add
                          <input type='radio' name='CRUD' value='read-employee' />Display
                          <input type='radio' name='CRUD' value='update-employee' />Update
                          <input type='radio' name='CRUD' value='delete-employee' />Delete
                          <br/><br/>
                          <div id='employee-details-btn'></div>
                      </fieldset>
                      <br/>
                    </section>
                  </form>
                </div>
                <hr/><br/>
                <!-- Member Form -->
                <div id="manage-member">
                  <form id='manage-member-form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>
                    <section>
                      <!-- Member Details -->
                      <fieldset>
                        <legend>Member Details</legend>
                        <div id='member-details'></div>
                        <label for='CRUD'></label>
                          <input type='radio' name='CRUD' value='create-member' />Add
                          <input type='radio' name='CRUD' value='read-member' />Display
                          <input type='radio' name='CRUD' value='update-member' />Update
                          <input type='radio' name='CRUD' value='delete-member' />Delete
                          <br/><br/>
                          <div id='member-details-btn'></div>
                      </fieldset>
                      <br/>
                    </section>
                  </form>
                </div>
                <hr/><br/>
                <!-- Product Form -->
                <div id="manage-product">
                  <form id='manage-product-form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>
                    <section>
                      <!-- Product Details -->
                      <fieldset>
                        <legend>Product Details</legend>
                        <div id='product-details'></div>
                        <label for='CRUD'></label>
                          <input type='radio' name='CRUD' value='create-product' />Add
                          <input type='radio' name='CRUD' value='read-product' />Display
                          <input type='radio' name='CRUD' value='update-product' />Update
                          <input type='radio' name='CRUD' value='delete-product' />Delete
                          <br/><br/>
                        <div id='product-details-btn'></div>
                      </fieldset>
                      <br/>
                    </section>
                  </form>
                </div>
                <hr/><br/>
                <!-- Sale Form -->
                <div id="manage-sale">
                  <form id='manage-sale-form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>
                    <section>
                      <!-- Sale Details -->
                      <fieldset>
                        <legend>Sale Details</legend>
                        <div id='sale-details'></div>
                        <label for='CRUD'></label>
                          <input type='radio' name='CRUD' value='create-sale' />Add
                          <input type='radio' name='CRUD' value='read-sale' />Display
                          <input type='radio' name='CRUD' value='update-sale' />Update
                          <input type='radio' name='CRUD' value='delete-sale' />Delete
                          <br/><br/>
                        <div id='sale-details-btn'></div>
                      </fieldset>
                      <br/>
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