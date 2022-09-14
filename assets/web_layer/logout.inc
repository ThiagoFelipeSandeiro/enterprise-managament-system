<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        session_start();
        // remove all session variables
        session_unset();
        // destroy the session
        session_destroy(); 
        header ("location: ../../index.php");
    }
?>
