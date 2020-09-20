		.code16
		.text
		.globl _start

_start:
		mov $0xb800, %bx #la dir se forma: ES:BX = b800:0000
		mov	%bx, %es
		mov $0x0000, %bx
		mov $0x0080, %dx
		mov $0x0001, %cx
		mov $0x0201, %ax

		int $0x13

		xorl %edx, %edx
		xorl %edx, %edx

		mov 0xc800, %dx
		mov 0x01c2, %bx
salta:
		movb (%edx,%ebx), %al
		mov $0x0e, %ah	#escribe pantalla
		mov	$0, %bh
		mov $0x07, %bl
		int $0x10

		incl (%ebx)
		cmp 0x01c4, %ebx
		jne salta
