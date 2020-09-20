 #include<stdio.h>

 struct registro{
      int i; double d; char c;
      };

 int main()
 {
      struct registro reg1 = { 1, 1.1, '1'}, reg2 = { 2, 2.2, '2'}, reg3 = {3, 3.3, '3'};

      struct registro *preg1 = &reg1, *preg2 = &reg2, *preg3 = &reg3;

      int *preg1_i = &(reg1.i), *preg2_i = &(reg2.i), *preg3_i = &(reg3.i);
      double *preg1_d = &(reg1.d), *preg2_d = &(reg2.d), *preg3_d = &(reg3.d);
      char *preg1_c = &(reg1.c), *preg2_c = &(reg2.c), *preg3_c = &(reg3.c);

       printf("\nLa estructura de tipo \"struct registro\" reg1 está en: %p\n",
            preg1);
       printf("\nY está conformada por: \n");
       printf("un entero i: reg1.i = %d ", reg1.i );
       printf("que está en: &(reg1.i) = %p \n" , preg1_i );
       printf("\nun double d: reg1.d = %f ", reg1.d );
       printf("que está en: &(reg1.d) = %p \n" , preg1_d );
       printf("\nun char c: reg1.c = %c ", reg1.c );
       printf("que está en: &(reg1.c) = %p \n" , preg1_c );
       printf("tamaño de la struct = %ld\n", sizeof(reg1));

       printf("\nLa estructura de tipo \"struct registro\" reg2 está en: %p\n",
            preg2);
       printf("\nY está conformada por: \n");
       printf("un entero i: reg2.i = %d ", reg2.i );
       printf("que está en: &(reg2.i) = %p \n" , preg2_i );
       printf("\nun double d: reg2.d = %f ", reg2.d );
       printf("que está en: &(reg2.d) = %p \n" , preg2_d );
       printf("\nun char c: reg2.c = %c ", reg2.c );
       printf("que está en: &(reg2.c) = %p \n" , preg2_c );


       printf("\nLa estructura de tipo \"struct registro\" reg3 está en: %p\n",
            preg3);
       printf("\nY está conformada por: \n");
       printf("un entero i: reg3.i = %d ", reg3.i );
       printf("que está en: &(reg3.i) = %p \n" , preg3_i );
       printf("\nun double d: reg3.d = %f ", reg3.d );
       printf("que está en: &(reg3.d) = %p \n" , preg3_d );
       printf("\nun char c: reg3.c = %c ", reg3.c );
       printf("que está en: &(reg3.c) = %p \n" , preg3_c );

       return 0;
 }
