#include <iostream>
#include <cstdlib>
#define N 20

using namespace std;

void print(int *v){
    cout << "[";
    for(int i = 0; i<N; i++)
        cout << v[i] << " ";
    cout << "]";
}
/* O seu funcionamento � procurar pelo menor elemento, e joga-lo na primeira
posi��o, depois � feito outra busca s� que com tamanho n-1, ja desconsiderando
o elemento da primeira posi��o que j� foi ordenado.*/
// COMPLEXIDADE O(n^2)
void selectionSort(int *vet, int n){
    int menor, aux;
    // la�o externo (n-1 varreduras)
    for(int i=0; i<n-1;i++){
        menor = i;
        //encontrar o menor
        for(int j=(i+1); j<n; j++){
            if(vet[j] < vet[menor])
                menor = j; // menor vai conter o indice do menor elemento, ou seja, a posi��o do menor elemento
        } //encontrado o menor
        //Realizando a troca
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
}

int main(){
    int vet[N];

    for(int i=0;i<N;i++)
        vet[i] = rand()%N;

    cout << "Vetor Desordenado: ";
    print(vet);
    cout << endl;

    selectionSort(vet,N);

    cout << "Vetor Ordenado: ";
    print(vet);
    cout << endl;


}
