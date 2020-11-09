/*

Nuestra entrada sera a siguiente

5 nodos 9 vertices

conexiones:

1 2 y pesa 7
1 4 y pesa 2
2 3 y pesa 1
2 4 y pesa 2
3 5 y pesa 4
4 2 y pesa 3
4 3 y pesa 8
4 5 y pesa 5
5 3 y pesa 5


*/


#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

#define MAX //como maximo 10005 de vertices
#define Node pair<int, int>  //un nodo de tipo vector donde estamos definiendo <primero, segundo>
#define INF 1<<30  //definimos un valor que representa la distancia incial hasta con su perior maximo de la arista

/*
como habiamos visto en el pseudocodigo lo primero que se debe de programar
es la cola de prioridades para realizar el recorrido del grafo, para asi
poder saber donde estoy, a donde voy, donde inicio y donde termino, para
asi realizar operaciones con su peso, almacernos y despues de ello, realizar
el algoritmo del mejor camino cuyos pesos sean menores del punta A al B
*/


//cola
struct cpm{
    bool operador()(const Node &a, const Node &b){
        return a.second > b.second;
    }
};


vector<Node>ayd[MAX]; //lista de adyacencia acorde al tamaño definido de memoria

int distancia[MAX];  //distancia entre el vertice inicial al siguiente

bool visitado[MAX]; //que vertices se han visitado

//definir la cola de prioridad, para saber el menor valor que este a tope
priority-queue<Node, vector<Node>, cpm>Q;

int V;  //numero de vertices

int previo[MAX];   //para imprimir los caminos

//vamos a inicializar 

void init(){

	for(int i=0; i<=V; i++){
		distancia[i] = INF; //inicializamos todas las distancias con el valor infinito
		visitado[i] = false; //iniciaizamos todos los vertices como no visitados
		previo[i] = -1;  //inicializamos el previo del vertices con -1, para que sepamos que esta afuera del rango
	}

}


//vamos a relajarnos wiiii a mimir

void relajacion(int actual, int adyacente, int peso){
	/*
		Si la distancia del origen al vertice actual + el peso de su arista
		es menor a la distancia del origen al vertices adyacente
	*/
	if(distancia[actual] + peso < distancia[adyacente]){

		//relajamos el vertice actualizando la distancia
		distancia[adyacente] = distancia[actual]+peso;
		previo[adyacente] = actual  //actualizar el vertice previo
		Q.push(Node(adyacente, distancia[adyacente])); //la prioridad de la cola de adyacencia	

	}
}


//vamos a imprimir el camino mas chiquito desde el vertice inicial al final

void print(int destino){
	if(previo[destino] != -1){
		//aun no tiene un vertice previo 
		print(previo[destino]);
	}//vamos a empezar a explorarlo de forma recursiva
	print("%d", destino);
}
