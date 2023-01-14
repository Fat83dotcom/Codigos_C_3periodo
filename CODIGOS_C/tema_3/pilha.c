#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 10
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct Registro{
    TIPOCHAVE chave;
    char nome[30];
}Registro;

typedef struct Pilha{
    Registro A[MAXIMO];
    int topo;
}Pilha;

void inicializacao(Pilha *pilha){
    pilha->topo = -1;
}

int tamanhoPilha(Pilha *pilha){
    return pilha->topo + 1;
}

void exibirPilha(Pilha *pilha){
    int i;
    printf("Pilha:\n");
    for (i = pilha->topo; i >= 0; i--){
        printf("%d", pilha->A[i].chave);
        printf("%s", pilha->A[i].nome);
    }
}

bool push(Pilha *pilha, Registro reg){
    if (pilha->topo >= MAXIMO - 1){
        return false;
    }
    pilha->topo += 1;
    pilha->A[pilha->topo] = reg;
    return true;
}

bool pop(Pilha *pilha, Registro *reg){
    if (pilha->topo == -1){
        return false;
    }
    *reg = pilha->A[pilha->topo];
    pilha->topo -= 1;
    return true;   
}

void reinicializacao(Pilha *pilha){
    inicializacao(pilha);
}

void inserirDadosPilha(Pilha *pilha, Registro *reg){
    do {
        int flag;
        printf("Digite o identificador único: ");
        scanf("%d", &reg->chave);
        printf("Digite o nome: ");
        __fpurge(stdin);
        fgets(reg->nome, 30, stdin);
        (push(pilha, *reg) == 1) ? printf("Registrado com Sucesso.\n") : printf("Pilha Cheia.\n");
        printf("Deseja inserir outro registro?(1: sim / 0: não) ");
        scanf("%d", &flag);
        if (flag == 0) break;
    } while (1);
}

int main(int argc, char const *argv[]){
    Pilha p, *pP = &p;
    Registro reg, *pReg = &reg;

    inserirDadosPilha(pP, pReg);
    
    return 0;
}
