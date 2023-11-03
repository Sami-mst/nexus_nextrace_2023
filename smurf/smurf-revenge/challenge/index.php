<?php
if ($_SERVER['HTTP_X_FORWARDED_FOR']==="10.101.10.1"){
    echo "<p>welcome smurf, here's your flag : nexus{0NLY_trU3_smURFs_CAn_FInd_thi$} </p>";
}
else{
    if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])){
        $ip=$_SERVER['HTTP_X_FORWARDED_FOR'];
    }
    else{
        $ip=$_SERVER['REMOTE_ADDR'];
    }
    ?>
        <style>
        body {
            background-color: #f0f0f0;
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            
        }

        header {
            background-color: #0074e4;
            color: #fff;
            text-align: center;
            padding: 20px 0;
        }

        h1 {
            font-size: 36px;
        }

        nav {
            background-color: #0055b3;
            color: #fff;
            text-align: center;
            padding: 10px 0;
        }

        nav ul {
            list-style-type: none;
            padding: 0;
        }

        nav li {
            display: inline;
            margin: 0 20px;
        }

        nav a {
            text-decoration: none;
            color: #fff;
        }

        section {
            padding: 20px;
        }

        footer {
            background-color: #0074e4;
            color: #fff;
            text-align: center;
            padding: 10px 0;
        }
        .image {
            width: 50%;
            height: 70%;
            border: 2px solid #333;
            border-radius: 10px; 
            box-shadow: 5px 5px 10px #888;
            display: flex;
            text-align: center;

        }
    </style>
    <?php
    echo "<center><h2>welcome to the smurf flag bank</h2>";
    echo "<p>you are visiting us from <strong>".$ip."</strong></p>";
    echo "<p>thus... the smurf village public ip is <strong>10.101.10.1</strong>";
    echo "<p>go away intruder >:(</p>";
    echo "<p>people like you are always bad news , trying to steal from us just for the sake of some CTF points</p> </center><center><img src='./smurf.png' class='image'></center>";
    }
?>
