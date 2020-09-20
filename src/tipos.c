#include<stdio.h>

int main()
{
    printf("char %ld\n", sizeof(char));
    printf("unsigned char %ld\n", sizeof(unsigned char));
    printf("int %ld\n", sizeof(int));
    printf("unsigned int %ld\n", sizeof(unsigned int));
    printf("short int %ld\n", sizeof(short int));
    printf("unsigned short int %ld\n", sizeof(unsigned short int));
    printf("long int %ld\n", sizeof(long int));
    printf("unsigned long int %ld\n", sizeof(unsigned long int));
    printf("double %ld\n", sizeof(double));
    printf("long double %ld\n", sizeof(long double));
    printf("void %ld\n", sizeof(void));
    return 0;
}

