/*******************/
/****  headers  ****/
/*******************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

/******************/
/****  macros  ****/
/******************/

#define SKIP_PARTITION_DESCRIPTOR   0x01be
#define SKIP_BOOT_INDICATOR         0x01be
#define SKIP_PARTITION_TYPE         0x01c2
#define SKIP_PARTITION_START        0x01c6
#define SKIP_PARTITION_SIZE         0x01ca
#define SKIP_VALIDITY_CHECK         0x01fe
#define OFFSET                      0x0010
#define PERM                             0

/****************************/
/**** variables globales ****/
/****************************/

int fd, buf;
unsigned char *pbuf = (unsigned char *) &buf;
char **argv_globl;

/********************/
/**** prototipos ****/
/********************/

int validity_check(void);
unsigned char partition_number(unsigned d);
unsigned char boot_indicator(unsigned d);
long int partition_start(unsigned d);
long int partition_size(unsigned d);
long int partition_end(unsigned d);
void tamano_dispositivo(void);
void particion_activa(void);
void espacio_total_dispositivo(int fd);
void lee_particion_activa(void);
void partition_size_KMGT(unsigned d);
void elimina_particion(void);
void activacion(void);
void borra_particion(unsigned d);
void activa_particion(unsigned d);
void cambia_tipo_particion(void);
void mostrar_tabla(void);
void procesar_comandos(void);
void mostrar_ayuda(void);
void partition_start_write(unsigned d);
void partition_end_write(unsigned d);
void partition_type_write(unsigned d);
void write_boot_sector(unsigned d);
int verifica_tamano_particiones(void);
void nombre_particion(int d);
void arregla_dispositivo(void);

/***********************************************************/
/****  funciones que solo leen la tabla de particiones  ****/
/***********************************************************/

int validity_check(void)
{
    if(lseek(fd, SKIP_VALIDITY_CHECK, SEEK_SET) != SKIP_VALIDITY_CHECK){
        printf("\nError lseek Validity Check\n");
        exit(-1);
    }
    if(read(fd, &buf, sizeof(buf)) <= 0){
        printf("\nError read Validity Check\n");
        exit(-1);
    }

    if(pbuf[0] == 0x55 && pbuf[1] == 0xaa){
        printf("\nfirma dispositivo ok: %x%x\n", pbuf[0], pbuf[1]);
        return 0;
    }
    else return -1;
}

void arregla_dispositivo(void)
{

    int nw = 0xaa55;
    char mi_buf[512];
    bzero(mi_buf, 512);
    lseek(fd, 0L, 0);

    if((write(fd, &mi_buf, sizeof(mi_buf))) < sizeof(mi_buf)){
        printf("\nError write PARTITION TABLE\n");
        exit(-1);
    }

    if(lseek(fd, SKIP_VALIDITY_CHECK, SEEK_SET) != SKIP_VALIDITY_CHECK){
        printf("\nError lseek FIRMA DISPOSITIVO\n");
        exit(-1);
    }

    if((nw = write(fd, &nw, sizeof(int))) < sizeof(int)){
        printf("\nError write FIRMA DE DISPOSITIVO\n");
        exit(-1);
    }
}
void tamano_dispositivo(void)
{

    printf("El tamaño del dispositivo %s es: ", *(argv_globl + 1)); /* Necesito que argv sea global en entonces*/
    espacio_total_dispositivo(fd);

    return;
}

void espacio_total_dispositivo(int fd)
{

    int ppio, final;
    double u;

    ppio = lseek(fd, 0L, 0);
    final = lseek(fd, 0L, 2);
    u = (final - ppio);

    if(u < 1024){
        printf("%3.0f\n", u);
        return;
    }
    else if(u >= 1024 && u < (1024*1024)){
        printf("%3.2fK\n", (float)u/1024);
        return;
    }
    else if(u >= (1024 *1024) && u < (1024*1024*1024)){
        printf("%3.2fM\n", (float)u/(1024*1024));
    }
   return;
}

void lee_particion_activa(void)
{
    unsigned i, bi[4];

    for(i = 0; i < 4; i++)
        if((bi[i] = boot_indicator(i)) != 0)
            printf("Particion %u activa\n", i);
    if(bi[0] == 0 && bi[1] == 0 && bi[2] == 0 && bi[3] == 0)
        printf("No hay particion activa\n");
    return;
}

