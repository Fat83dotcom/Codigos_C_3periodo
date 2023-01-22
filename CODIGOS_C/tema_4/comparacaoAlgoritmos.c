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

void insertionSort(int *vetor, int tamanhoVetor){
    int i, j, chave;
    for ( j = 1; j < tamanhoVetor; j++){
        chave = vetor[j];
        i = j - 1;
        while (i >= 0 && vetor[i] > chave){
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = chave;
    }
}

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

typedef struct Temporizador{
    clock_t inicio;
    clock_t fim;
}Temporizador;

int main(int argc, char const *argv[]){
    
    Temporizador bubble, selection, insertion, vet;

    const unsigned long tamanhoVetor = 500000;
    int vetor[tamanhoVetor];
    srand(time(NULL));
    printf("O vetor contém %d elementos aleatórios.\n", tamanhoVetor);

    vet.inicio = clock();
    for (unsigned long i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand() % 100000;
    }
    vet.fim = clock();
    printf("O preenchimento de vetor durou %.5f segundos.\n", ((double)(vet.fim - vet.inicio)) / CLOCKS_PER_SEC);

    
    bubble.inicio = clock();
    bubbleSort(vetor, tamanhoVetor);
    bubble.fim = clock();
    printf("O algoritmo BubbleSort foi executado em %.5f segundos.\n", ((double)(bubble.fim - bubble.inicio)) / CLOCKS_PER_SEC);

    vet.inicio = clock();
    for (unsigned long i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand() % 100000;
    }
    vet.fim = clock();
    printf("O preenchimento de vetor durou %.5f segundos.\n", ((double)(vet.fim - vet.inicio)) / CLOCKS_PER_SEC);

    insertion.inicio = clock();
    insertionSort(vetor, tamanhoVetor);
    insertion.fim = clock();
    printf("O algoritmo InsertionSort foi executado em %.5f segundos.\n", ((double)(insertion.fim - insertion.inicio)) / CLOCKS_PER_SEC);

    vet.inicio = clock();
    for (unsigned long i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand() % 100000;
    }
    vet.fim = clock();
    printf("O preenchimento de vetor durou %.5f segundos.\n", ((double)(vet.fim - vet.inicio)) / CLOCKS_PER_SEC);

    selection.inicio = clock();
    selectionSort(vetor, tamanhoVetor);
    selection.fim = clock();
    printf("O algoritmo SelectionSort foi executado em %.5f segundos.\n", ((double)(selection.fim - selection.inicio)) / CLOCKS_PER_SEC);

    return 0;
}
