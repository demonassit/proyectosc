#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

/*
vamos a hacer un programa en el cual se ejemplifique el
metodo de ordenamiento de sacudida 
*/

int main(){
	int i, k, der, izq, aux, N, A[30];
	
	cout<<"Metodo de ordanamiento de la Sacudida wiiii"<<endl;
	cout<<"Ingrese el tamanio del arreglo que desea ordenar: "<<endl;
	cin>>N;
	k=N;
	izq=2;
	der=N;
	
	//recorrer y asginar
	
	for(i=1; i<=N; i++){
		cout<<"\t A["<<i<<"] : ";
		cin>>A[i];
	}
	
	//el ordenamiento
	do{
		//recorrer de derecha a izquierda
		for(i=der; i>=izq; i--){
			if(A[i-1]>A[i]){
				aux=A[i-1];
				A[i-1]=A[i];
				A[i]=aux;
				k=i;
			}
		}
		
		//izquierda a derecha
		izq=k+1;
		for(i=izq; i<=der; i++){
			if(A[i-1]>A[i]){
				aux=A[i-1];
				A[i-1]=A[i];
				A[i]=aux;
				k=i;
			}
		}
		der=k-1;
		
		system("pause");
		
	}while(izq<der);
	
	//imprimir el resultado ordenado
	cout<<"\n El arreglo ordenado es el siguiente: "<<endl;
	
	//necesitamos el for para imprimirlo
	for(i = 1; i <= N; i++){
		cout<<"\t"<<A[i]<<"\n"<<endl;
	}
	
	system("pause");
	return 0;
	getch();
}
