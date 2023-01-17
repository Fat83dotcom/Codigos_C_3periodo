#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int TIPOCHAVE;
typedef int bool;

typedef struct Registro{
    TIPOCHAVE chave;
    char nome[30];
}Registro;

typedef struct Aux{
    Registro reg;
    struct Aux *proximo;
}Elemento;

typedef Elemento *Pont;

typedef struct Pilha{
    Pont topo;
}Pilha;

void inicializacao(Pilha *pilha){
    pilha->topo = NULL;
}

int tamanhoPilha(Pilha *pilha){
    Pont endereco = pilha->topo;
    int tamanho = 0;
    while (endereco != NULL){
        tamanho++;
        endereco = endereco->proximo;
    }
    return tamanho;
}

bool vazia(Pilha *pilha){
    if (pilha->topo == NULL){
        return true;
    }
    return false;
}

void exibirPilha(Pilha *pilha){
    Pont endereco = pilha->topo;
    printf("Pilha:\n");
    while (endereco != NULL){
        printf("%d", endereco->reg.chave);
        printf("%s", endereco->reg.nome);
        endereco = endereco->proximo;
    }
    printf("\n");
}

bool inserirElementoPilha(Pilha *pilha, Registro reg){
    Pont novoElemento = (Pont*) malloc(1 * sizeof(Elemento));
    novoElemento->reg = reg;
    novoElemento->proximo = pilha->topo;
    pilha->topo = novoElemento;
    return true;
}

bool excluirElementoPilha(Pilha *pilha, Registro *reg){
    if (pilha->topo == NULL){
        return false;
    }
    *reg = pilha->topo->reg;
    Pont apagar = pilha->topo;
    pilha->topo = pilha->topo->proximo; 
    free(apagar);
    return true;
}

reinicializarPilha(Pilha *pilha){
    Pont apagar, posicao = pilha->topo;
    while (posicao != NULL){
        apagar = posicao;
        posicao = posicao->proximo;
        free(apagar);
    }
    pilha->topo = NULL;
}

int main(int argc, char const *argv[]){
    

    return 0;
}
