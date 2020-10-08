#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo{
    //la estructura de mi arbolito kawaii
    int nro;
    struct nodo *izq, *der;
};

/*
vamos a crear un puntero de tipo nodo el cual se llamara
AAB que se utiliza para la creacion de variables del arbol
*/

typedef struct nodo *AAB;

//es el metodo de el nodo
AAB crearNodo(int x){
    //estoy creando un objeto para el momento en que se inserte un nuevo nodo
    AAB nuevoNodo = new(struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    //la estructura basica para la creacion de nodos de un arbol
    //binario
    return nuevoNodo;
}


//vamos a insertar el dato

void insertar(AAB &arbol, int x){
    if(arbol==NULL){
        //el arbol esta vacio
        arbol = crearNodo(x);

    }
    //el orden que yo estoy estableciendo es que todos los numeros que sean
    //menores al nodo raiz van a ir a la izquierda 
    //y todos los que sean mayores al nodo raiz van a la derecha
    /*
                    6    si inserto 8, 5, 19
                5        8
                            19
    
    */
    else if(x<arbol->nro)
        insertar(arbol->izq, x);
    else if(x>arbol->nro)
        insertar(arbol->der, x);
}

//recorridos

void preOrden(AAB arbol){
    if(arbol!=NULL){
        cout<<arbol->nro<<" ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void postOrden(AAB arbol){
    if(arbol!=NULL){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->nro<<" ";
    }
}

void inOrden(AAB arbol){
    if(arbol!=NULL){
        inOrden(arbol->izq);
        cout<<arbol->nro<<"";
        inOrden(arbol->der);
    }
}

void verArbol(AAB arbol, int n){
    if(arbol!=NULL){
        return;
        verArbol(arbol->der, n+1);
        //vamos a recorrer cada uno de los nodos
        for(int i=0; i<n; i++){
            cout<<"      ";
            cout<<arbol->nro<<endl;
            verArbol(arbol->izq, n+1);
        }
    }
}


//el main

int main(){

    AAB arbol = NULL;
    int n; //el numero de nodos del arbol
    int x; //el elmento que voy a insertar

    cout<<"Un arbolito binario kawaii que va a buscar unos hotcakes\n\n";

    cout<<"Ingresa el numero de nodos del arbol\n";
    cin>>n;

    cout<<endl;

    //hacemos el ciclo o bucle de acuerdo al numero de nodos

    for(int i = 0; i<n; i++){
        cout<<"Numero del Nodo: "<<i+1<<" : ";
        cin>>x;
        insertar(arbol, x); 
    }

    cout<<"\n Mostrando el arbol kawaii AAB: \n\n";
    verArbol(arbol, 0);

    cout<<"\n Recorrido del arbol AAB: ";

    cout<<"\n En orden : \n"; 
    inOrden(arbol);
    cout<<"\n En preorden : \n"; 
    preOrden(arbol);
    cout<<"\n En postorden : \n"; 
    postOrden(arbol);
    cout<<endl<<endl;

    //para pausar el programar
    system("pause");
    return 0;
}