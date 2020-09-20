#include<stdio.h>

void print_bin(int x)
{
    unsigned i, indice = 1 << (sizeof(int) * 8 - 1);

    for(i = indice; i != 0; i >>= 1){
        putchar((x & i)? '1':'0');
    }
    putchar('\n');
}

int main()
{
    int x;
    printf("Ingrese un entero: ");
    scanf("%d", &x);
    printf("binario: ");
    print_bin(x);

    return 0;
}
