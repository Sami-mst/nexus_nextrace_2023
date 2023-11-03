<?php
function check($username,$_signature){
    return sha1($username)===$_signature;
}
if(isset($_POST['username'])){
    if ($_POST['username']==='admin'){
        echo "<p>ERROR : for security reasons you are not authorized to log in as admin</p>";
    }
    else{
        $_cookie='{"username":"'.$_POST['username'].'","signature":"'.sha1($_POST['username']).'"}';
        setcookie("token", base64_encode($_cookie), time() + 2 * 24 * 60 * 60); 
        header("Location:index.php");
    }
}
if (isset($_COOKIE['token'])){
    try{
    $cookie=base64_decode($_COOKIE['token']);
    $cookie=json_decode($cookie);
    if (isset($cookie->username)&&isset($cookie->signature)){
        if (check($cookie->username,$cookie->signature)){
            if ($cookie->username==='admin'){
                echo "welcome admin";
                echo "<br>here's the secret flag: <strong>nexus{cO0kie_1NteGRIty_f4Ilur3}</strong>";
            }
            else{
                echo "welcome ".$cookie->username;
                echo "<br>since you're not the <strong>admin</strong> user , you don't have access to the flag :(";
                ?>
                <br>
                <input type="button" value="logout"id='logout'>
                <script>
                    function reset(){
                        document.cookie = 'token=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;';
                        location.reload();
                    }
                document.getElementById('logout').addEventListener('click',reset)
                </script><?php
            }
        }else{
            echo "user data tampering attempt detected !!! and blocked";
        }
    }
    else{
        echo "<h1>500 SERVER ERROR : UNVALID TOKEN </h1>";
        echo "username or signature field missing";
    }
}catch(Exception $e){
    echo "<h1>500 SERVER ERROR : UNVALID TOKEN </h1>";
}
}
elseif (!isset($_POST['username'])) {
?>
<h1>welcome !!! please enter your username</h1>
<form action="index.php" method="post">
    <input type="text" name="username" id="name">
    <label for="name">name : </label>
    <input type="submit">
</form>
<?php } ?>

