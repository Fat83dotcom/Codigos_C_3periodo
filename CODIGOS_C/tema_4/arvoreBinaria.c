#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char const *argv[]){
    Pont raiz = inicializar();
    Pont no =  criarNo(50);
    raiz = adicionar(raiz, no);
    no =  criarNo(25);
    raiz = adicionar(raiz, no);
    no =  criarNo(40);
    raiz = adicionar(raiz, no);
    no =  criarNo(15);
    raiz = adicionar(raiz, no);
    no =  criarNo(75);
    raiz = adicionar(raiz, no);
    no =  criarNo(90);
    raiz = adicionar(raiz, no);
    no =  criarNo(55);
    raiz = adicionar(raiz, no);
    return 0;
}
