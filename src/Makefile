all:
	nasm -f bin char.s -ochar.bin
	dd if=char.bin of=disk.img
	echo -ne "\x55\xaa" | dd seek=510 bs=1 of=disk.img
	qemu-system-x86_64 -hda disk.img
