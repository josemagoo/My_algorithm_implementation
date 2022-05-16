#include <bits/stdc++.h>
#define PAR pair<int,int>
using namespace std;
//BFS en Matrices
char matriz[1005][1005]; //Matriz que leo
int distancia[1005][1005]; //Matriz para guardar la distancia
bool visitados[1005][1005]; //Para marcar los visitados
int adyx[] = {1,-1,0,0}; //Para recorrer los adyacentes en las x
int adyy[] = {0,0,1,-1}; // en las y
int fila,columna,cont,resp;
void BFS(int x,int y){
    queue<PAR> cola;
    cola.push(make_pair(x,y));
    visitados[x][y] = true;
    cont = 1;
    while(!cola.empty()){
        int zx = cola.front().first;
        int zy = cola.front().second;
        cola.pop();
        for(int i = 0;i < 4;i++){
            int xx = zx + adyx[i];
            int yy = zy + adyy[i];
            if(xx >= 0 && xx < fila && yy >= 0 && yy < columna && visitados[xx][yy] == false && matriz[xx][yy] != '*'){
                cola.push(make_pair(xx,yy));
                visitados[xx][yy] = true;
                distancia[xx][yy] = distancia[zx][zy]+1;
                cont++;
            }
        }

    }

}


int main(){

    cin >> fila >> columna; //Leo la cantidad de filas y columnas

    for(int i = 0;i < fila;i++){
        for(int j = 0;j < columna;j++){         //Leo cada elemento de la Matriz
            cin >> matriz[i][j];
        }
    }
    for(int i = 0;i < fila;i++){
        for(int j = 0;j < columna;j++){
            if(matriz[i][j] == 'I'){
                BFS(i,j);
                resp = max(cont,resp);
            }
            if(matriz[i][j] == 'F'){
                cout<<"Dsitancia minima: " <<distancia[i][j]<<endl;
                cout<<"Tamaño que abarca el BFS: "<<resp<<endl;
                break;
            }
        }
    }






    return 0;
}
