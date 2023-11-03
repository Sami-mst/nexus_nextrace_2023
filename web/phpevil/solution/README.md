# EvilPHP

## Write-up

it's an old challenge from blackHatMEA quals and i recreated it:
 1-after checking the source code we can see comment saying check ?pihpi=
 
 2-we can see the php code and yes they are using two functions that we should worry about **preg_replace and eval **  ,
 
 3- ** if($_POST["username"]==="GUTS") ** so the username is GUTS, 
 
 4- ** $inp=preg_replace("/[^A-Za-z0-9$]/", "", $_POST["password"]); ** it's replacing anything that's not alphanumeric or $ with space, 
 
 5- ** if(eval("return \$inp=\"$inp\";")==="griffithDidNothingWrong") ** here the main condition so the result of the eval($inp) should be the password ,
 
 6- we can see ** $Role=$_POST["role"]; ** we have a variable  post parameter
 
 7- after analysing the code we should think about using the variable $Role to pass our password because the preg_replace accept the $ so our solution should be:
 
`curl -X POST http://178.62.77.6:2029 --data-binary $'username=GUTS&role=griffithDidNothingWrong&password=$Role'`
 
 
  

 

## Flag

`nexus{3v4l_1s_r3ally_ev1l1337}`