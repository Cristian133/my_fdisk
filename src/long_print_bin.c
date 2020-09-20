#include<stdio.h>

void print_bin(long x)
{
     unsigned i, indice = 1 << (sizeof(long) * 8 - 1);
     for(i = indice; i != 0; i >>= 1){
         putchar((x & i)? '1':'0');
     }
     putchar('\n');
}

int main()
{
     long x;

     printf("Ingrese un entero: ");
     scanf("%ld", &x);
     printf("binario: ");
     print_bin(x);

     return 0;
}
