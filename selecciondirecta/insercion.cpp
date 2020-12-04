/*
metodo de ordenamiento de insercion

*/

#include<stdio.h>

using namespace std;

//declarar el arreglo

int arreglo[10] = {5, 2, 8, 22, 3, 6, 8, 12, 87, 2};

void imprimirarreglo(){
	int i;
	for(i=0; i<10; i++){
		printf("La posicion es: %d , El elemento es: %d\n", i, arreglo[i]);
	}
}

int main(){
	int i, j, k;
	//vamos a crear un metodo para imprimir el arreglo
	imprimirarreglo();
	
	//ordenamiento
	for(i=1; i<10; i++){
		j = i;
		while(j>=0 && arreglo[j]<arreglo[j-1]){
			k=arreglo[j];
			arreglo[j] = arreglo[j-1];
			arreglo[j-1] = k;
			j--;
		}
	}
	//que imprima el arreglo ordenamdo
	printf("\n El arreglo ordenado es: \n");
	imprimirarreglo();
}


