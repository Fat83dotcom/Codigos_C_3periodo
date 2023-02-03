#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct Aux{
    TIPOCHAVE chave;
    struct Aux *esquerda,*direita;
    int h;
}Node;

typedef Node *Pont;

Pont criarNode(TIPOCHAVE chave){
    Pont newNode = (Pont) malloc(1 * sizeof(Node));
    newNode->esquerda = NULL;
    newNode->direita = NULL;
    newNode->h = 0;
    newNode->chave = chave;
    return newNode;
}

Pont inicializar(){
    return(NULL);
}

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int altura(Pont raiz){
    if (!raiz){
        return -1;
    }
    return raiz->h;
}

Pont rotacionaDireita(Pont raiz){
    Pont aux;
    aux = raiz->esquerda;
    raiz->esquerda = aux->direita;
    aux->direita = raiz;
    
    raiz->h = max(altura(raiz->direita), altura(raiz->esquerda) + 1);
    aux->h = max(altura(aux->esquerda), raiz->h) + 1;
    return aux;
}

Pont rotacionaEsquerda(Pont raiz){
    Pont aux;
    aux = raiz->direita;
    raiz->direita = aux->esquerda;
    aux->esquerda = raiz;
    
    raiz->h = max(altura(raiz->esquerda), altura(raiz->direita) + 1);
    aux->h = max(altura(aux->direita), raiz->h) + 1;
    return aux;
}

Pont rotacionaDireitaEsquerda(Pont raiz){
    raiz->direita = rotacionaDireita(raiz->direita);
    return rotacionaEsquerda(raiz);
}

Pont rotacionaEsquerdaDireita(Pont raiz){
    raiz->esquerda = rotacionaEsquerda(raiz->esquerda);
    return rotacionaDireita(raiz);
}

Pont inserirNode(Pont raiz, TIPOCHAVE chave){
    if (!raiz){
        return criarNode(chave);
    }
    if (chave < raiz->chave){
        raiz->esquerda = inserirNode(raiz->esquerda, chave);
        if ((altura(raiz->esquerda) - altura(raiz->direita)) == 2){
             if (chave < raiz->esquerda->chave){
                raiz = rotacionaDireita(raiz);
            }
            else{
                raiz = rotacionaEsquerdaDireita(raiz);
            }
        }
    }
    else{
        if (chave > raiz->chave){
            raiz->direita = inserirNode(raiz->direita, chave);
            if ((altura(raiz->direita) - altura(raiz->esquerda)) == 2){
                if (chave > raiz->direita->chave){
                    raiz = rotacionaEsquerda(raiz);
                }
                else{
                    raiz = rotacionaDireitaEsquerda(raiz);
                }
            }
        }
    }
    raiz->h = max(altura(raiz->esquerda), altura(raiz->direita)) + 1;
    return raiz;
}

Pont contem(Pont raiz, TIPOCHAVE chave){
    if (raiz == NULL) return (NULL);
    if (raiz->chave == chave) return (raiz);
    if (raiz->chave > chave) return (contem(raiz->esquerda, chave));
    return (contem(raiz->direita, chave));
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

int contadorNodes(Pont raiz){
    if (!raiz) return 0;
    return (contadorNodes(raiz->esquerda) + 1 + contadorNodes(raiz->direita));
}

int main(int argc, char const *argv[]){
    srand(time(NULL));
    Pont raiz = inicializar();
    int tamanhoArvore, rangeRand, cont, chave;
    tamanhoArvore = rangeRand = 40;
    
    cont = 0;
    while (cont < (tamanhoArvore)){
        chave = rand() % rangeRand;
        if (contem(raiz, chave) == NULL){
            raiz = inserirNode(raiz, chave);
            cont++;
        }
    }
    
    exibirArvore(raiz);
    printf("%d\n", contadorNodes(raiz));
    printf("%p\n", contem(raiz, 35));

    return 0;
}
