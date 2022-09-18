<?php
  session_start();
  $_SESSION["Login"] = 'false'
?>
<!DOCTYPE html>
<html lang="en" dir="ltr">

<head>
    <meta charset="utf-8" />
    <title>Go-to-Gro EMS | Login Page</title>
    <meta name="description" content="Go-to-Gro EMS | Login Page" />
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
                <h1 id="h1">Employee Login</h1>
                <hr />

                <!-- Form -->
                <div id="manage-container">
                  <form id='LoginForm' class='form' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>' method='post' novalidate='novalidate'>
                    <?php require_once './assets/web_layer/login.inc';?>
                      <!-- Admin Details -->
                      <fieldset id='admin-details'>
                        <legend>Employee Login Details</legend>

                        <label for='email'>Email</label>
                          <input type='text' name='employeeEmail' placeholder='Email...' /><br /><br />

                        <label for='password'>Password</label>
                          <input type='password' name='employeePassword' placeholder='Password...' /><br /><br />

                          <button form='LoginForm' type='submit'>Login</button>
                      </fieldset>
                      <br />
                      <br />
                  </form>
                </div>

            </section>
        </article>
      </main>
      <!-- JS -->
      <script src='../js/main.js'></script>

  </body>

</html>
