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


//recorrido dijkstra 

void dijkstra(int inicial){
	//vamos a inicializar los arreglos
	init();
	//insertando los vertices a la cola de prioridad
	Q.push(Node(inicial, 0));  
	//verificar la distancia inicial a 0
	distancia[inicial] = 0;
	
	int actual, adyacente, peso;
	
	//mientras cola no este vacia
	while(!Q.empty()){
		//obtenemos de la cola el nodo con el menor peso
		actual = Q.top().first;
		//sacarlo del elemento de la cola
		Q.pop();
		//si el vertice acutal ya fue visitado entonces sigo sacando elementos de la cola
		if(visitado[actual]) continue;
		//marcar el elemento como visitado
		visitado[actual]=true;
		
		//vamos a revisar la adyacencia de los vertices referente al actual
		for(int i = 0; i < ady[actual].size; ++i){
			//obtener el numero del vertice adyacente
			adyacente = ady[actual][i].first;
			//obtener el peso de la arista
			peso = ady[actual][i].second;
			
			//si el vertice adyacente no fue visitado
			if(!visitado[adyacente]){
				//realizamos la relajacion
				relajacion(actual, adyacente, peso);
			}
		}
	}
	
	printf("Distancia mas corta iniciado en le Vertice %d\n", inicial);
	
	for(int i = 0; i <= V; ++i){
		printf("Vertice %d, distancia mas corta %d\n ", i, distancia[i]);
	}
	
	
	puts("\n Impresion del camino mas corto wiiiii ono uwu \n");
	
	//aqui es donde el usuario ingresa el destino
	printf("Ingrese el vertice destino: ");
	int destino;
	
	scanf("%d", &destino);
	
	print(destino);
	
	printf("\n");
		
}



//el main

int main(){
	int E, origen, destino, peso, inicial;
	scanf("%d %d", &V, &E);
	while(E--){
		printf("Ingresa el origen el destino y su peso");
		scanf("%d %d %d", &origen, &destino, &peso);
		//si es un grafo dirigido
		ady[origen].push_back(Node(destino, peso));
		//para no dirigido
		ady[destino].push_back(Node(origen, peso));
	}
	printf("Ingresa el Vertice inicial");
	scanf("%d", &inicial);
	//mando a llamar a mi metodo de dijkstra
	dijkstra(inicial);
	return 0;
}
