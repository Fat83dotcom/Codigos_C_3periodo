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

typedef struct Aux{
    Registro reg;
    struct Aux *proximo;
}Elemento;

typedef Elemento * Pont;

typedef struct Lista{
    Pont inicio;
}Lista;

void inicializacao(Lista *lista){
    lista->inicio = NULL;
}

int tamanhoLista(Lista *lista){
    Pont endereco = lista-> inicio;
    int tamanho = 0;
    while (endereco != NULL){
        tamanho++;
        endereco = endereco->proximo;
    }
    return tamanho;
}

void imprimirLista(Lista *lista){
    Pont endereco = lista->inicio;
    printf("Lista:\n");
    while (endereco != NULL){
        printf("%d", endereco->reg.chave);
        printf("%s", endereco->reg.nome);
        endereco = endereco->proximo;
    }
}

Pont buscaSequencial(Lista *lista, TIPOCHAVE chave){
    Pont posicao = lista-> inicio;
    while (posicao != NULL){
        if (posicao->reg.chave == chave){
            return posicao;
        }
        posicao = posicao->proximo;
    }
    return NULL;
}

Pont buscaSequencialOrdenada(Lista *lista, TIPOCHAVE chave){
    Pont posicao = lista->inicio;
    while (posicao != NULL && posicao->reg.chave < chave){
        posicao = posicao->proximo;
    }
    if (posicao != NULL && posicao->reg.chave == chave){
        return posicao;
    }
    return NULL;
}

Pont buscaSequencialAuxiliar(Lista *lista, TIPOCHAVE chave, Pont *anterior){
    *anterior = NULL;
    Pont atual = lista->inicio;
    while ((atual != NULL) && (atual->reg.chave < chave)){
        *anterior = atual;
        atual = atual->proximo;
    }
    if ((atual != NULL) && (atual->reg.chave == chave)){
        return atual;
    }
    return NULL;
}

bool insercaoOrdenada(Lista *lista, Registro *reg){
    TIPOCHAVE chave = reg->chave;
    Pont indice, anterior;
    indice = buscaSequencialAuxiliar(lista, chave, &anterior);
    if (indice != NULL){
        return false;
    }
    indice = (Pont*) malloc(1 * sizeof(Elemento));
    indice->reg = *reg;
    if (anterior == NULL){
        indice->proximo = lista->inicio;
        lista->inicio = indice;
    }
    else{
        indice->proximo = anterior->proximo;
        anterior->proximo - indice;
    }
    return true;
}

bool excluirElementoLista(Lista *lista, TIPOCHAVE chave){
    Pont anterior, indice;
    indice = buscaSequencialAuxiliar(lista, chave, &anterior);
    if (indice == NULL){
        return false;
    }
    if (anterior == NULL){
        lista->inicio = indice->proximo;
    }
    else{
        anterior->proximo = indice->proximo;
    }
    free(indice);
    return true;
}

void reinicializar(Lista *lista){
    Pont endereco = lista->inicio;
    while (endereco != NULL){
        Pont deletado = endereco;
        endereco = endereco->proximo;
        free(deletado);
    }
    lista->inicio = NULL;
}

void inserirDadosLista(Lista *lista, Registro *reg){
    do {
        int flag;
        printf("Digite o identificador único: ");
        scanf("%d", &reg->chave);
        printf("Digite o nome: ");
        __fpurge(stdin);
        fgets(reg->nome, 30, stdin);
        (insercaoOrdenada(lista, reg) == 1) ? printf("Registrado com Sucesso.\n") : printf("Pilha Cheia.\n");
        printf("Deseja inserir outro registro?(1: sim / 0: não) ");
        scanf("%d", &flag);
        if (flag == 0) break;
    } while (1);
}
int main(int argc, char const *argv[]){
    
    return 0;
}
