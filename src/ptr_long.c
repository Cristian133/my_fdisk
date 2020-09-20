#include<stdio.h>
int main()
{
    long int var = 0x123456789abdcef0;
    unsigned char* pvar = (unsigned char *) &var;
    unsigned i;

    for(i = 0; i < 8; i++)
        printf("pvar[%u] = %2x\n", i, pvar[i]);

    return 0;
}
