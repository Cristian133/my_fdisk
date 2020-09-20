		/*****************************************/
		/*										 */
		/* 		se utilizan dos formas			 */
		/* 		de lectura y escritura			 */
		/*                                       */
		/*****************************************/

		.data
		.macro write str	#inicia macro
			movl $4, %eax		#escribe
			movl $1, %ebx		#en stdout=1 pantalla
			movl \str, %ecx		#arg de la macro
			movl $32, %edx		#tamaño del arg.
			int $0x80			#llama a la int.
		.endm				#termina macro

		.macro read buff	#inicia macro
		    movl $3, %eax		#lee
			movl $0, %ebx		#desde sdin=0 teclado
			movl \buff, %ecx	#arg de la macro
			movl $32, %edx		#tamaño del arg.
			int  $0x80			#llamada a int.
		.endm				#termina macro

L:		.string "Hola mundo\n"

		.macro prologo
			pushl %ebp
			movl %esp, %ebp
		.endm

		.macro epilogo
			movl %ebp, %esp
			popl %ebp
		.endm

		.bss
		.lcomm buff, 32


		.text
		.globl main			#hace visible main al linker
main:
		read $buff
		write $buff

		prologo

		pushl $L
		call printf
		addl $4, %esp
		movl $0, %eax

		epilogo

		movl $1, %eax
		movl $0, %ebx
		int $0x80
