import subprocess
from pwn import *
r=process("./guess")
a=subprocess.run(["./solve"],capture_output=True).stdout
r.sendlineafter("number :",a)
r.interactive()