unsigned char boot_indicator(unsigned d)
{

    if(lseek(fd, SKIP_BOOT_INDICATOR + d*OFFSET, SEEK_SET) != SKIP_BOOT_INDICATOR + d*OFFSET){
        printf("\nError lseek BOOT_PARTITION\n");
        exit(-1);
    }

    if(read(fd, &buf, sizeof(buf)) <= 0){
        printf("\nError read BOOT_PARTITION\n");
        exit(-1);
    }
    return pbuf[0];
}

unsigned char partition_number(unsigned n)
{
    if(lseek(fd, SKIP_PARTITION_TYPE + n*OFFSET, SEEK_SET) != SKIP_PARTITION_TYPE + n*OFFSET){
        printf("\nError lseek PARTITION TYPE\n");
        exit(-1);
    }

    if(read(fd, &buf, sizeof(buf)) <= 0){
        printf("\nError read PARTITION TYPE\n");
        exit(-1);
    }

    return pbuf[0];
}


long int partition_start(unsigned s)
{

    if(lseek(fd, SKIP_PARTITION_START + s*OFFSET, SEEK_SET) != SKIP_PARTITION_START + s*OFFSET){
        printf("\nError lseek PARTITION START\n");
        exit(-1);
    }
    if(read(fd, &buf, sizeof(buf)) <= 0){
        printf("\nError read PARTITION START\n");
        exit(-1);
    }
    return buf;
}


long int partition_size(unsigned t)
{

    if(lseek(fd, SKIP_PARTITION_SIZE + t*OFFSET, SEEK_SET) != SKIP_PARTITION_SIZE + t*OFFSET){
        printf("\nError lseek PARTITION SIZE\n");
        exit(-1);
    }
    if(read(fd, &buf, sizeof(buf)) <= 0){
        printf("\nError read PARTITION SIZE\n");
        exit(-1);
    }
    return buf;
}

long int partition_end(unsigned e)
{
    if((partition_size(e) + partition_start(e) - 1) < 0)
        return 0;
    return (partition_size(e) + partition_start(e) - 1);
}

void partition_size_KMGT(unsigned k)
{
    double u = partition_size(k)/2;

    if(u < 1024){
        printf("\t%10.0fK\n", u);
        return;
    }
    else if(u >= 1024 && u < (1024*1024)){
        printf("\t%10.2fM\n", u/1024);
        return;
    }
    else if(u >= (1024 *1024) && u < (1024*1024*1024)){
        printf("\t%10.2fG\n", u/(1024*1024));
        return;
    }
}

/********************************************************/
/**** funciones que escriben en tabla de particiones ****/
/********************************************************/

void activacion(void)
{
    unsigned u;
    printf("¿Que particion activamos? (nº): ");
    scanf("%u", &u);
    activa_particion(u);

    return;
}

void activa_particion(unsigned d)
{

    unsigned char i = 0x80;

    if(lseek(fd, SKIP_BOOT_INDICATOR + d*OFFSET, SEEK_SET) != SKIP_BOOT_INDICATOR + d*OFFSET){
        printf("\nError lseek BOOT_PARTITION\n");
        exit(-1);
    }

    if((write(fd, &i, 1)) != 1){
        printf("\nError write BOOT_PARTITION\n");
        exit(-1);
    }
    return;
}

void cambia_tipo_particion(void)
{
    unsigned d;

    printf("¿A qué partición le cambiamos el tipo? (nº): ");
    scanf("%u", &d);

    int nw, mi_buf = 0;

    if(lseek(fd, SKIP_PARTITION_TYPE + d*OFFSET, SEEK_SET) != SKIP_PARTITION_TYPE + d*OFFSET){
        printf("\nError lseek PARTITION TYPE\n");
        exit(-1);
    }

    printf("¿En qué tipo de partición la convertimos? (nº): ");
    scanf("%x", &mi_buf);

    if((nw = write(fd, &mi_buf, sizeof(mi_buf))) < sizeof(mi_buf)){
        printf("\nError write PARTITION TYPE\n");
        exit(-1);
    }
    return;
}

void elimina_particion(void)
{
    unsigned int n;

    printf("Que partición borramos? (nº): ");
    scanf("%u", &n);
    borra_particion(n);

    return;
}

void borra_particion(unsigned d)
{
    int nw;
    char mi_buf[16];
    bzero(mi_buf, 16);
    if(d < 0 || d > 3){
        printf("Número de particion invalido\n");
        procesar_comandos();
    }
    if(lseek(fd, SKIP_PARTITION_DESCRIPTOR + d*OFFSET, SEEK_SET) != SKIP_PARTITION_DESCRIPTOR + d*OFFSET){
        printf("\nError lseek PARTITION START\n");
        exit(-1);
    }

    if((nw = write(fd, &mi_buf, sizeof(mi_buf))) < sizeof(mi_buf)){
        printf("\nError write PARTITION\n");
        exit(-1);
    }

    return;
}

