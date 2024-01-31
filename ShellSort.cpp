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

// COMPLEXIDADE O(entre n^1,25 e 1,6n^1,25), analises empiricas apontam que é mais eficiente que o InsertionSort
void shellSort(int *vet, int n){
    int aux, j, h;
    h = n/2;

    while ( h >= 1){
        for(int i = 1; i < n; i++){
            aux = vet[i];
            // trocamos no laço interno, todos os intervalos com "1" por h, e agora "j" decrementa em h.
            for (j = i-h; (j >= 0) && (vet[j] > aux)  ; j = j - h)
                vet[j+h] = vet[j];
            vet[j+h] = aux;
        }
        h = h/2;
    }

}

int main(){
    int vet[N];

    for(int i = 0;i < N; i++)
        vet[i] = rand()%N;

    cout << "Vetor Desordenado: ";
    print(vet);
    cout << endl;

    shellSort(vet,N);

    cout << "Vetor Ordenado: ";
    print(vet);
    cout << endl;


}
