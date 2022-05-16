#include <bits/stdc++.h>
//cowflix mochila
using namespace std;
int tabla[50005];

int main(){
    int peso, cantidad;
    cin >> peso >> cantidad;
    vector<int> v(cantidad);
    for(int i = 0;i < cantidad;i++){
        cin >> v[i];
    }
    for(int i = 0;i < cantidad;i++){
        for(int j = peso;j >= v[i];j--){
            tabla[j] = max(tabla[j],tabla[j-v[i]]+v[i]);
        }
    }
    cout<<tabla[peso]<<endl;






    return 0;
}