void agregar_particion(void)
{
    unsigned d, i;
    unsigned char p[4];

    for(d = 0; d < 4; d++){
        if(lseek(fd, SKIP_PARTITION_TYPE + d*OFFSET, SEEK_SET) != SKIP_PARTITION_TYPE + d*OFFSET){
            printf("\nError lseek PARTITION TYPE\n");
            exit(-1);
        }

        if(read(fd, &buf, sizeof(buf)) <= 0){
            printf("\nError read PARTITION_TYPE\n");
            exit(-1);
        }

        if(buf == 0){
            printf("Se puede agregar particion %u\n", d);
            p[d] = d;
        }
    }
    printf ("Numero de particion a agregar?: ");
    scanf("%d", &d);

    if(d != p[d] || d > 3 || d < 0){
        printf("\nEL numero ingresado es incorrecto\n");
        return;
        }

    partition_type_write(d);
    partition_start_write(d);
    partition_end_write(d);
    if(verifica_tamano_particiones() == -1)
        borra_particion(d);
    procesar_comandos();

    return;
}

void partition_type_write(unsigned d)
{
    int nw, mi_buf;
    if(lseek(fd, SKIP_PARTITION_TYPE + d*OFFSET, SEEK_SET) != SKIP_PARTITION_TYPE + d*OFFSET){
        printf("\nError lseek PARTITION TYPE\n");
        exit(-1);
    }

    printf("Ingrese tipo de partición (nº)(L para ver tipos): ");
    if(scanf("%x", &mi_buf) == 0)
        procesar_comandos();

    if((nw = write(fd, &mi_buf, sizeof(mi_buf))) < sizeof(mi_buf)){
        printf("\nError write PARTITION TYPE\n");
        exit(-1);
    }
    return;
}

void partition_start_write(unsigned d)
{
    unsigned i;
    long int u;

    /* Bloque comprobacion */

    printf("Desde sector: ");
    scanf("%ld", &u);

    for(i = 0; i < 4; i++){
        if(u >= partition_start(i) && u <= partition_end(i)){
            printf("ERROR: sector fuera de rango\n");
            borra_particion(d);
            procesar_comandos();
        }
    }

    /* Bloque escritura*/

    if(lseek(fd, SKIP_PARTITION_START + d*OFFSET, SEEK_SET) != SKIP_PARTITION_START + d*OFFSET){
        printf("\nError lseek PARTITION START\n");
        exit(-1);
    }

    if(write(fd, &u, sizeof(u)) <= 0){
        printf("\nError read PARTITION START WRITE\n");
        exit(-1);
    }
    return;
}

void partition_end_write(unsigned d)
{
    unsigned i;
    long int ppio, final, total, u, s;  //s: termina particion, u: tamano particion

    ppio = lseek(fd, 0L, 0);
    final = lseek(fd, 0L, 2);
    total = (final - ppio)/512;

    /*bloque comprobacion */

    printf("Hasta sector: ");
    scanf("%ld", &s);

    if(((u = s - partition_start(d) + 1) > total) || (u > final)){
        printf("ERROR: el ultimo sector del dispositivo es %ld\n", total);
        borra_particion(d);
        procesar_comandos();
    }

    for(i = 0; i < 4; i++){
        if(((u >= partition_start(i)) && (u <= partition_end(i))) || ( u > final)){
            printf("ERROR: sector fuera de rango\n");
            procesar_comandos();
            exit(-1);
        }
    }

    /* Bloque escritura */

    if(lseek(fd, SKIP_PARTITION_SIZE + d*OFFSET, SEEK_SET) != SKIP_PARTITION_SIZE + d*OFFSET){
        printf("\nError lseek PARTITION SIZE WRITE\n");
        exit(-1);

    }
    if(write(fd, &u, sizeof(u)) <= 0){
        printf("\nError write PARTITION END WRITE\n");
        exit(-1);
    }

    return;
}

