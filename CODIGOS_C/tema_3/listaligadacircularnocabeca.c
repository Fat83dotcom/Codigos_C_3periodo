#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct Registro{
    TIPOCHAVE chave;
    char nome[30];
}Registro;

typedef struct TempRegistro{
    Registro reg;
    struct TempRegistro *proximo;
}Elemento;

typedef Elemento *Pont;

typedef struct Lista{
    Pont cabeca;
}Lista;

void inicializacao(Lista *lista){
    lista->cabeca = (Pont*) malloc(1 * sizeof(Elemento));
    lista->cabeca->proximo = lista->cabeca;
}


int main(int argc, char const *argv[]){
    
    return 0;
}
