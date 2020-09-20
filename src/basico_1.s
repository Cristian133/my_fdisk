//segmento de datos o data segment(DS), contiene los datos
//que usa el programa, lo que está en este segmento se
//puede ser accedido mediante punteros.
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

//segmento de sistema o system segment(SS), tiene los recursos
//del proceso, que este no puede manipular sino por medio
//del sistema operativo(SO).
		.bss
		.lcomm buff, 32

//segmento de texto o text segment(TS) contiene las instrucciones
// en lenguaje de máquina.
		.text
		.globl main			#hace visible main al linker
main:
		read $buff
		write $buff

		//exit devuelve 0
		movl $1, %eax
		movl $0, %ebx
		int $0x80
