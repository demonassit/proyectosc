/*
crear una lista doble que permita
insertar
eliminar
modificar repetidos
 
 a traves del uso del metodo de burbuja 

 para ordenar diferentes datos numericos


*/


#include<conio.h>
#include<iostream>


//estructura del nodo de la lista

struct nodo{
    int nro;
    struct nodo*sgte;
};

typedef struct nodo*TLista;

using namespace std;

//los metodos necesarios para el programa
void insertarAlInicio(TLista &, int);
void insertarAlFinal(TLista &, int);  //tarea


//insertarlo en una posicion en especifico
void insertarEnPosicion(TLista &, int, int);

void eliminarElemento(TLista &, int);

//para eliminar elementos repetidos
void eliminarRepetidos(TLista);  //tarea

void eliminarListar(TLista &);  //tarea

//metodo burbuja
void burbuja(TLista);

void imprimir(TLista);  //tarea :3

void modificar(TLista &, int, int);

//ahi lo hacen va ya me dio sueñito nwn

int main(){

    TLista lista = NULL;
    int opc, valor, pos;
    //elementos que se repita
    do{
        //aqui debe de estar el menu del programa

        switch(opc){
            case 1:

            case 2: 

            //correspondiente con el menu
        }

    }while(opc!=numero de casos);

}


void insertarAlInicio(TLista &lista, int valor){
    TLista q;
    q = new(struct nodo);
    //apuntamos al inicio de la lista
    q->nro=valor;
    q->sgte=lista;
    lista=q; 
}

void insertarAlFinal(TLista &lista, int valor){
    //ahi lo terminan me dio mas sueñito
} 

void insertarEnPosicion(TLista &lista, int valor, int pos){
    TLista q, t;

    int i;

    q = new (struct nodo);
    q->nro=valor;

    //necesito saber donde esta la posicion antes o despues
    if(pos==1){
        q->sgte=lista;
        lista=q;
    }else{
        //entonces necesito otro n odo
        t = lista;
        for(i=1; t!=NULL; i++){
            //donde estoy
            if(pos==1){
                q->sgte=t->sgte;
                t->sgte=q;
                return;
            }
            t = t->sgte;
        }
    }
    //si me diste una posicion afuera del rango
    cout<<"Error la posicion es incorrecta"<<endl;
}


void eliminarElemento(TLista & lista, int valor){
    TLista q, ant;
    q=lista;

    while(q!=NULL){
        //primero necesitamos el valor que vamos a eliminar
        if(q->nro = valor){
            //tengo otra desicion donde diablos esta
            if(q==lista){
                lista = lista->sgte;

            }else{
                ant->sgte = q->sgte;
                delete(q);
                return;
            }
            
        }
        ant->q;
        q=q->sgte;
        
    }
}

void modificar(TLista &lista, int v, int pos){
    TLista q, stge;
    q = lista;

    int i;

    for(i = 0; i<pos-1&&q->sgte!=NULL; i++){
        q = q->sgte;
        q->nro = v;
    }
}


void burbuja(TLista lista){
    TLista actual, siguiente, marca;
    int i;
    marca = NULL;
    while(marca!=lista->sgte){
        actual=lista;
        siguiente=actual->sgte;
        //recorrer todos los elementos
        while(siguiente!=marca){
            //la comparacion para el ordenamiento
            if(actual->nro > siguiente->nro){
                i = siguiente->nro;
                siguiente->nro = actual->nro;
                actual->nro = i;
            }
            actual = actual->sgte;
            siguiente = actual->sgte;
        }
        marca=actual;
    }
}