#include <bits/stdc++.h>
#define JJJ 105
#define Nmin 1e9
#define Nsum 0
#define Nmax -1e9
/*
Te dan un arreglo de n (1<=n<=100) elementos y Q (Q<=N) consultas.
Cada consulta tiene 4 elementos, oper,tipoQ,l,r. Si la respuesta de una
consulta es un numero primo. Tendra que ver la mayor secuencia incremental
del arreglo e imprimirla.
oper es un string min o max
tipoQ es un char 'Q' o 'U'
l y r enteros <=100

*/
using namespace std;
bool primo[105];
int arr[105];
int LISS[105];
int sqmin[105],sqmax[105],sqsum[105];

int n,Q,l,r,q,nn;
string oper;
char tip;
//Actualization
void updatemin(int i,int valor){
    sqmin[i/q] = min(valor,sqmin[i/q]);
    arr[i] = valor;
}
void updatemax(int i,int valor){
    sqmax[i/q] = max(sqmax[i/q],valor);
    arr[i] = valor;
}
void updatesum(int i,int valor){
    sqsum[i/q] += valor - arr[i];
    arr[i] = valor;
}
//query function
int rminq(int l,int r){
    int minimo = Nmin;
    int kl = l/q; int kr = r/q;
    if(kl == kr) for(int i = l;i <= r;i++) minimo = min(minimo,arr[i]);
    else{
        int kl_b = kl*q,kl_e = (kl+1)*q-1;
        int kr_b = kr*q,kr_e = (kr+1)*q-1;

        if(l == kl_b) minimo = min(sqmin[kl],minimo);
        else for(int i = l;i <= kl_e;i++) minimo = min(minimo,arr[i]);

        if(r == kr_e) minimo = min(minimo,sqmin[kr]);
        else for(int i = kr_b;i <= r;i++) minimo = min(minimo,arr[i]);

        for(int i = kl+1;i <= kr-1;i++) minimo = min(minimo,sqmin[i]);



    }

    return minimo;

}

int rmaxq(int l,int r){
    int maximo = Nmax;
    int kl = l/q; int kr = r/q;
    if(kl == kr) for(int i = l;i <= r;i++) maximo = max(maximo,arr[i]);
    else{
        int kl_b = kl*q,kl_e = (kl+1)*q-1;
        int kr_b = kr*q,kr_e = (kr+1)*q-1;

        if(l == kl_b) maximo = max(sqmax[kl],maximo);
        else for(int i = l;i <= kl_e;i++) maximo = max(maximo,arr[i]);

        if(r == kr_e) maximo = max(maximo,sqmax[kr]);
        else for(int i = kr_b;i <= r;i++) maximo = max(maximo,arr[i]);

        for(int i = kl+1;i <= kr-1;i++) maximo = max(maximo,sqmax[i]);



    }

    return maximo;

}

int rsq(int l,int r){
    int suma = Nsum;
    int kl = l/q; int kr = r/q;
    if(kl == kr) for(int i = l;i <= r;i++) suma+=arr[i];
    else{
        int kl_b = kl*q,kl_e = (kl+1)*q-1;
        int kr_b = kr*q,kr_e = (kr+1)*q-1;

        if(l == kl_b) suma+=sqsum[kl];
        else for(int i = l;i <= kl_e;i++) suma+=arr[i];

        if(r == kr_e) suma+=sqsum[kr];
        else for(int i = kr_b;i <= r;i++) suma+=arr[i];

        for(int i = kl+1;i <= kr-1;i++) suma+=sqsum[i];



    }

    return suma;

}

//LIS

int LIS(){
    int mayor = -1;
    LISS[0] = 1;
    for(int i = 1;i < n;i++){
        LISS[i]  = 1;
        for(int j = 0;j < i;j++){
            if(arr[i]>arr[j] && LISS[j]+1 > LISS[i]){
                LISS[i] = LISS[j]+1;
                mayor = max(mayor,LISS[i]);
            }
        }
    }


    return mayor;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(sqmin,sqmin+JJJ,Nmin);
    fill(sqmax,sqmax+JJJ,Nmax);
    fill(sqsum,sqsum+JJJ,0);
    memset(primo,true,sizeof primo);
    //sieve
    primo[0] = false; primo[1] = false;
    for(int i = 4;i <= 102;i+=2) primo[i] = false;
    for(int i = 3;i*i<=102;i+=2){
        if(primo[i]){
            for(int j = i*i;j <= 102;j+=2*i){
                primo[j] = false;
            }
        }
    }
    //input
    cin >> n >> Q;
    q = ceil(sqrt(n));
    nn = q*q;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        sqmin[i/q] = min(arr[i],sqmin[i/q]);
        sqmax[i/q] = max(arr[i],sqmax[i/q]);
        sqsum[i/q] += arr[i];
    }
    //query and answer
    for(int i = 0;i < Q;i++){
        cin >> oper >> tip >> l >> r;
        if(oper == "min"){
            if(tip == 'Q'){
                cout<<rminq(l,r)<<"\n";
                if(primo[rminq(l,r)]){
                    cout<<LIS();
                }
            }
            if(tip == 'U'){
                updatemin(l,r);
                if(primo[r]) cout<<LIS();
            }
        }
        else if(oper == "max"){
            if(tip == 'Q'){
                cout<<rmaxq(l,r)<<"\n";
                if(primo[rmaxq(l,r)]){
                    cout<<LIS()<<" LIS\n";
                }
            }
            if(tip == 'U'){
                updatemax(l,r);
                if(primo[r]) cout<<LIS()<<" LIS\n";
            }
        }
        else if(oper == "sum"){
            if(tip == 'Q'){
                cout<<rsq(l,r)<<"\n";
                if(primo[rsq(l,r)]){
                    cout<<LIS()<<" LIS\n";
                }
            }
            if(tip == 'U'){
                updatesum(l,r);
                if(primo[r]) cout<<LIS()<<" LIS\n";
            }
        }
    }


    return 0;
}
