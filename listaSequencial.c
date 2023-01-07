#include <stdio.h>
#include <stdlib.h>

#define tamMaximo 10
typedef int TIPOCHAVE;

typedef struct Registro{
    TIPOCHAVE chave;
    char *nome[50];
    char *idade[3];
}Registro;

typedef struct Lista{
    Registro A[tamMaximo];
    int index;
}Lista;

void inicializarLista(Lista *lista){
    lista->index = 0;
}

int qtdElementosValidos(Lista *lista){
    return lista->index;
}

void mostrarItens( Lista *lista){
    printf("Os Elementos são:\n");
    for (int i = 0; i < lista->index; i++){
        printf("Numero Identificador: %d\n", lista->A[i].chave);
        printf("Nome: %s\n", lista->A[i].nome);
        printf("Idade: %s\n\n", lista->A[i].idade);
    }
    printf("Fim da lista.\n");
}

int buscaSequencial(Lista *lista, TIPOCHAVE chaveBuscada){
    int i;
    while (i < lista->index){
        if (chaveBuscada == lista->A[i].chave){
            return i;
        }
        else{
            i++;
        } 
    }
    return -1;
}

int inserirItemLista(Lista *lista, Registro reg, int posicaoInsercao){
    if ((posicaoInsercao < 0) || (lista->index == tamMaximo) || (posicaoInsercao > lista->index)) {
        return 0;
    }
    for (int i = lista->index; i > posicaoInsercao; i--){
        lista->A[i] = lista->A[i - 1];
    }
    lista->A[posicaoInsercao] = reg;
    lista->index++;
    return 1;
}

int excluirItemLista(Lista *lista, TIPOCHAVE chaveExclusao){
    int posicao = buscaSequencial(lista, chaveExclusao);
    if (posicao == -1){
        return 0;
    }
    for (int i = posicao; i < lista->index - 1; i++){
        lista->A[i] = lista->A[i + 1];
    }
    lista->index--;
    return 1;
}

void reinicializar(Lista *lista){
    inicializarLista(lista);
}

int main(int argc, char const *argv[]){
    
    
    
    return 0;
}
