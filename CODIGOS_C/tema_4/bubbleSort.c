#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *vetor, int tamanhoVetor){
    int i, j, aux;
    for (i = tamanhoVetor - 1; i > 0; i--){
        for (j = 0; j < i; j++){
            if (vetor[j] > vetor[j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main(int argc, char const *argv[]){
    const int tamanhoVetor = 500000;
    int vetor[tamanhoVetor];
    srand(time(NULL));

    for (int i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand() % 10000;
    }
    
    bubbleSort(vetor, tamanhoVetor);

    for (int i = 0; i < tamanhoVetor; i++){
        printf("%d\n", vetor[i]);
    }
    
    return 0;
}
