#include<stdio.h>

int main()
{
    struct reg{
        int i;
        long l;
        char c;
    } reg1 = {2, 3, '9'};

    printf("sizeof(i) = %ld, sizeof(l) = %ld, sizeof(char)= %ld\n", sizeof(reg1.i),
            sizeof(reg1.l), sizeof(reg1.c));
    printf("siz"
            "eof(reg1) = %ld\n", sizeof(reg1));

    return 0;
}

