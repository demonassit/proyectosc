/*
ahi lo hacen wiiiii
*/


#include<iostream>

using namespace std;

/*
quiero que se pueda meter n cantidad de elementos a este programa
un metodo para meter los elementos del arreglo
primero ccuantos elementos y despues meterlos
*/

int array[] = {22, 55, 12, 1, 56, 89, 13, 17, 90, 9, 6, 2, 10};

//vamos a sacarle la micha
const int micha = sizeof(array)/sizeof(int);

void intercambio(int i, int j){
	int t = array[j];
	array[j] = array[i];
	array[i] = t;
	return;
}

void imprimirarreglo(){
	cout<<"Arreglo: \n";
	for(int i = 0; i < micha; i++){
		cout<<array[i]<<" ";
	}
	return;
}

void particionar(int inicio, int fin){
	int i = inicio + 1;
	int j = fin;
	
	if(fin <= inicio){
		return;
	}
	
	cout<<"\n A mimir wiii " <<inicio<<": = "<<array[i]<<" , "<<j<<": = "<<array[j]<<"\n";
	
	
	//ahora el pivote
	int pivote = array[inicio];
	
	cout<<"\n Privote: "<<inicio<<": = "<<array[inicio];
	
	if(inicio + 1 == j){
		if(array[inicio]>array[j]) intercambio(inicio, j);
		return;
	}
	
	while(i<j){
		//recursividad
		while(pivote>= array[i]&&micha-1)
		++i;
		
		while(pivote< array[j]&& j>0)
		--j;
		
		if(i<j){
			intercambio(i,j);
		}else{
			//intercambio a partir del pivote
			intercambio(inicio, j);
		}
	}
	
	imprimirarreglo();
	
	particionar(inicio, j-1);
	particionar(i, fin);
}

void quicksort(){
	particionar(0,micha-1);
	return;
}

int main(){
	cout<<"Metodo quicksort \n";
	quicksort();
	cout<<"Resultado final: \n";
	imprimirarreglo();
}
