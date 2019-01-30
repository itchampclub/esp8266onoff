<?php
$txt = "data.txt"; 
if (isset($_POST['field1']) && isset($_POST['field2'])) { // check if both fields are set
    $fh = fopen($txt, 'a'); 
    $txt=$_POST['field1'].' - '.$_POST['field2']; 
    fwrite($fh,$txt); // Write information to the file
    fclose($fh); // Close the file
}
?>
