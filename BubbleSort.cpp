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
/* Seu funcionamento � comparar dois a dois os elementos,
e levando ao fim do vetor o maior elemento, observe que,
a cada ordena��o o la�o interno percorre n-1 na pr�xima passada.*/
// COMPLEXIDADE O(n^2)
void bubble(int *vet, int n){
    int aux;
    //la�o externo
    for(int i=0; i<n; i++){
        //la�o interno, compara os elementos 2 a 2 dois e faz a troca quando necess�rio
        for(int j=0; j<n-1-i; j++){
            if (vet[j+1] < vet[j]){ //compara o elemento atual com o elemento seguinte
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

int main(){
    int vet[N];

    for(int i=0;i<N;i++)
        vet[i] = rand()%N;

    cout << "Vetor Desordenado: ";
    print(vet);
    cout << endl;

    bubble(vet,N);

    cout << "Vetor Ordenado: ";
    print(vet);
    cout << endl;


}
