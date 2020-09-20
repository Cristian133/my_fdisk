#include<stdio.h>

int main()
{
    int i = 0x12345678;
    unsigned char *pi = (unsigned char *) &i;

    if( pi[0] == 0x12 && pi[1] == 0x34 && pi[2] ==0x56 && pi[3] == 0x78){
        printf("Este micro es BIG ENDIAa !\n");
    }
    else if( pi[0] == 0x78 && pi[1] == 0x56 && pi[2] ==0x34 && pi[3] == 0x12){
        printf("Este micro es LITTLE ENDIAN !\n");
    }
    else{
        printf("Este micro es un PDP/11 !\n");
    }
return 0;
}
