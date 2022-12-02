#include <stdio.h>
#include <stdlib.h>

int pesquisaBinaria(int *numeros, int itemProcurado){
    int contArray, baixo, alto, chute, meio;

    for (contArray = 0; numeros[contArray]; contArray++);
    
    baixo = 0;
    alto = contArray - 1;
    while (baixo <= alto){
        meio = (baixo + alto) / 2;
        chute = numeros[meio];
        if (chute == itemProcurado){
            return meio;
        }
        if (chute > itemProcurado){
            alto = meio - 1;
        }
        else{
            baixo = meio + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]){
    int i, numeroCalculado, resposta, tamanhoArray = 10, numeroBuscado = 17, *array;
    array = calloc(tamanhoArray, sizeof(int));
    for (i = 0; i < tamanhoArray; i++){
        numeroCalculado = i + (2 * (7 + i));
        array[i] = numeroCalculado;
    }
    resposta = pesquisaBinaria(array, numeroBuscado);
    if (resposta == -1){
        printf("O número %d não foi encontrado na lista.\n", numeroBuscado);
        free(array);
        return 0;
    }
    else{
        printf("Posição onde o número %d está no array: índice: %d\n", array[resposta], resposta);
        free(array);
        return 0;
    }
}
