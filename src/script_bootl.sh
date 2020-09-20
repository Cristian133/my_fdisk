as -o bootl.o bootl.s
ld --oformat binary -Ttext 7c00 -Tdata 7cf0 -o bootl bootl.o
echo -ne "\x55\xaa"|dd seek=510 bs=1 of=bootl
qemu-system-x86_64 -hda bootl -hdb disk.img
