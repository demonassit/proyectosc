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