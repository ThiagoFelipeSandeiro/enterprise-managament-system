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
    <title>Go-to-Gro EMS | Display Product Page</title>
    <meta name="description" content="Go-to-Gro EMS | Home Page" />
    <meta name="keywords" content="" />
    <meta name="author" content="James Sanders" />
    <meta name="author" content="Michael Gorissen" />
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
              <div style="display: flex;flex-direction: row;"><h1 id="h1" style="width: 95%;">Go-to-Gro EMS | Display Product Page</h1>
                <div style="align-items: center;display: grid;">
                    <button><a style='text-decoration:none;' href='logout.php'>Logout</a></button>
                </div>
              </div>
              <hr /><br />
              <fieldset>
                <legend>Product Details</legend>
                <?php 
                  //Display the retrived records.
                  echo "<div>\n";
                  echo "<table border='1'>\n";
                  echo "<tr>\n"
                        ."<th scope='col'>Product ID</th>\n"
                        ."<th scope='col'>Product Name</th>\n"
                        ."<th scope='col'>Product Description</th>\n"
                        ."<th scope='col'>Product Unit Cost</th>\n"
                        ."<th scope='col'>Product Quantity on Hand</th>\n"
                        ."<th scope='col'>Product Supplier</th>\n"
                        ."</tr>\n";
                  //Retrive current records pointed by the result pointer.
                    echo "<tr>\n";
                    echo "<td>", $_SESSION['product_ID'], "</td>\n";
                    echo "<td>", $_SESSION['product_name'], "</td>\n";
                    echo "<td>", $_SESSION['product_description'], "</td>\n";
                    echo "<td>", $_SESSION['product_unitCost'], "</td>\n";
                    echo "<td>", $_SESSION['product_quantityOnHand'], "</td>\n";
                    echo "<td>", $_SESSION['product_supplier'], "</td>\n";
                    echo "</tr>\n";

                  echo "</table>\n";
                  echo "</div>\n";
                ?>
              </fieldset>
              <br />
              <button onclick='history.back()'>Okay</button>
            </section>
        </article>
    </main>

  </body>

</html>
