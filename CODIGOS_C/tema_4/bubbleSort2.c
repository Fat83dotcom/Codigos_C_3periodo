#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int *vetor, int tamanhoVetor){
	int troca = 1, i = 0, aux;
	while (troca){
		troca = 0;
		while (i < tamanhoVetor - 1){
			if (vetor[i] > vetor[i + 1])
			{
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
				troca = 1;
			}
			i++;
		}
		i = 0;
	}
}

int main(int argc, char const *argv[]){
    
    const int tamanhoVetor = 50000;
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
