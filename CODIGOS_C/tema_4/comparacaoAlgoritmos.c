#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Temporizador{
    clock_t inicio;
    clock_t fim;
}Temporizador;

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

void preenchedorVetor(int *vetor, int tamanhoVetor, int rangeDosNumeros){
    Temporizador vet;
    vet.inicio = clock();
    for (unsigned long i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand() % rangeDosNumeros;
    }
    vet.fim = clock();
    printf("O preenchimento de vetor durou %.5f segundos.\n", ((double)(vet.fim - vet.inicio)) / CLOCKS_PER_SEC);
}

void executorFuncoes(void funcao(int*, int), int *vetor, int tamanhoVetor, char *nomeFuncao){
    Temporizador temp;
    temp.inicio = clock();
    funcao(vetor, tamanhoVetor);
    temp.fim = clock();
    printf("O algoritmo %s foi executado em %.5f segundos.\n", nomeFuncao, ((double)(temp.fim - temp.inicio)) / CLOCKS_PER_SEC);
}


int main(int argc, char const *argv[]){
    
    void (*pBubble)(int*, int) = &bubbleSort;
    void (*pInsertion)(int*, int) = &insertionSort;
    void (*pSelection)(int*, int) = &selectionSort;

    const unsigned long tamanhoVetor = 500000;
    int vetor[tamanhoVetor], rangeNumeros = 10000;
    srand(time(NULL));
    printf("O vetor contém %ld elementos aleatórios.\n", tamanhoVetor);

    preenchedorVetor(vetor, tamanhoVetor, rangeNumeros);
    
    executorFuncoes(pBubble, vetor, tamanhoVetor, "BubbleSort");

    preenchedorVetor(vetor, tamanhoVetor, rangeNumeros);

    executorFuncoes(pInsertion, vetor, tamanhoVetor, "InsertionSort");

    preenchedorVetor(vetor, tamanhoVetor, rangeNumeros);

    executorFuncoes(pSelection, vetor, tamanhoVetor, "SelectionSort");

    return 0;
}
