#include <bits/stdc++.h>
#define JJJ 100000
using namespace std;
vector<int>grafo[JJJ];
int N,A,a,b,P,F;
int distancia[JJJ];
bool visited[JJJ];

void BFS(int nodo){
    queue<int>cola;
    cola.push(nodo);
    visited[nodo] = true;
    while(!cola.empty()){
        int zx = cola.front();
        cola.pop();
        for(int i = 0;i < grafo[zx].size();i++){
            int xx = grafo[zx][i];
            if(!visited[xx]){
                cola.push(xx);
                visited[xx] = true;
                distancia[xx] = distancia[zx]+1;
            }
        }
    }
}

void dfs(int nodo){
    visited[nodo] = true;
    for(int i = 0;i < grafo[nodo].size();i++){
        int xx = grafo[nodo][i];
        if(!visited[xx]) dfs(xx);
    }

}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> A >> P >> F;
    for(int i = 0;i < A;i++){
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    BFS(P);
    cout<<distancia[F]<<" distancia entre el nodo "<<P<<" y el nodo "<<F<<"\n";
    cout<<"\n";
    int comp = 0;
    memset(visited,false,sizeof visited);
    for(int i = 1;i <= N;i++){
        if(!visited[i]){
            comp++;
            dfs(i);
        }

    }

    cout<<comp<<" cantidad de componentes conexos";

    return 0;
}
