/*
un programa que ordene los elementos de un array por medio de un metodo 
con el uso de estructuras de ordenamiento para lo cual, dene permitir
ingresar el limite del arreglo, ingresar los elementos y mostrarlo ordenadito

*/

#include<iostream>
#include<conio.h>
#include<string.h>

#define MAX 50

struct ordenamiento{
    int elem;
};

using namespace std;

//metodos
void leerarray(int, struct ordenamiento[]);
void burbuja(int, struct ordenamiento[]);
void mostrar(int, struct ordenamiento[]);


int main(){
    int n;
    struct ordenamiento orden[MAX];

    cout<<"Ingrese el limite del arreglo:";
    cin>>n;

    leerarray(n, orden);
    burbuja(n, orden);

    cout<<endl<<"El arreglo ordenado es: "<<endl;

    mostrar(n, orden);

    getch();   

}


void leerarray(int n, struct ordenamiento a[]){
    for(int i =0; i<n; i++){
        cout<<"Ingrese el elemento";
        cin>>a[i].elem;
    }
}


void burbuja(int n, struct ordenamiento a[]){
    int i, j;
    struct ordenamiento temp;
    

    for(i = 1; i<n; i++){
        for(j=n-1; j>=i; j--){
            //comparacion
            if(a[j-1].elem>a[j].elem){
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void mostrar(int n, struct ordenamiento a[]){
    for(int i =0; i<n; i++){
        cout<<" "<<a[i].elem;
        
    }
}
