<?php
$txt = "data.txt"; 
if(isset($_POST["hidden_gender"])) { // check if both fields are set
    $fh = fopen($txt, 'a'); 
    $txt=$_POST['hidden_gender']; 
    fwrite($fh,$txt); // Write information to the file
    fclose($fh); // Close the file
}
?>

