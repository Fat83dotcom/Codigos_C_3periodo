#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    srand(time(NULL));
    const int tamanhoVetor = 10000;
    const int numeroProcurado = 190;
    int contador = 0;
    int realocadorMemoria = 1;
    int posicionadorMemoria = 0;
    int *numeros = (int*) malloc(tamanhoVetor * sizeof(int));
    int *posicaoDosNumeros = (int*) malloc(realocadorMemoria * sizeof(int));

    for (int i = 0; i < tamanhoVetor; i++){  
        *(numeros + i) = rand() % 1000;
    }
    for (int i = 0; i < tamanhoVetor; i++){
        if (*(numeros + i) == numeroProcurado){
            posicaoDosNumeros = (int*) realloc(posicaoDosNumeros, realocadorMemoria++ * sizeof(int));
            *(posicaoDosNumeros + posicionadorMemoria) = i;
            posicionadorMemoria++;
        }
    }
    for (int i = 0; i < tamanhoVetor; i++){
        if (*(numeros + i) == numeroProcurado){
            contador++;
        }
    }
    printf("O numero procurado %d, apareceu %d vezes nas posições: \n", numeroProcurado, contador);
    for (int i = 0; i < posicionadorMemoria ; i++){
        printf("%d, ", *(posicaoDosNumeros + i));
    }
    printf("\nO realocador de memoria marcou %dx, ocupando %d bytes de memoria"
     " e o posicionador de memoria marcou %d incrementos de memoria\n", realocadorMemoria, realocadorMemoria*4, posicionadorMemoria);
    // printf("%d\n", *(numeros + 5041));
    free(numeros);
    free(posicaoDosNumeros);

    return 0;
}
