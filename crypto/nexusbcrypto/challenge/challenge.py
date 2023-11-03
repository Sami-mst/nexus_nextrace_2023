try:
	flag="nexus{F1n4lly_you_4re_h3r3!!}"
	n=25392301604326196534855112992099                                   
	print("-----------------------------------------welcome to our NexusBcrypto----------------------------------------------------------------------\nYou have to answer all the questions to get the flag\n (use lower case and spaces  to answer)\n\n")
	#first Q:
	
	if(input("First Part \nDo you think it's easy to decrypt this? XD :\n AABBA AABBA BAABB AABBA ABBAB BAABA ABAAA BAABA ABAAA BAABA ABAAA BAAAB AABAA AAAAA BAAAB BABBA\n")=="gg u got it it is easy"):
		if input("what about that one  : \n"+"--. .. ...- . / -- . / - .... . / ..-. .-.. .- --. / .-. -.\n")=="give me the flag rn":
		    	print("congrats we can move to the second Part\n")
		else:
			print("wrong answer :(\n")
	 
	#second Q:
	
		A1=input("Second part(RSA) \n find  the phi or Euler's totient : \n n="+str(n)+'\n')
		    
		if(A1=="25392301604326186456700201635320"):
				print("congrats here ur prize  "+flag)
		else:
			print("wrong answer :(\n")

	else:
		print("wrong answer :(\n")
except KeyboardInterrupt:
    print("\nTry Again	\n------------------------------------------------------------------------------------------------------------------------------------------")
    # Additional cleanup or handling code can be added here if needed

                        


