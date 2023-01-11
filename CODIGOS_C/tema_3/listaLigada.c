#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define MAXIMO 10
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct Registro{
    TIPOCHAVE chave;
    char nome[30];
    char sobreNome[30];
    char idade[3];
}Registro;

typedef struct Elemento{
    Registro reg;
    int proximo;
}Elemento;

typedef struct Lista{
    Elemento A[MAXIMO];
    int incicio;
    int disponivel;
}Lista;
void inicializacaoLista(Lista *lista){
    for (int i = 0; i < MAXIMO - 1; i++){
        lista->A[i].proximo = i + 1;
    }
    lista->A[MAXIMO - 1].proximo = INVALIDO;
    lista->incicio = INVALIDO;
    lista->disponivel = 0;
}

int tamanho(Lista *lista){
    int i = lista->incicio;
    int tam = 0;
    while (i != INVALIDO){
        tam++;
        i = lista->A[i].proximo;
    }
    return tam;
}

void exibirLista(Lista *lista){
    int i = lista->incicio;
    printf("Lista:\n");
    while (i != INVALIDO){
        printf("%d\n", lista->A[i].reg.chave);
        printf("%s", lista->A[i].reg.nome);
        printf("%s", lista->A[i].reg.sobreNome);
        printf("%s", lista->A[i].reg.idade);
        i = lista->A[i].proximo;
    }
    printf("\n");
}

int buscaSequencialOrdenada(Lista *lista, TIPOCHAVE chave){
    int i = lista->incicio;
    while (i != INVALIDO && lista->A[i].reg.chave < chave){
        i = lista->A[i].proximo;
    }
    if (i != INVALIDO && lista->A[i].reg.chave == chave){
        return i;
    }
    else{
        return INVALIDO;
    }
}

int obterNo(Lista *lista){
    int resultado = lista->disponivel;
    if (lista->disponivel != INVALIDO){
        lista->disponivel = lista->A[lista->disponivel].proximo;
    }
    return resultado;
}

int inserirItemListaOrdenado(Lista *lista, Registro reg){
    if (lista->disponivel == INVALIDO){
        return 0;
    }
    int anterior = INVALIDO;
    int i = lista->incicio;
    TIPOCHAVE chave = reg.chave;
    while ((i != INVALIDO) && (lista->A[i].reg.chave < chave)){
        anterior = i;
        i = lista->A[i].proximo;
    }
    if (i != INVALIDO && lista->A[i].reg.chave == chave){
        return 0;
    }
    i = obterNo(lista);
    lista->A[i].reg = reg;
    if (anterior == INVALIDO){
        lista->A[i].proximo = lista->incicio;
        lista->incicio = i;
    }
    else{
        lista->A[i].proximo = lista->A[anterior].proximo;
        lista->A[anterior].proximo = i;
    }
    return 1;
}

void devolverNo(Lista *lista, int posicao){
    lista->A[posicao].proximo = lista->disponivel;
    lista->disponivel = posicao;
}

void reinicializacao(Lista *lista){
    inicializacaoLista(lista);
}

int exclusaoItemLista(Lista *lista, TIPOCHAVE chave){
    int anterior = INVALIDO;
    int i = lista->incicio;
    while ((i != INVALIDO) && (lista->A[i].reg.chave < chave)){
        anterior = i;
        i = lista->A[i].proximo;
    }
    if (i == INVALIDO || lista->A[i].reg.chave != chave){
        return 0;
    }
    if (anterior == INVALIDO){ 
        lista->incicio = lista->A[i].proximo;
    }
    else{
        lista->A[anterior].proximo = lista->A[i].proximo;
    }
    devolverNo(lista, i);
    return 1;
}

void cadastrarDados(Lista *lista, Registro *reg){
    do {
        int flag;
        printf("Digite o identificador único: ");
        scanf("%d", &reg->chave);
        printf("Digite o nome: ");
        __fpurge(stdin);
        fgets(reg->nome, 30, stdin);
        printf("Digite o sobrenome: ");
        __fpurge(stdin);
        fgets(reg->sobreNome, 30, stdin);
        printf("Digite a idade: ");
        __fpurge(stdin);
        fgets(reg->idade, 3, stdin);
        (inserirItemListaOrdenado(lista, *reg) == 1) ? printf("Registrado com Sucesso.\n") : printf("Lista Cheia.\n");
        printf("Deseja inserir outro registro?(1: sim / 0: não) ");
        scanf("%d", &flag);
        if (flag == 0) break;
    } while (1);
}

int main(int argc, char const *argv[]){
    Lista lista, *pLista = &lista;
    Registro reg, *pReg = & reg;
    inicializacaoLista(pLista);
    cadastrarDados(pLista, pReg);
    exibirLista(pLista);

    return 0;
}
