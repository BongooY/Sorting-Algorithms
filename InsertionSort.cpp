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
/*Seu funcionamento é semelhante a ordenar cartas de baralho na mão.
Faz comparações e deslocamentos*/
// COMPLEXIDADE O(n^2)
void insertionSort(int *vet, int n){
    int aux, j;
    //laço externo
    // Começamos na posição 1, visto que a 0 já esta "ordenada".
    for(int i = 1; i < n; i++){
        aux = vet[i]; // pega o primeiro elemento da segunda parte
        //laço interno percorre de tras para frente, procurando e descolando elementos
        for (j = i-1; (vet[j] > aux) && (j >= 0); j--)
            vet[j+1] = vet[j];
        vet[j+1] = aux;
    }

}

int main(){
    int vet[N];

    for(int i = 0;i < N; i++)
        vet[i] = rand()%N;

    cout << "Vetor Desordenado: ";
    print(vet);
    cout << endl;

    insertionSort(vet,N);

    cout << "Vetor Ordenado: ";
    print(vet);
    cout << endl;


}
