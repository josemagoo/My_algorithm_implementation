#include <bits/stdc++.h>
#define PAR pair<int,int>
#define peso first
#define valor second
using namespace std;
int n,M;
int tabla[100000];
int main(){
    cin >> n >> M;
    vector<PAR> objetos(n);
    for(int i = 0;i < n;i++){
        cin >> objetos[i].peso >> objetos[i].valor;
    }

    for(int i = 0;i < n;i++){
        for(int cap = objetos[i].peso;cap<=M;cap++){
            tabla[cap] = max(tabla[cap],tabla[cap-objetos[i].peso]+objetos[i].valor);
        }
    }
    cout << tabla[M];

    return 0;
}
