#include <stdio.h>
#include <stdlib.h>

void testeVetor(int *vet){
    int tamanhoVetor;
    for (tamanhoVetor = 0; tamanhoVetor < vet[tamanhoVetor]; tamanhoVetor++);

    printf("O tamanho do vetor é: %d\n", tamanhoVetor - 1);
}

int main(int argc, char const *argv[]){
    int *vet = (int*) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++){
        *(vet + i) = i + 1;
        printf("%d\n", *(vet + i));
    }
    testeVetor(vet);
    return 0;
}
