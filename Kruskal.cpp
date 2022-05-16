#include <bits/stdc++.h>
#define JJJ 10000
using namespace std;
int N,A,a,b,c;
vector<pair<int,pair<int,int> > >v;
int father[JJJ];

void init(){
    for(int i = 1;i <= N;i++){
        father[i] = i;
    }

}


int Find(int n){
    if(n == father[n]) return n;
    else return (father[n] = Find(father[n]));
}

void Union(int a,int b){
    father[b] = a;
}

int kruskal(){
    init();
    int suma = 0;
    int m = v.size();
    for(int i = 0;i < m;i++){
        int a = Find(v[i].second.first);
        int b = Find(v[i].second.second);
        if(a!=b){
            suma+=v[i].first;
            Union(a,b);
        }
    }

    return suma;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> A;
    for(int i = 0;i < A;i++){
        cin >> a >> b >> c;
        v.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(v.begin(),v.end());

    cout << kruskal();



    return 0;
}
