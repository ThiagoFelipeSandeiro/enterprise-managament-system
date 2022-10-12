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
    <title>Go-to-Gro EMS | Display Sale Page</title>
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
              <div style="display: flex;flex-direction: row;"><h1 id="h1" style="width: 95%;">Go-to-Gro EMS | Display Sale Page</h1>
                <div style="align-items: center;display: grid;">
                    <button><a style='text-decoration:none;' href='logout.php'>Logout</a></button>
                </div>
              </div>
              <hr /><br />
              <fieldset>
                <legend>Sale Details</legend>
                <?php 

                  //Display the retrived records.
                  echo "<div>\n";

                  // Member Details
                  echo "<table border='1'>\n";
                  echo "<tr>\n"
                        ."<th scope='col'>Member ID</th>\n"
                        ."<th scope='col'>Member Name</th>\n"
                        ."<th scope='col'>Member Address</th>\n"
                        ."<th scope='col'>Member Email</th>\n"
                        ."</tr>\n";
                  //Retrive current records pointed by the result pointer.
                    echo "<tr>\n";
                    echo "<td>", $_SESSION['member_ID'], "</td>\n";
                    echo "<td>", $_SESSION['member_name'], "</td>\n";
                    echo "<td>", $_SESSION['member_address'], "</td>\n";
                    echo "<td>", $_SESSION['member_email'], "</td>\n";
                    echo "</tr>\n";

                  echo "</table>\n";

                  // Purchase Details
                  echo "<table border='1'>\n";
                  echo "<tr>\n"
                        ."<th scope='col'>Purchase ID</th>\n"
                        ."<th scope='col'>Date</th>\n"
                        ."</tr>\n";
                  //Retrive current records pointed by the result pointer.
                    echo "<tr>\n";
                    echo "<td>", $_SESSION['purchase_ID'], "</td>\n";
                    echo "<td>", $_SESSION['date'], "</td>\n";
                    echo "</tr>\n";

                  echo "</table>\n";

                  // Purchased Products Details
                  echo "<table border='1'>\n";
                  echo "<tr>\n"
                        ."<th scope='col'>Product ID</th>\n"
                        ."<th scope='col'>Product Name</th>\n"
                        ."<th scope='col'>Product Description</th>\n"
                        ."<th scope='col'>Product Unit Cost</th>\n"
                        ."<th scope='col'>Product Quantity Ordered</th>\n"
                        ."<th scope='col'>Product Sub Total</th>\n"
                        ."</tr>\n";
                  
                  $arr = array($_SESSION['basket']);
                  echo $arr[0][1];
                  //Retrive current records pointed by the result pointer.
                    for($i = 0; $i < count($arr); $i++){
                      echo "<tr>\n";
                      echo "<td>", $arr[$i][0], "</td>\n";
                      echo "<td>", $arr[$i][1], "</td>\n";
                      echo "<td>", $arr[$i][2], "</td>\n";
                      echo "<td>", $arr[$i][3], "</td>\n";
                      echo "<td>", $arr[$i][4], "</td>\n";
                      echo "<td>", $arr[$i][5], "</td>\n";
                      echo "</tr>\n";
                    }

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
