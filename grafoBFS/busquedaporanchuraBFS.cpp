/*

Vamos a suponer que tenemos un grafo acorde a las siguientes condiciones


22 21
1 2
1 3
1 4
2 5
2 6
5 11
11 18
11 19
11 20
3 7
3 8
7 12
7 13
8 14
4 9
4 10
10 15
10 16
10 17
17 21
17 22

Todos estos son los caminos o las conexiones que tendra el grafo
y vamos a crear un algoritmo que se encargue de realizar su busqueda
de los nodos por medio de su anchura


*/

#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 500

vector<int> ady[ MAX ]; //sera para mi matriz de adyacencia
bool visitado[ MAX ];  //para saber si el nodo ya fue visitado


void bfs(){

    int ini, fin;
    printf("Nodo raiz: ");
    scanf("%d", &ini);//%d es para enteros %f flotantes   %s cadenas   %c caracteres
    printf("Nodo final: ");
    scanf("%d", &fin);

    //creamos una cola para almacenar los nodos
    queue<int> Q;

    Q.push(ini);
    //contar los pasos del recorrido

    int pasos = 0, maxi = 0;
    //mientras exista otro nodo
    //dice mientras la cola no este vacia haz
    while(!Q.empty()){
        //saber si la memoria de la cola esta siendo usada
        maxi = max(maxi, (int)Q.size());

        int actual = Q.front(); Q.back();

        pasos++;
        if(actual == fin)break;

        //los movimientos

        //tengo que saber donde estoy
        visitado[actual] = true;
        for(int i=0; i<ady[actual].size(); ++i){
            //estamos viendo que nodos son adyacentes al nodo que estoy visitando
            if(!visitado[ady[actual][i]]){
                //la i se refiere a la posicion en donde se encuentra el nodo
                printf("%d   -->  %d", actual, ady[actual][i]);
                //hay que meterlos a la cola
                Q.push(ady[actual][i]);
            }
        }
    }
    printf("Memoria maxima : %d\n", maxi);
    printf("Numeros de pasos que ha dado: %d\n", pasos);


}


//metodo principal

int main(){

    //declarar a nuestro grafo con sus elementos
    int V, E, x, y;
    //Numero de vertices y aristas
    scanf("%d %d", &V, &E);

    //recorrer su origin y su fin
    for(int i=1; i<=E; ++i){
        //necesitamos su orgigen y fin
        scanf("%d %d", &x, &y); //origen y destino, hasta el final

    }
    bfs();

    return 0;
}