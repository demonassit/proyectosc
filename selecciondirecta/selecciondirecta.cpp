/*

ejemplo de metodo de ordenamiento de seleccion directa
20 min para hacer la modificacion 

*/

#include<stdio.h>

using namespace std;

int main(){
	//declarar un arreglo
	//que el arreglo sea de n dimension y que el usuario ingrese el elemento
	int vector[4] = {3, 2, 5, 8};
	
	//variables para jugar
	int i, j, k, aux;
	
	//ordenamiento del array
	//que se cambia si ahora el arreglo es de n dimension?
	for(k = 0; k<=2; k++){
		i = k;
		aux = vector[k];
		for(j = k+1; j<=3; j++){
			if(vector[j] < aux){
				i = j;
				aux = vector[i];
			}
		}
		//intercambio
		vector[i] = vector[k];
		vector[k] = aux;
	}
	
	//imprimimos
	for(i=0; i<=3; i++){
		printf("%d", vector[i]);
	}
} 
