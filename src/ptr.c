#include<stdio.h>

int main()
{
    int i = 0X12345678;
    unsigned char *pi = (unsigned char *) &i;

    for(int j = 0; j < 4; j++){
        printf("pi[%d] = %x\n", j, pi[j]);
    }

    return 0;
}
