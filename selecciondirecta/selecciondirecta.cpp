/*

ejemplo de metodo de ordenamiento de seleccion directa
*/

#include<stdio.h>

using namespace std;

int main(){
	//declarar un arreglo
	int vector[4] = {3, 2, 5, 8};
	
	//variables para jugar
	int i, j, k, aux;
	
	//ordenamiento del array
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
