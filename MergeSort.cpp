#include <iostream>
#include <cstdlib>
#define N 20

using namespace std;

void print(int *v){
    cout << "[";
    for(int i = 0; i < N; i++)
        cout << v[i] << " ";
    cout << "]";
}

void mergeIntercala(int *vet, int *aux, int ini, int meio, int fin){
    int atual, fimEsq, n;
    atual = ini;
    fimEsq = meio-1;
    n = fin - ini+1;

    while((ini <= fimEsq)&&(meio <= fin)){
        if(vet[ini] <= vet[meio])
            aux[atual++] = vet[ini++];
        else
            aux[atual++] = vet[meio++];
    }
    while(ini <= fimEsq)
        aux[atual++] = vet[ini++];
    while(meio <= fin)
        aux[atual++] = vet[meio++];

    for(int i = 0; i < n; i++){
        vet[fin] = aux[fin];
        fin--;
    }
}

void mergeDivide(int *vet, int *aux, int ini, int fin){
    int meio;
    if(fin > ini){ // se temos um elemento na posição fin, maior que na inicial significa que temos de continuar a dividir o vetor em subvetores
        meio = (ini + fin)/2;
        // divide em dois subproblemas (divide para conquistar)
        mergeDivide(vet,aux,ini,meio);
        mergeDivide(vet,aux,meio+1,fin);
        //combina as metades
        mergeIntercala(vet,aux,ini,meio+1,fin);
    }

}

// COMPLEXIDADE O(n log n)
// DIVISÃO E CONQUISTA
void mergeSort(int *vet, int n){
    int aux[n];
    mergeDivide(vet,aux,0,n-1);
}

int main(){
    int vet[N];

    for(int i = 0;i < N; i++)
        vet[i] = rand()%N;

    cout << "Vetor Desordenado: ";
    print(vet);
    cout << endl;

    mergeSort(vet,N);

    cout << "Vetor Ordenado: ";
    print(vet);
    cout << endl;


}
