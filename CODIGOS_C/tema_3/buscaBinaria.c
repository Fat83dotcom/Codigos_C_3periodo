#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int vetor[], int itemProcurado){
    int baixo = 0;
    int alto, meio, chute;
    for (alto = 0; alto < vetor[alto]; alto++);
    alto -+ 1;
    while (baixo <= alto){
        meio = (baixo + alto) / 2;
        chute = vetor[meio];
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

int buscaBinariaRec(int vetor[], int itemProcurado){
    static int baixo = 0;
    static int alto;
}
int main(int argc, char const *argv[]){

    // int *listaNumeros = (int*) malloc(5 * sizeof(int));
    int listaNumeros[50000];
    int posNumProcurado;

    for (int i = 0; i < 50000; i++){
        *(listaNumeros + i) = i + 1;
    }
    posNumProcurado = buscaBinaria(listaNumeros, 5674);

    printf("%d\n", posNumProcurado);
    
    return 0;
}
