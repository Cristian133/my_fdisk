#include<stdio.h>

int main()
{
    long int i = 0;
a:  if(i<(i+1)){
       i++;
       goto a;
    }
    printf("MAX %ld\n", i-1);

    i = 0;
s:  if(i>(i-1)){
       i--;
       goto s;
    }
    printf("MIN %ld\n", i);
    return 0;
}
