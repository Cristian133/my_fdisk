		/********************************/
		/*	 						  	*/
		/*	 Lee sector de disco duro  	*/
		/*   int 0x13 ah=02			  	*/
		/*							  	*/
		/********************************/

		.code16
		.text
		.global _start

_start:

		mov $0x02, %ah			#leer sector de disco
		mov $0x01, %al			#numero de sectores a leer(1-128 dec o 1-80 hex)
		mov	$0x00, %ch			#00000000
		mov $0x01, %cl			#00000001
		mov $0x00, %dh
		mov $0x81, %dl			#lee disco 1 es decir sda
		mov $0x00, %bx
		mov %bx, %es
		mov $0x7e00, %bx		#offset
		int $0x13
		xor %cx, %cx

		mov $0x0e, %ah 			#escribe en pantalla
		mov $0x00, %bh
		mov $0x07, %bl
		int $0x10



