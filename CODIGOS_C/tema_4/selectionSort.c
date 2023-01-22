#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *vetor, int tamanhoVetor){
    int i,j,aux, minimo, pos_minimo;
    for (i=0; i < tamanhoVetor - 1; i++)
    {
        minimo = vetor[i];
        pos_minimo = i;
        for (j = i + 1; j < tamanhoVetor; j++) // Passo 1 
        {
            if (minimo > vetor[j])
            {
                minimo = vetor[j];
                pos_minimo = j;
            }
        }
        if (pos_minimo != i)  // Passo 2
        {
            aux = vetor[pos_minimo];
            vetor[pos_minimo] = vetor[i];
            vetor[i] = aux;
        }
    }
}

int main(int argc, char const *argv[]){
    
    const int tamanhoVetor = 50000;
    int vetor[tamanhoVetor];
    srand(time(NULL));

    for (int i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand() % 10000;
    }
    
    selectionSort(vetor, tamanhoVetor);

    for (int i = 0; i < tamanhoVetor; i++){
        printf("%d\n", vetor[i]);
    }
    return 0;
}
