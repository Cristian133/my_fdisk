		/********************************/
		/*	 						  	*/
		/*	 Lee sector de disco duro  	*/
		/*   int 0x13 ah=02			  	*/
		/*							  	*/
		/********************************/

		.code16
		.text
		.global _start

_start: /*Leemos primer sector de disco*/

		mov $0x02, %ah			#leer sector de disco
		mov $0x01, %al			#numero de sectores a leer: uno (1-128 dec o 1-80 hex)
		mov	$0x00, %ch			#00000000 Los 10 bits mas altos contienen la dir CHS del cilindro
		mov $0x01, %cl			#00/000001 del primer sector a leer y los 6 mas bajos, del sector.
		mov $0x00, %dh          #direccion CHS de la cabeza del primer sector logico a leer
		mov $0x80, %dl			#lee disco 1 (0x80) es decir sda
		mov $0xb800, %bx        #en ES:BX se escriben los sectores leidos
		mov %bx, %es			#segmento EX=0xc700 (fuera del mapeo de video)
		mov $0x0000, %bx		#offset   BX=0x0000 desde el ppio
		int $0x13               #llamada
		xor %cx, %cx            #limpia %cx

		mov %ah, %dl

		add $0x30, %al			#sectores leídos
		mov $0x0e, %ah 			#escribe en pantalla
		mov $0x00, %bh
		mov $0x07, %bl
		int $0x10

		mov $0x0a, %al
		mov $0x0e, %ah 			#escribe en pantalla
		mov $0x00, %bh
		mov $0x07, %bl
		int $0x10

		mov %dl, %al
		add $0x30, %al			#código de error: 0 = no error
		mov $0x0e, %ah 			#escribe en pantalla
		mov $0x00, %bh
		mov $0x07, %bl
		int $0x10

		mov $0x0a, %al
		mov $0x0e, %ah 			#escribe en pantalla
		mov $0x00, %bh
		mov $0x07, %bl
		int $0x10

		mov $0xb800, %dx
		mov $0x0020, %cx
		movb (%edx, %ecx), %al
		mov $0x0e, %ah 			#escribe en pantalla
		mov $0x00, %bh
		mov $0x07, %bl
		int  $0x10
