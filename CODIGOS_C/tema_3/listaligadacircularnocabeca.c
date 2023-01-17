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

int tamanhoLista(Lista *lista){
    Pont endereco = lista->cabeca->proximo;
    int tamanho = 0;
    while (endereco != lista->cabeca){
        tamanho++;
        endereco = endereco->proximo;
    }
    return tamanho;
}

void exibirLista(Lista *lista){
    Pont endereco = lista->cabeca->proximo;
    printf("Lista:\n");
    while (endereco != lista->cabeca){
        printf("%d", endereco->reg.chave);
        printf("%s", endereco->reg.nome);
        endereco = endereco->proximo;
    }
    printf("\n");
}

Pont buscaSentinela(Lista *lista, TIPOCHAVE chave){
    Pont posicao = lista->cabeca->proximo;
    lista->cabeca->reg.chave = chave;
    while (posicao->reg.chave != chave){
        posicao = posicao->proximo;
    }
    if (posicao != lista->cabeca){
        return posicao;
    }
    return NULL;
}

Pont buscaSentinelaListaOrdenada(Lista *lista, TIPOCHAVE chave){
    Pont posicao = lista->cabeca->proximo;
    lista->cabeca->reg.chave = chave;
    while (posicao->reg.chave < chave){
        posicao = posicao->proximo;
    }
    if (posicao != lista->cabeca && posicao->reg.chave == chave){
        return posicao;
    }
    return NULL;
}

Pont buscaSequencialAux(Lista *lista, TIPOCHAVE chave, Pont *anterior){
    *anterior = lista->cabeca;
    Pont atual = lista->cabeca->proximo;
    lista->cabeca->reg.chave = chave;
    while (atual->reg.chave < chave){
        *anterior = atual;
        atual = atual->proximo;
    }
    if (atual != lista->cabeca && atual->reg.chave == chave){
        return atual;
    }
    return NULL;
}

bool inserirElementosListaOrdenado(Lista *lista, Registro reg){
    Pont anterior, inserido;
    inserido = buscaSequencialAux(lista, reg.chave, &anterior);
    if (inserido != NULL){
        return false;
    }
    inserido = (Pont *) malloc(1 * sizeof(Elemento));
    inserido->reg = reg;
    inserido->proximo = anterior->proximo;
    anterior->proximo = inserido;
    return true;
}

bool excluirElementoLista(Lista *lista, TIPOCHAVE  chave){
    Pont anterior, excluido;
    excluido = buscaSequencialAux(lista, chave, &anterior);
    if (excluido == NULL){
        return false;
    }
    anterior->proximo = excluido->proximo;
    free(excluido);
    return true;
}
void reinicializacao(Lista *lista){
    Pont endereco = lista->cabeca->proximo;
    while (endereco != lista->cabeca){
        Pont apagar = endereco;
        endereco = endereco->proximo;
        free(apagar);
    }
    lista->cabeca->proximo = lista->cabeca;
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
