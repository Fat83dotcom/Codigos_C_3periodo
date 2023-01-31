#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct Aux{
    TIPOCHAVE chave;
    struct Aux *esquerda, *direita;
}Node;

typedef Node *Pont;

Pont inicializar(){
    return(NULL);
}

Pont adicionar(Pont raiz, Pont no){
    if (raiz == NULL){
        return no;
    }
    if (no->chave < raiz->chave){
        raiz->esquerda = adicionar(raiz->esquerda, no);
    }
    else{
        raiz->direita = adicionar(raiz->direita, no);
    }
    return(raiz);
}

Pont criarNo(TIPOCHAVE chave){
    Pont newNode = (Pont) malloc(1 * sizeof(Node));
    newNode->esquerda = NULL;
    newNode->direita = NULL;
    newNode->chave = chave;
    return(newNode);
}

Pont contem(Pont raiz, TIPOCHAVE chave){
    if (raiz == NULL) return (NULL);
    if (raiz->chave == chave) return (raiz);
    if (raiz->chave > chave) return (contem(raiz->esquerda, chave));
    return (contem(raiz->direita, chave));
}

Pont adicionadorNode(int chave, Pont raiz){
    Pont no = criarNo(chave);
    raiz = adicionar(raiz, no);
    return (raiz);
}

int contadorNodes(Pont raiz){
    if (!raiz) return 0;
    return (contadorNodes(raiz->esquerda) + 1 + contadorNodes(raiz->direita));
}

void exibirArvore(Pont raiz){
    if (raiz != NULL){
        printf("%d", raiz->chave);
        printf("(");
        exibirArvore(raiz->esquerda);
        exibirArvore(raiz->direita);
        printf(")");
    }
}

int main(int argc, char const *argv[]){
    srand(time(NULL));
    int qtdNodes, randomen, randd;
    qtdNodes = randomen = 20000;
    Pont raiz = inicializar();
    Pont no = criarNo((qtdNodes / 2));
    raiz = adicionar(raiz, no);
    for (int i = 0; i < qtdNodes; i++){
        randd = rand() % randomen;
        raiz = adicionadorNode(randd, raiz);
    }
    
    printf("%d\n", contadorNodes(raiz));
    exibirArvore(raiz);
    Pont p = contem(raiz, 15);
    printf("%p\n", p);
    return 0;
}
