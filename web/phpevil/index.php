<!DOCTYPE html>
<html>

<head>
    <title>Login Form</title>
    <link rel="stylesheet" type="text/css" href="./style.css">
</head>

<body>
	<!-- check ?pihpi-->
    <form method="post" >
        <h2>Login Form</h2>
        <label>Username:</label>
        <input type="text" name="username">
        <label>Password:</label>
        <input type="password" name="password">
        <input type="submit" value="Login">
        
        
    </form>

</body>

</html>
<?php
include "flag.php";
if (isset($_GET["pihpi"]))
{
    highlight_file(__FILE__);
}


ini_set('display_errors', '0');


if ($_SERVER['REQUEST_METHOD'] === 'POST'){
if(isset($_POST["username"]) && isset($_POST["password"])){
if($_POST["username"]==="GUTS"){
$Role=$_POST["role"];
$inp=preg_replace("/[^A-Za-z0-9$]/", "", $_POST["password"]); 

if($inp==="griffithDidNothingWrong"){
  echo("<center>Hacking Attempt detected</center>");
}

else{
  if(eval("return \$inp=\"$inp\";")==="griffithDidNothingWrong"){
    echo $flag;
}
else{
  echo("<center>you are close!! </center>");
}}

}else{
  die("<center>incorrect creds, try again!</center>");
}
}
}
?>
