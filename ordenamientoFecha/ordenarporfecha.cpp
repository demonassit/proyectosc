/*
Vamos a realizar un programa que se encargue de ingresar n cantidad de trabajadores
incluyendo codigo, nombre, apellico, dia mes y año de nacimeinto y a partir de ahi
imprimir la lsita de lso trabajadores ordenado por fecha


*/

#include<iostream>
#include<conio.h>
#include<string.h>

#define MAX 50

//vamos a crear una estructura para la fecha y para el trabajor

using namespace std;

struct fecha{
    char dia[3];
    char mes[3];
    char annio[5];
};

struct trabajador{
    char codigo[9];
    char nombre[MAX];
    char apellido[MAX];
    struct fecha fecnac;
};

//metodos

//mostrar al personal
void leerpersonal(int, struct trabajador[]);
void ordenarxfecha(int, struct trabajador[]);
void listado(int, struct trabajador[]);

int bBinariafecha(int, struct trabajador[], struct fecha);

void main(){
    int n, pos;
    struct fecha f;
    struct trabajador x[MAX];

    cout<<"Ingresa el codigo del trabajor";
    cin>>n;
    leerpersonal(n, x);
    ordenarxfecha(n, x);
    listado(n, x);

    cout<<"Ingresa la fecha a buscar: "; cin>>f.dia;
    cout<<"Ingresa el mes: "; cin>>f.mes;
    cout<<"Ingresa el annio: "; cin>>f.annio;


    pos = bBinariafecha(n, x, f);

    if(pos==-1){
        cout<<"no se encuentra el trabajador";
    }else{
        cout<<"se encuentra en la posicion numero: "<<pos;
    }

    getch();

}

