 #include<stdio.h>

 struct registro{
      int i; double d; char c;
      };

 int main()
 {
      struct registro reg1 = { 1, 1.1, '1'}, reg2 = { 2, 2.2, '2'};

      struct registro *preg1 = &reg1, *preg2 = &reg2;

      int *preg1_i = &(reg1.i), *preg2_i = &(reg2.i);
      double *preg1_d = &(reg1.d), *preg2_d = &(reg2.d);
      char *preg1_c = &(reg1.c), *preg2_c = &(reg2.c);

       printf("\nLa estructura de tipo \"struct registro\" reg1 está en: %p\n",
            preg1);
       printf("\nY está conformada por: \n");
       printf("un entero i: reg1.i = %d ", reg1.i );
       printf("que está en: &(reg1.i) = %p \n" , preg1_i );
       printf("el mismo entero i: (*preg1).i = %d " , (*preg1).i );
       printf("que está en: &((*preg1).i) = %p \n" , &((*preg1).i) );
       printf("el mismo entero i: preg1­-> i = %d ", preg1->i );
       printf("que está en: &(preg1->i) = %p \n" , &(preg1->i) );
       printf("\nun double d: reg1.d = %f ", reg1.d );
       printf("que está en: &(reg1.d) = %p \n" , preg1_d );
       printf("el mismo double d: (*preg1).d = %f " , (*preg1).d );
       printf("que está en: &((*preg1).d) = %p \n" , &((*preg1).d) );
       printf("el mismo double d: preg1->d = %f ", preg1->d );
       printf("que está en: &(preg1->d) = %p \n" , &(preg1->d) );
       printf("\nun char c: reg1.c = %c ", reg1.c );
       printf("que está en: &(reg1.c) = %p \n" , preg1_c );
       printf("el mismo char c:(*preg1).c = %c ", (*preg1).c );
       printf("que está en: &((*preg1).c) = %p \n" , &((*preg1).c) );
       printf("el mismo char c: preg1->c = %c ", preg1->c );
       printf("que está en: &(preg1->c) = %p \n" , &(preg1->c) );
       printf("\nLa estructura de tipo \"struct registro\": reg2 está en: %p\n",
            preg2);
       printf("Y está conformada por: \n");
       printf("\nun entero i: reg2.i = %d ", reg2.i );
       printf("que está en: &(reg2.i) = %p \n" , preg2_i );
       printf("el mismo entero i: (*preg2).i = %d ", (*preg2).i );
       printf("que está en: &((*preg2).i) = %p \n" , &((*preg2).i) );
       printf("el mismo entero i: preg2->i = %d ", preg2->i );
       printf("que está en: &(preg2->i) = %p \n" , &(preg2->i) );
       printf("\nun double d: reg2.d = %f ", reg2.d );
       printf("que está en: &(reg2.d) = %p \n" , preg2_d );
       printf("el mismo double d: (*preg2).d = %f " , (*preg2).d );
       printf("que está en: &((*preg2).d) = %p \n" , &((*preg2).d) );
       printf("el mismo double d: preg2->d = %f ", preg2->d );
       printf("que está en: &(preg2->d) = %p \n" , &(preg2->d) );
       printf("\nun char c: reg2.c = %c ", reg2.c );
       printf("que está en: &(reg2.c) = %p \n" , preg2_c );
       printf("el mismo char c: (*preg2).c = %c ", (*preg2).c );
       printf("que está en: &((*preg2).c) = %p \n" , &((*preg2).c) );
       printf("el mismo char c: preg2->c = %c ", preg2->c );
       printf("que está en: &(preg2->c) = %p \n" , &(preg2->c) );

       reg1.i = 3;

       printf("Ahora modificamos:\n");
       printf("        reg1.i = 3;     \n");

       reg1.d = 3.3;
       printf("        reg1.d = 3.3;   \n");

       reg1.c = '3';
       printf("        reg1.c = '3';   \n");
       printf("Obteniendo:\n");
       printf("reg1.i = %d <=> (*preg1).i = %d <=> preg1->i = %d \n",
            reg1.i, (*preg1).i, preg1->i );
       printf("reg1.d = %f <=> (*preg1).d = %f <=> preg1->d = %f \n",
            reg1.d, (*preg1).d, preg1->d );
       printf("reg1.c = %c <=> (*preg1).c = %c <=> preg1->c = %c \n",
            reg1.c, (*preg1).c, preg1->c );

       (*preg1).i = 5;
       printf("Ahora modificamos:\n");
       printf("        (*preg1).i = 5; \n");

       (*preg1).d = 5.5;
       printf("        (*preg1).d = 5.5;       \n");

       (*preg1).c = '5';
       printf("        (*preg1).c = '5';       \n");

       printf("Obteniendo:\n");
       printf("reg1.i = %d <=> (*preg1).i = %d <=> preg1->i = %d \n",
            reg1.i, (*preg1).i, preg1->i );
       printf("reg1.d = %f <=> (*preg1).d = %f <=> preg1->d = %f \n",
            reg1.d, (*preg1).d, preg1->d );
       printf("reg1.c = %c <=> (*preg1).c = %c <=> preg1->c = %c \n",
            reg1.c, (*preg1).c, preg1->c );

       preg1->i = 7;
       printf("Ahora modificamos:\n");
       printf("        preg1->i = 7;   \n");

       preg1->d = 7.7;
       printf("        preg1->d = 7.7; \n");

       preg1->c = '7';
       printf("        preg1->c = '7'; \n");
       printf("Obteniendo:\n");
       printf("reg1.i = %d <=> (*preg1).i = %d <=> preg1->i = %d \n",
            reg1.i, (*preg1).i, preg1->i );
       printf("reg1.d = %f <=> (*preg1).d = %f <=> preg1->d = %f \n",
            reg1.d, (*preg1).d, preg1->d );
       printf("reg1.c = %c <=> (*preg1).c = %c <=> preg1->c = %c \n",
            reg1.c, (*preg1).c, preg1->c );

       preg2->i = 4;
       printf("Por último modificamos:\n");
       printf("        preg2->i = 4;   \n");

       preg2->d = 4.4;
       printf("        preg2->d = 4.4; \n");

       preg2->c = '4';
       printf("        preg2->c = '4'; \n");
       printf("Obteniendo:\n");
       printf("reg2.i = %d <=> (*preg2).i = %d <=> preg2->i = %d \n",
            reg2.i, (*preg2).i, preg2->i );
       printf("reg2.d = %f <=> (*preg2).d = %f <=> preg2->d = %f \n",
            reg2.d, (*preg2).d, preg2->d );
       printf("reg2.c = %c <=> (*preg2).c = %c <=> preg2->c = %c \n",
            reg2.c, (*preg2).c, preg2->c );
       printf("\nPOR LO TANTO:\n" );
       printf("LA OPERACIÓN CON EL OPERADOR SELECTOR DE MIEMBRO ");
       printf("PROPIO DE LAS ESTRUCTURAS:\n");
       printf("\n      estructura.variableMiembro\n" );
       printf("\nES EQUIVALENTE A USAR:\n");
       printf("\nLA OPERACIÓN CON EL OPERADOR \"­>\" ");
       printf("PROPIO DE LOS PUNTEROS A ESTRUCTURAS:\n");
       printf("\n      punteroAestructura -> variableMiembro\n" );
       printf("\nQUE TAMBIÉN ES EQUIVALENTE A USAR:\n");
       printf("\n      ( *punteroAestructura ).variableMiembro\n" );
       printf("\nYA SEA PARA MOSTRAR VALORES DE LAS VARIABLES MIEMBROS \n");
       printf("ASÍ COMO PARA MODIFICARLAS.\n" );
       return 0;
       // salida exitosa del programa
 }
