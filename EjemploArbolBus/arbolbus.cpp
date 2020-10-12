#include <iostream>
#include <stdlib.h>

using namespace std;

//estructura del arbolito

typedef struct nodo{
    int nro;
    struct nodo *izq, *der;
}*ABB;    //tipo de arbol ABB

//el numero de nodos del arbol ABB
int numNodos = 0;
//nodos menores que un numero k ingresado
int numK =0, k;


//vamos a crear una estructura de la cola del arbol

struct nodoCola{
    ABB ptr;
    struct nodoCola *sgte;
};

//vamos a crear la cola
struct cola{
    struct nodoCola *delante;
    struct nodoCola *atras;
};

//inicializacion de la colita
void inicializarCola(struct cola &q){
    //estamos apuntando a la direccion de memoria donde va a iniciar la cola
    //para la busqueda de los nodos del arbol, en pocas palabras
    //la que se encarga de recorrer, y recordemos que una cola
    //debe de tener un punto de inicio y un punto final, que quiere decir
    //vamos a ocupar la raiz del arbol como el inicio, y cada uno de los nodos
    //se vana meter en la cola, para la ramificación y recorrido
    q.delante = NULL;
    q.atras = NULL;
}

//adentro de la cola

void enCola(struct cola &q, ABB n){
    struct nodoCola *p;
    p = new(struct nodoCola);
    p->ptr = n;
    p->sgte = NULL;
    if(q.delante == NULL){
        q.delante = p;
    }else{
        (q.atras)->sgte = p;
    }
    q.atras = p;
    
}






