#include <bits/stdc++.h>
#define JJJ 1000009
using namespace std;

bool primos[JJJ];

int main(){

    memset(primos,true,sizeof primos);
    for(int i = 4;i <= JJJ;i+=2) primos[i] = false;
    for(int i = 3;i*i<=JJJ;i+=2){
        if(primos[i]){
            for(int j = i*i;j <= JJJ;j+=2*i){
                primos[j] = false;
            }
        }
    }
    primos[0] = false; primos[1] = false;
    int n;
    while(cin >> n){
        if(primos[n]) cout<<"es primo\n";
        else cout<<"no es primo\n";
    }



    return 0;
}
