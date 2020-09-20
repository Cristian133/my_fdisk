#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int elemento;
    struct nodo *izq, *der;
};

struct nodo *inserta( int elemento, struct nodo *nodo_actual);
void recorre( struct nodo *nodo_actual);

void recorre( struct nodo *nodo_actual)
{
    if( nodo_actual != NULL){

        recorre( nodo_actual->izq);
        printf("\n%d\n", nodo_actual->elemento);
        recorre( nodo_actual->der);
    }
}

struct nodo *inserta(int elemento, struct nodo *nodo_actual)
{
    if(nodo_actual == NULL){
        nodo_actual = malloc( sizeof( struct nodo));
        nodo_actual->elemento = elemento;
        nodo_actual->izq = nodo_actual->der = NULL;
    }
    else if(elemento < nodo_actual->elemento){
        nodo_actual->izq = inserta( elemento, nodo_actual->izq);
    }
    else if( elemento > nodo_actual->elemento){
        nodo_actual->der = inserta(elemento, nodo_actual->der);
    }

    return nodo_actual;
}


int main()
{
    struct nodo *arbol = NULL;
    int indice;
    for( indice = 99; indice > 0; indice -= 2){
        arbol = inserta(indice, arbol);
    }
    recorre( arbol);

    return 0;
}
