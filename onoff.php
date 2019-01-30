 <?php

$mode=$_POST['mode'];
$filename = 'data.txt';
$txt1 = "On";
$txt2 = "Off";
if ($mode=='true')
{

 if (file_exists($filename)) {
  $myfile = fopen('data.txt', "w+") or die("Unable to open file!");
  fwrite($myfile, $txt1);
  fclose($myfile);
} else {
  $myfile = fopen('data.txt', "x+") or die("Unable to open file!");
  fwrite($myfile, $txt1);
  fclose($myfile);
}
 
 
    $message='Light is On!!';
    $success='Enabled';
    echo json_encode(array('message'=>$message,'$success'=>$success));
}

else if ($mode=='false')
{

 if (file_exists($filename)) {
  $myfile = fopen('data.txt', "w+") or die("Unable to open file!");
  fwrite($myfile, $txt2);
  fclose($myfile);
} else {
  $myfile = fopen('data.txt', "x+") or die("Unable to open file!");
  fwrite($myfile, $txt2);
  fclose($myfile);
}
 
    $message='Light is Off!!';
    $success='Disabled';
    echo json_encode(array('message'=>$message,'success'=>$success));

} 
 ?>
