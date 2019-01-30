<?php
$txt = "data.txt"; 
if(isset($_POST["onoff"])) { // check if both fields are set
    $fh = fopen($txt, 'a'); 
    $txt=$_POST['onoff']; 
    fwrite($fh,$txt); // Write information to the file
    fclose($fh); // Close the file
}
?>
