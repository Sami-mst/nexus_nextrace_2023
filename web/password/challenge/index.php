<?php
$password="donthackme";
if (isset($_POST['password']) and $_POST['password']===$password){
    echo "<p>congratulation for cracking this </p><br><h5>nexus{maSt3R_P4SsWOrD_cr4CK3r}</h5>";
}

else{ ?>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/crypto-js/3.1.9-1/crypto-js.js"></script>
    <h3>nexus' flag storage !!!!!</h3>
    <p>only those who have the password can access the flag ! : </p>
    <form action="index.php" id='form' method='post'>
        <label for="password"><br>password : </label>
        <input type="text" name='password' id='password'>
        <p id="errorText" style="color: red;"></p>
    </form>
    <script>function check(password){return CryptoJS.MD5(password).toString()==="c389b201cdf0b6ea7568ae644c4cf52d";}
        const passwordField = document.getElementById('password');
        const errorText = document.getElementById('errorText');
        const formEvent = document.getElementById('form');
        formEvent.addEventListener('submit',function(e){
            e.preventDefault();
            if (check(passwordField.value)){
                formEvent.submit()
            }
            else{
                errorText.textContent = 'wrong password :(';
            }
        })
    </script>
    
<?php }
?>
