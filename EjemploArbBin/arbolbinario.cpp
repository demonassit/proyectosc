#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//vamos a crear la estructura base de un arbol

struct nodo{
    //primero va el dato
    char dato;
    //nodo derecho
    struct nodo *der;
    //nodo izquierda
    struct nodo *izq;
};

//ahora para poder operar las ramas izq y der

typedef struct nodo _nodo;

//vamos a crear una definicion de como van a operar las ramas izq y der del arbol

_nodo *crear(char dato){
    _nodo *nuevo;
    //en sizeof solicitas el tamño del tipo de dato de la estructura
    nuevo = (_nodo *)malloc(sizeof(_nodo));
    nuevo -> dato = dato;   //asigno al char
    nuevo -> der = NULL;
    nuevo -> izq = NULL;

    return nuevo; 

}

//metodo cuando vamos a agregar a derecha

_nodo *agregarDerecha(_nodo *nuevo, _nodo *raiz){
    raiz -> der = nuevo;
    return raiz;
}

//metodo cuando vamos a agregar izquierda

_nodo *ägregarIzquierda(_nodo *nuevo, _nodo *raiz){
    raiz -> izq = nuevo;
    return raiz;
}


//vamos a imprimir el arbol

void imprimir(_nodo *nodo){

    //tenemos que saber si el nodo esta vacio
    if(nodo != NULL){
        printf(" %c ", nodo->dato);
    }

}

//cuales son los modos de impresion de un arb bin


//preorden
void preOrden(_nodo *raiz){

    //nodo actual, rama izq, rama der
    if(raiz != NULL){
        imprimir(raiz);
        //recursividad
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
    
}

//inorden

void inOrden(_nodo *raiz){
    //izq raiz der
    if(raiz != NULL){
        inOrden(raiz->izq);
        imprimir(raiz);
        inOrden(raiz->der);
    }

}

//posorden
void posOrden(_nodo *raiz){
    //izq der raiz
    if(raiz != NULL){
        posOrden(raiz->izq);
        posOrden(raiz->der);
        imprimir(raiz);
    }
}

//ahora el metodo principal

int main(){

    _nodo *raiz;

    raiz = crear('+');
    raiz -> izq = crear('*');
    raiz -> der = crear('=');

    raiz -> izq -> izq = crear('A');
    raiz -> izq -> der = crear('B');

    raiz -> der -> izq = crear('/');

    raiz -> der -> izq -> izq = crear('C');
    raiz -> der -> izq -> der = crear('D');

    raiz -> der -> der = crear('2');

    //vamos a imprimir el arbolito de navidad *w*
    printf("Preorden (RID): ");
    preOrden(raiz);

    printf("\n InOrden (IRD): ");
    inOrden(raiz);

    printf("\n PostOrden (IDR): ");
    posOrden(raiz);

    printf("\n");

    return 0;
}