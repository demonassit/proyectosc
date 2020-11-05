/*
vamos a suponer que vamos a tener un grafo con los siguientes
nodos

5 3
1 2
2 3
4 5

Esas son las opciones o direccion de conexion entre nodos

*/

#include<stdio.h>
#include<vector>
#include<cstring>
//sirve para poder hacer operaciones con cadenas
//manipular los elementos de caracteres en matrices

using namespace std;
//LO QUE PUEDE OCUPAR DE MEMORIA
#define MAX 10001


vector<int> ady[ MAX ];

//tenemos que tener una variable que me detecte el recorrido
//para saber que caminos visito
bool visitado[ MAX ]; 
//para saber que nodos visito
bool visitado_componente[ MAX ];


//la defnicion de mi algoritmo para el recorrido
void dfs(int u){
    //saber si ya visite el camino
    visitado[u] = true;
    //saber si ya visite el nodo
    visitado_componente[u] = true;
    for(int v=0; v<ady[u].size(); v++){
        if(!visitado[ady[u][v]]){
            dfs(ady[u][v]);
        }
    }
}


int main(){
    //variables para el grafo
    int V, E, u, v;
    //elementos de memoria
    scanf("%d, %d", &V, &E);

    //ahora vamos a crear un bucle que se encargue de entrar y salir, meter y sacar
    while(E--){
        scanf("%d, %d", &u, &v);
        ady[u].push_back(v);
        ady[u].push_back(u);
    }


    printf("Cantidad de componetes conexos\n");
    int total = 0;
    //con esto puedo saber cuanto pesa cada uno de los caminos de mi grafo
    //primero el camino, el inicio, y su peso o tamaño
    memset(visitado, 0, sizeof(visitado));
    for(int i =1; i<=V; ++i){
        //vamos a recorrer todos los posibles caminos de las vertices 
        //en este caso solo tiene 1 wiiii
        //volvemos a preguntar si ya lo visite?
        if(!visitado[i]){
            memset(visitado_componente, 0, sizeof(visitado_componente));
            dfs(i);
            //recorremos el nodo y ya sabemos como se forma el grafo
            //imprimir los componentes del vertice o nodo
            printf("Componente: %d", total+1);
            //recorrer los valores del componente
            for(int j = 1; j<=V; ++j){
                if(!visitado_componente[j]){
                    printf(" %d ", j);
                }
            }
            printf("\n\n");
            total++;
        }
    }
    printf("%d\n", total);
    return 0;

}


