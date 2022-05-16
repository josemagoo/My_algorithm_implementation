#include <bits/stdc++.h>

using namespace std;

int n,m,ini;
vector<pair<int,int> >grafo[1005];
int distancia[1005];

void DIJKSTRA(int nodo){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >cola;
    distancia[nodo]=0;
    cola.push(make_pair(0,nodo));
    while(!cola.empty()){
        int ad=cola.top().second;
        int p=cola.top().first;
        cola.pop();
        if(p<=distancia[ad]){
            for(int i=0;i<grafo[ad].size();i++){
                int pp=grafo[ad][i].second;
                int ax=grafo[ad][i].first;
                if(distancia[ad]+pp<distancia[ax]){
                    distancia[ax]=distancia[ad]+pp;
                    cola.push(make_pair(distancia[ax],ax));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("bparty.in","r",stdin);
    //freopen("bparty.out","w",stdout);

    memset(distancia,999999,sizeof distancia);
    int a,b,c;
    cin >> n >> m >> ini;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        grafo[a].push_back(make_pair(b,c));
        grafo[b].push_back(make_pair(a,c));
    }
    DIJKSTRA(ini);
    int result=0;
    for(int i=1;i<=n;i++){
        result=max(distancia[i]*2,result);
    }
    cout << result;

    return 0;
}
