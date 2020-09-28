//librerias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>

using namespace std;


//una estrucctura se define de la siguiente forma en c++

struct dato{
    //una lista debe de tener un nodo de acceso, el dato y el apuntador
    //dato
    int i;
    dato *s; //nodo
}*a, *i, *p, *e;


int da;

//metodos de acceso a la lista

int buscar(int d);
void insertar(int dat);
void mostrar(void);
void borrar(void);
void menu(void);
void guardar(void);
void cargar(void);


//principal

main(){
    menu();
}


//metodo del menu
void menu(void){

    int opc, da;

    do{
        //imprimir la vista del menu
        cout<<"1.- Buscar datos";
        cout<<"\t 2.- Insertar datos";
        cout<<"\t 3.- Mostrar todos los datos";
        cout<<"\t 4.- Borrar un dato";
        cout<<"\t 5.- Guardar datos a un Archivo";
        cout<<"\t 6.- Cargar datos de un Archivo";
        cout<<"\t 0.- Salir";
        cout<<"\n Seleccione una opcion";
        cin>>opc;
        //un menu de opciones
        switch (opc)
        {
        case 0: 
            cout<<"\n\n Finalizar gracias Adios :3";
            getch();
            //pausa
            //antes de salir del programa se deben de borrar todos los datos de la lista
            p=i;
            while(p){

                a=p;
                p=p->s;
                delete(a);
            }
            exit(0);
        case 1:
            cout<<"\n\n Ingresa el datos a buscar:";
            cin>>da;
            if(buscar(da))
                cout<<"Datos Existe wiiiii";
            else
                cout<<"Dato no existe solo juguito contigo T_T ";
            getch();
            break;
        case 2:
            cout<<"Ingresa el Dato:";
            cin>>da;
            insertar(da);
            break;
        case 3:
            mostrar();
            break;
        case 4:
            borrar();
            break;
        case 5:
            guardar();
            break;
        case 6:
            cargar();
            break;
        
        default:
            cout<<"Opcion no valida aprender a leer ¬¬";
            getch();
        }

    }while(opc);

}


//metodo mostrar

void mostrar(void){
    int cont = 1;
    if(!i){
        cout<<"No hay lista para mostrar";
        getch();
        return;
    }
    p=i;
    cout<<endl<<endl;
    while(p){
        //como si existe la lista empezamos a recorrer los elementos o datos de la lista
        cout<<cont++<<"\n Valor = "<<p->i<<endl;
        // operador ->   es un apuntador de asignacion  
        // = es un operador para asignar un valor   a = 4
        // == es un operador de equivalencia    a == b
        p=p->s;
    }
    cout<<"\n Fin de la lista";
    getch();
}

int buscar(int d){

    if(!i){
        cout<<"\n No hay datos en la lista";
        getch();
        return(0);
    }

    //cuando si hay
    p=i;
    a = NULL;
    while(p->s && p->i<d){
        //recorrer los valores de la lista
        a=p;
        p=p->s;

    }
    return(p->i==d?1:0);

}

void insertar(int dat){

    if(!i){
        //creando un nuevo nodo para asignar el dato
        //aqui es cuando se ingresa el primer valor
        i = new(dato);
        i->s = NULL;
        i->i = dat;
        return; 
    }
    if(buscar(dat)){
        //inserto 1
        //insertar 1
        cout<<"\n El Dato Existe";
        getch();
        return;
    }
    //ahora inserte el 2
    //si tuvieramos varios valores en la lista    
    //  nodo3 = -4     nodo2= a==-3       nodo1 = 1    nnod4 = 2      nodo2= a==3 nod5= 23 NULL    ......
    e = new(dato);
    e->i=dat;
    if(p==i && p->s){
        if(p->i < e->i){
            p->s = e;
            e->s = NULL;
        }else{
            e->s = p;
            i=e;
        }
        return;
    }
    if(p->s){
        a->s = e;
        e->s = p;
        return;
    }
    if(e->i > p->i){
        e->s = NULL;
        p->s = e;
    }else{
        a->s = e;
        e->s = p;
    }
}

void borrar(void){
    cout<<"\n Ingresa el dato que deseas eliminar: ";   //23
    cin>>da;
    if(buscar(da)){

        if(a)
            a->s = p->s;   //asignar el nodo donde esta el dato
        else
            i = p->s;    //que obtenga el valor del nodo
        delete(p);
        cout<<"\n Dato eliminado";
    }else{
        cout<<"\n Dato no se encuentra T_T";
        getch();
    }
}