#!/usr/bin/env python3

def main():
	while True :
		path = input('Aim well :  ')
		try:
			with open(f"../challenge/../../Babyjail/./../Babyjail/./challenge/../../nothere/{path}/flag",'r', encoding = 'utf-8') as f:

				flag = f.read()
				print(flag)
		except:
			print('Too close')


if __name__ == '__main__':
	main()

