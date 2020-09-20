		.code16
		.data

message:
		.asciz "Particion          inicio          fin          tipo"

		.text
		.globl _start

_start:
		xor %di, %di
		mov $0xb800, %ax
		mov %ax, %ds
		mov $message, %si

move:
		xor %dx, %dx
		mov %cs:(%si), %dl
		cmp $0, %dl

		mov %dl, (%di)
		inc %di
		movb $0x07, (%di)
		inc %di
		inc %si

/*		mov $0xf800, %bx #la dir se forma: ES:BX = f800:0000
		mov	%bx, %es
		mov $0x0000, %bx
		mov $0x0080, %dx
		mov $0x0001, %cx
		mov $0x0201, %ax

		int $0x13