int verifica_tamano_particiones(void)
{

    unsigned d;
	int total, ppio, final, parcial;

    ppio = lseek(fd, 0L, 0);
    final = lseek(fd, 0L, 2);
    total = (final - ppio);
    parcial = 0;

    for(d = 0; d < 4; d++){
        if(lseek(fd, SKIP_PARTITION_SIZE + d*OFFSET, SEEK_SET) != SKIP_PARTITION_SIZE + d*OFFSET){
            printf("\nError lseek VERIFICA TAMANO PARTICIONES\n");
            exit(-1);
        }
        if(read(fd, &buf, sizeof(buf)) <= 0){
            printf("\nError read VERIFICA TAMANO PARTICIONES\n");
            exit(-1);
        }
        parcial = parcial + buf;
    }
    if(parcial == (total/512))
        printf("ADVERTENCIA: No hay lugar para mas particiones\n");
    else if(parcial > total/512){
        printf("ERROR: PARTICION DEMASIADO GRANDE\nLa suma de los tamanos de las particiones supera al tamano del dispositivo\n");
        return -1;
    }
    return 0;
}

/*****************************/
/**** funciones generales ****/
/*****************************/


void mostrar_tabla(void)
{
    int i;

    printf("particion\t\tid\ttipo\t\t      inicio\t      fin\t\t tamaño\t\t  Capacidad\n");
    for(i = 0; i < 4; ++i){

        if(partition_number(i) > 0){
            printf("%s%d\t\t%2x\t",*(argv_globl + 1), i, partition_number(i));
            nombre_particion(partition_number(i));
            printf("%12ld %12ld\t   %12ld\t", partition_start(i), partition_end(i), partition_size(i));
            partition_size_KMGT(i);
        }

    }
    printf("\n(incio, fin y tamaño de la partición expresados en sectores\n");
    printf(" Capacidad expresado en múltiplos de byte)\n");
    verifica_tamano_particiones();
    return;
}


void procesar_comandos(void)
{
    char cmd[10] = "";
    int a, b, p;

    while(strcmp(cmd, "q") != 0){
        printf("\nIngresar comando (h para menu de ayuda): ");
        scanf("%s", cmd);
        printf("\n");

        if(strcmp(cmd, "d") == 0){
            elimina_particion();
        }
        else if(strcmp(cmd,"n") == 0){
            agregar_particion();
        }
        else if(strcmp(cmd,"p") == 0){
            mostrar_tabla();
        }
        else if(strcmp(cmd,"h") == 0){
            mostrar_ayuda();
        }
        else if(strcmp(cmd,"l") == 0){
            cambia_tipo_particion();
        }
        else if(strcmp(cmd,"t") == 0){
            tamano_dispositivo();
        }
        else if(strcmp(cmd, "L") == 0){
            imprime_lista_nombres();
        }
        else if(strcmp(cmd, "a") == 0){
            lee_particion_activa();
        }
        else if(strcmp(cmd, "A") == 0){
            activacion();
        }
        else if(strcmp(cmd, "w") == 0){
            printf("CUIDADO: SE BORRARA LA TABLA DE PARTICIONES\n Y SE ESCRIBIRA NUEVAMENTE LA FIRMA DE DISPOSITIVO\n");
            printf("Confirme pulsando nuevamente \"w\": ");
            scanf("%s", cmd);
            if(strcmp(cmd, "w") == 0){
                arregla_dispositivo();
            }

        }
    }

    exit(-1);
}

/****************/
/****  main  ****/
/****************/

int main(int argc, char **argv)
{

    if(argc != 2){
        printf("Uso: ./mi_fdisk dispositivo\n");
        exit(-1);
    }

    argv_globl = argv;

    if((fd = open(*(argv + 1), O_RDWR, 0)) < 0){
        printf("\nError al intentar abrir archivo %s\n", *(argv + 1));
        exit(-1);
    }
    if(validity_check() != 0){
        printf("%s no es un dispositivo\n", *(argv + 1));
        printf("Comando \"w\" arregla dispositivo/CUIDADO: BORRA TODOS LOS DATOS\n");
        procesar_comandos();
    }

    printf("Dispositivo: %s\nfile descriptor %d\n", *(argv + 1), fd);
    tamano_dispositivo();

    long int total = lseek(fd, 0L, 2) - lseek(fd, 0L, 0);

    printf("Cantidad total de sectores: %ld\n", total/512);
    procesar_comandos();
    close(fd);

    return 0;
}

/*****************/
/****  ayuda  ****/
/*****************/

void mostrar_ayuda(void)
{

    printf("h  :    muestra menú ayuda\n");
    printf("n  :    agregar partición\n");
    printf("w  :    arregla dispositivo\n");
    printf("p  :    muestra tabla de particiones\n");
    printf("d  :    borra partición\n");
    printf("l  :    cambia tipo de partición\n");
    printf("L  :    lista de tipos de  particiones\n");
    printf("t  :    muestra tamaño total dispositivo\n");
    printf("a  :    muestra particion activa\n");
    printf("A  :    hace particion activa\n");
    printf("q  :    sale\n\n");

    return;
}
