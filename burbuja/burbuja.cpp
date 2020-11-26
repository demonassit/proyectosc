/*
vamos a realizar el algoritmo de ordenamiento de burbuja

*/

#include<stdio.h>
#include<conio.h>

#define TAM 9

int main(){
    //el arreglo predefinido para ordenar
    int a[TAM] = {9, 8, 0, 2, 5, 1 ,3, 2, 9};

    int i, pasada, aux;

    printf("Datos en el ordern inicial del arreglo: \n");
    for(i=0; i<=TAM; i++){
        printf("%d", a[i]);
    }


    //vamos a realizar un recorrido para la pasada
    for(i=0; i<=TAM-1; i++)
        for(i=0; i<=TAM-2; i++){
            //empezar a realizar las comparaciones
            if(a[i]>a[i+1]){
                //cuadno sea verdad
                //intercambio
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
            }
        }
    
    printf("\nDatos ordenaos en sentido ascendente son: \n");

    //para poder visualizar los datos otro for
    for(i=0; i<=TAM; i++)
        printf("%d", a[i]);

    printf("\n");

    return 0;
}