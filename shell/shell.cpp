/*
metodo de ordenamiento shell
*/

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int n, i, x[100], salto, temp, b;
	
	char s;
	
	do{
		cout<<"Define la cantidad de elementos del arreglo:"<<endl;
		cin>>n;
		
		//recorremos el arreglo
		for(i = 0; i<n; i++){
			//introducimos los elementos
			cout<<"Elemento: ["<<i<<"]"<<endl;
			cin>>x[i];
		}
		//ahora tenemos que sacar la micha
		for(salto=n/2; salto>0; salto=salto/2){
		
		
		//tengo que empezar a determinar las comparaciones
		//entre cada uno de los elementos de la mitad del grupo
		//asi como lo establece el algotirmo
		//g1 e1 vs g2 e1
		do{
			b = 0;
			for(i=0; i<n-salto; i++){
				
				//se compara el primer grupo que es el que esta en el iterador i
				//contra el segundo grupo que es i+salto
				if(x[i]>x[i+salto]){
					temp = x[i];
					x[i] = x[i+salto];
					x[i+salto] = temp; 
					b=1;
				}
				
			}
		}while(b=0);
		
		}
		for(i=0; i<n; i++){
			cout<<x[i]<<" ";
			cout<<endl;
		}
		cout<<"Desea continuar s o n";
		cin>>s;
	
	}while(s=='s');
	getch(); 
}
