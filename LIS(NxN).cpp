#include <iostream>
#include <vector>

using namespace std;

class Elemento{
public:
    int longitud;
    int antecesor;
};

int n;
int A[100];
vector<Elemento> LIS;
vector<int> subsecuencia;

void get_subsecuencia(int k){
    subsecuencia.push_back(A[k]);
    if(LIS[k].antecesor == -1)  return;
    else  get_subsecuencia(LIS[k].antecesor);
}

int main(){
    n = 8;
    A[0]=-7;  A[1]=10;  A[2]=9;  A[3]=2;
    A[4]=3;   A[5]=8;   A[6]=8;  A[7]=1;

    LIS.resize(8);
    // Caso base
    LIS[0].longitud = 1;
    LIS[0].antecesor = -1;


    for(int i=1; i<n; i++){
        LIS[i].longitud = 1;
        LIS[i].antecesor = -1;

        for(int j=0; j<i; j++){
            if(A[i] > A[j]  &&  LIS[j].longitud+1 > LIS[i].longitud){
                LIS[i].longitud = LIS[j].longitud + 1;
                LIS[i].antecesor = j;
            }
        }
    }

    int mayor=0;
    int indice=-1;
    for(int i=0; i<n; i++){
        if(LIS[i].longitud > mayor){
            mayor = LIS[i].longitud;
            indice = i;
        }
    }
    get_subsecuencia(indice);

    cout << "Longitud de mayor subsecuencia: " << mayor << "\n";
    cout << "Subsecuencia: ";
    int m = subsecuencia.size();
    for(int i=m-1; i>=0; i--){
        cout << subsecuencia[i] << " ";
    }
    cout << "\n";

    return 0;
}
