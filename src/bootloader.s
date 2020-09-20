# Author: Susam Pal <http://susam.in/>
#
# To assemble and link this code, execute the following commands:-
# as -o char.o char.s
# ld --oformat binary -o char char.o
#
# To write this code into the boot sector of a device, say /dev/sdb:-
# dd if=char of=/dev/sdb
# echo -ne "\x55\xaa" | dd seek=510 bs=1 of=/dev/sdb

.code16
.section .text
.globl _start
_start:
  mov $0xb800, %ax
  mov %ax, %ds
  movb $'A', 0
  movb $0x1e, 1
idle:
  jmp idle