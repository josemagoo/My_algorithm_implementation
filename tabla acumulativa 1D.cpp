#include <iostream>

using namespace std;
int tabla[10000];
int main(){
    int n,q,a,b;
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> tabla[i];
    }
    for(int i = 1;i <= n;i++){
        tabla[i] = tabla[i]+tabla[i-1];
    }
    for(int i = 0;i < q;i++){
        cin >> a >> b;
        cout<<tabla[b]-tabla[a-1];
    }



    return 0;
}
