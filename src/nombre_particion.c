#include <stdio.h>

void nombre_particion(unsigned char id)
{
    switch(id){

    case  0x00:
        printf("Vacía           ");
        break;

    case 0x24:
        printf("NEC DOS         ");
        break;

    case 0x81:
        printf("Minix / old Lin ");
            break;

    case 0xbf:
        printf("Solaris         ");
        break;

    case 0x01:
        printf("FAT12           ");
        break;

    case 0x27:
        printf("WinRE NTFS ocul ");
        break;

    case 0x82:
        printf("Linux swap / So ");
        break;

    case 0xc1:
        printf("DRDOS/sec (FAT- ");
        break;

    case 0x02:
        printf("XENIX root      ");
        break;

    case 0x39:
        printf("Plan 9          ");
        break;

    case 0x83:
        printf("Linux           ");
        break;

    case 0xc4:
        printf("DRDOS/sec (FAT- ");
        break;

    case 0x03:
        printf("XENIX usr       ");
        break;

    case 0x3c:
        printf("PartitionMagic  ");
        break;

    case 0x84:
        printf("Unidad C: ocult ");
        break;

    case 0xc6:
        printf("DRDOS/sec (FAT- ");
        break;

    case 0x04:
        printf("FAT16 <32M      ");
        break;

    case 0x40:
        printf("Venix 80286     ");
        break;

    case 0x85:
        printf("Linux extendida ");
        break;

    case 0xc7:
        printf("Syrinx          ");
        break;

    case 0x05:
        printf("Extendida       ");
        break;

    case 0x41:
        printf("PPC PReP Boot   ");
        break;

    case 0x86:
        printf("Conjunto de vol ");
        break;

    case 0xda:
        printf("Datos sin SF    ");
        break;

    case 0x06:
        printf("FAT16           ");
        break;

    case 0x42:
        printf("SFS             ");
        break;

    case 0x87:
        printf("Conjunto de vol ");
        break;

    case 0xdb:
        printf("CP/M / CTOS / . ");
        break;

    case 0x07:
        printf("HPFS/NTFS/exFAT ");
        break;

    case 0x4d:
        printf("QNX4.x          ");
        break;

    case 0x88:
        printf("Linux plaintext ");
        break;

    case 0xde:
        printf("Utilidad Dell   ");
        break;

    case 0x08:
        printf("AIX             ");
        break;

    case 0x4e:
        printf("QNX4.x segunda  ");
        break;

    case 0x8e:
        printf("Linux LVM       ");
        break;

    case 0xdf:
        printf("BootIt          ");
        break;

    case 0x09:
        printf("AIX bootable    ");
        break;

    case 0x4f:
        printf("QNX4.x tercera  ");
        break;

    case 0x93:
        printf("Amoeba          ");
        break;

    case 0xe1:
        printf("DOS access      ");
        break;

    case 0x0a:
        printf("OS/2 Boot Manag ");
        break;

    case 0x50:
        printf("OnTrack DM      ");
        break;

    case 0x94:
        printf("Amoeba BBT      ");
        break;

    case 0xe3:
        printf("DOS R/O         ");
        break;

    case 0x0b:
        printf("W95 FAT32       ");
        break;

    case 0x51:
        printf("OnTrack DM6 Aux ");
        break;

    case 0x9f:
        printf("BSD/OS          ");
        break;

    case 0xe4:
        printf("SpeedStor       ");
        break;

    case 0x0c:
        printf("W95 FAT32 (LBA) ");
        break;

    case 0x52:
        printf("CP/M            ");
        break;

    case 0xa0:
        printf("Hibernación de  ");
        break;

    case 0xeb:
        printf("BeOS fs        ");
        break;

    case 0x0e:
        printf("W95 FAT16 (LBA) ");
        break;

    case 0x53:
        printf("OnTrack DM6 Aux ");
        break;

    case 0xa5:
        printf("FreeBSD         ");
        break;

    case 0xee:
        printf("GPT            ");
        break;

    case 0x0f:
        printf("W95 Ext'd (LBA) ");
        break;

    case 0x54:
        printf("OnTrackDM6      ");
        break;

    case 0xa6:
        printf("OpenBSD         ");
        break;

    case 0xef:
        printf("EFI (FAT-12/16/");
        break;

    case 0x10:
        printf("OPUS            ");
        break;

    case 0x55:
        printf("EZ-Drive        ");
        break;

    case 0xa7:
        printf("NeXTSTEP        ");
        break;

    case 0xf0:
        printf("inicio Linux/PA ");
        break;

    case 0x11:
        printf("FAT12 oculta    ");
        break;

    case 0x56:
        printf("Golden Bow      ");
        break;

    case 0xa8:
        printf("UFS de Darwin   ");
        break;

    case 0xf1:
        printf("SpeedStor       ");
        break;

    case 0x12:
        printf("Compaq diagnost ");
        break;

    case 0x5c:
        printf("Priam Edisk     ");
        break;

    case 0xa9:
        printf("NetBSD          ");
        break;

    case 0xf4:
        printf("SpeedStor       ");
        break;

    case 0x14:
        printf("FAT16 oculta <3 ");
        break;

    case 0x61:
        printf("SpeedStor       ");
        break;

    case 0xab:
        printf("arranque de Dar ");
        break;

    case 0xf2:
        printf("DOS secondary   ");
        break;

    case 0x16:
        printf("FAT16 oculta    ");
        break;

    case 0x63:
        printf("GNU HURD o SysV ");
        break;

    case 0xaf:
        printf("HFS / HFS+      ");
        break;

    case 0xfb:
        printf("VMFS de VMware  ");
        break;

    case 0x17:
        printf("HPFS/NTFS ocult ");
        break;

    case 0x64:
        printf("Novell Netware  ");
        break;

    case 0xb7:
        printf("BSDI fs         ");
        break;

    case 0xfc:
        printf("VMKCORE de VMwa ");
        break;

    case 0x18:
        printf("SmartSleep de A ");
        break;

    case 0x65:
        printf("Novell Netware  ");
        break;

    case 0xb8:
        printf("BSDI swap       ");
        break;

    case 0xfd:
        printf("Linux raid auto");
        break;

    case 0x1b:
        printf("Hidden W95 FAT3 ");
        break;

    case 0x70:
        printf("DiskSecure Mult ");
        break;

    case 0xbb:
        printf("Boot Wizard hid ");
        break;

    case 0xfe:
        printf("LANstep         ");
        break;

    case 0x1c:
        printf("Hidden W95 FAT3 ");
        break;

    case 0x75:
        printf("PC/IX           ");
        break;

    case 0xbe:
        printf("arranque de Sol ");
        break;

    case 0xff:
        printf("BBT             ");
        break;

    case 0x1e:
        printf("Hidden W95 FAT1 ");
        break;

    case 0x80:
        printf("Old Minix       ");
        break;

    default:
        printf("Desconocido     ");
        break;
    }
    return;
}
