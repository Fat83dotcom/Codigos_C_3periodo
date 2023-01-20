#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vet, int tamVet){
    int i, j, chave;
    for ( j = 1; j < tamVet; j++){
        chave = vet[j];
        i = j - 1;
        while (i >= 0 && vet[i] > chave){
            vet[i + 1] = vet[i];
            i--;
        }
        vet[i + 1] = chave;
    }
}

int main(int argc, char const *argv[]){
    int vet[10] = {3, 6, 9, 12, 1, 89, 4, 76, 323, 0};

    insertionSort(vet, 10);

    for (int i = 0; i < 10; i++){
        printf("%d\n", vet[i]);
    }
    
    return 0;
}
