# unauthorized

## Write-up

decoding the token cookie gives us a json payload with a username and signature parameter , 
after some research you can find out that the signature is basically the sha1 hash of the inputed username , that being said , changing the username to admin and the signature the sha1 hash value of admin , then base64 encoding it and sending back to web server will log us as admin

## Flag

`nexus{cO0kie_1NteGRIty_f4Ilur3}`
