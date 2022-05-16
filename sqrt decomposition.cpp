#include <bits/stdc++.h>
// by j o s e m a g o
#define Nmin 1000009
#define Nmax -1000009
using namespace std;
int n,Q,l,r,q,nn;
int a[50625];
int sqmin[225];
int sqmax[225];


int rmax(int l,int r){
    int minimo = Nmin;
    int kl = l/q; int kr = r/q;
    if(kl == kr) for(int i = l;i <= r;i++) minimo = min(minimo,a[i]);
    else{
        int kl_b = kl*q;
        int kr_b = kr*q;
        int kl_e = (kl+1)*q-1;
        int kr_e = (kr+1)*q-1;

        if(l == kl_b) minimo = min(minimo,sqmin[kl]);
        else for(int i = l;i <= kl_e;i++) minimo = min(minimo,a[i]);

        if(r == kr_e) minimo = min(minimo,sqmin[kr]);
        else for(int i = kr_b;i <= r;i++) minimo = min(minimo,a[i]);

        for(int i = kl+1;i <= kr-1;i++){
            minimo = min(minimo,sqmin[i]);
        }

    }
    return minimo;
}


int rmin(int l,int r){
    int maximo = Nmax;
    int kl = l/q; int kr = r/q;
    if(kl == kr) for(int i = l;i <= r;i++) maximo = max(a[i],maximo);
    else{
        int kl_b = kl*q;
        int kr_b = kr*q;
        int kl_e = (kl+1)*q-1;
        int kr_e = (kr+1)*q-1;

        if(l == kl_b) maximo = max(maximo,sqmax[kl]);
        else for(int i = l;i <= kl_e;i++) maximo = max(maximo,a[i]);

        if(r == kr_e) maximo = max(maximo,sqmax[kr]);
        else for(int i = kr_b;i <= r;i++) maximo = max(maximo,a[i]);

        for(int i = kl+1;i <= kr-1;i++) maximo = max(sqmax[i],maximo);




    }


    return maximo;

}

int main(){

    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(sqmin,sqmin+225,Nmin);
    fill(sqmax,sqmax+225,Nmax);

    cin >> n >> Q;
    q = ceil(sqrt(n));
    nn = q*q;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
        sqmin[i/q] = min(sqmin[i/q],a[i]);
        sqmax[i/q] = max(sqmax[i/q],a[i]);
    }
    for(int i = n;i < nn;i++){
        a[i] = 0;
    }

    for(int i = 0;i < Q;i++){
        cin >> l >> r;
        l--; r--;
        cout<<abs(rmax(l,r)-rmin(l,r))<<"\n";
    }








    return 0;
}
