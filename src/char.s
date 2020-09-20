bits 16
org 0x7c00

mov ah, 42h ; Funcion de bios
mov dl, 80h ; Leer el 1er disco IDE
mov si, diskaddr ; Descriptor de lectura
int 13h ; llamada a bios
jc error
; TODO OK
; Imprimir el byte 510 del MBR
mov ax, 0xb800
mov gs,ax
xor bx,bx
mov byte [gs:bx],'O'
inc bx
mov byte [gs:bx],0x0f
mov si,kernel
add si, 510
mov al, [si]
inc bx
mov byte [gs:bx],al
inc bx
mov byte [gs:bx],0x0f
fin:
  jmp fin
error:
mov ax, 0xb800
mov gs,ax
xor bx,bx
mov byte [gs:bx],'E'
inc bx
mov byte [gs:bx],0x0f
jmp error
diskaddr:       ; see table 00272 in Ralf Brown's Interrupt List
db 10h                  ; 10h = size of this structure
db 0                    ; reserved (padding)
dw 1                    ; # of sectors (blocks) to read
dd kernel               ; transfer buffer (load at this addr)
dq 0                    ; starting sector #
kernel:
.done   ret
pad:    times   510-($-$$) nop  ; pad to end of sector
dw      0xAA55          ; boot sector signature (magic #)
