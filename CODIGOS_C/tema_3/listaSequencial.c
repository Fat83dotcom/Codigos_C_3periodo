#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#define MAXIMO 3
#define PATH_ARQUIVO "dadosSalvos.txt"
typedef int TIPOCHAVE;

typedef struct Registro{
    TIPOCHAVE chave;
    char nome[30];
    char sobreNome[30];
    char idade[3];
}Registro;

typedef struct Lista{
    Registro A[MAXIMO];
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
        printf("Sobrenome: %s\n", lista->A[i].sobreNome);
        printf("Idade: %s\n", lista->A[i].idade);
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

int inserirItemLista(Lista *lista, Registro *reg, int posicaoInsercao){
    if ((posicaoInsercao < 0) || (lista->index == MAXIMO) || (posicaoInsercao > lista->index)) {
        return 0;
    }
    for (int i = lista->index; i > posicaoInsercao; i--){
        lista->A[i] = lista->A[i - 1];
    }
    lista->A[posicaoInsercao] = *reg;
    lista->index++;
    return 1;
}

int inserirFinalLista(Lista *lista, Registro *reg){
    if ((lista->index == MAXIMO)){
        return -1;
    }
    lista->A[lista->index] = *reg;
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
        (inserirFinalLista(lista, reg) == 1) ? printf("Registrado com Sucesso.\n") : printf("Lista Cheia.\n");
        printf("Deseja inserir outro registro?(1: sim / 0: não) ");
        scanf("%d", &flag);
        if (flag == 0) break;
    } while (1);
}

void eliminarEnter(char *str){
    int tamStr = strlen(str);
    for (int i = 0; i < (tamStr + 1); i++){
        if (str[i] == '\n'){
            str[i] = '\0';
        }
    }
}

int gravarDadosArquivo(Lista *lista){
    FILE *arquivo;
    arquivo = fopen(PATH_ARQUIVO, "a");
    if (arquivo == NULL){
        return -1;
    }
    for (int i = 0; i < lista->index; i++){
        eliminarEnter(lista->A[i].nome);
        eliminarEnter(lista->A[i].sobreNome);
        eliminarEnter(lista->A[i].idade);
        fprintf(arquivo, "%d %s %s %s\n",
            lista->A[i].chave, lista->A[i].nome,
            lista->A[i].sobreNome, lista->A[i].idade
        );
    }
    fclose(arquivo);
    return 1;
}

void lerDadosArquivo(){
    FILE *arquivo;
    char id[6], nome[30], sobreNome[30], idade[3];
    arquivo = fopen(PATH_ARQUIVO, "r");
    rewind(arquivo);
    while (fscanf(arquivo, "%s %s %s %s", id, nome, sobreNome, idade) != EOF){
        printf("%s %s %s %s\n", id, nome, sobreNome, idade);
    }
    fclose(arquivo);
}

int main(int argc, char const *argv[]){
    Lista pessoas, *pPessoa = &pessoas;
    Registro rebeceDados, *pRecebeDados = &rebeceDados;
    
    cadastrarDados(pPessoa, pRecebeDados);
    mostrarItens(pPessoa);
    gravarDadosArquivo(pPessoa);
    lerDadosArquivo();
    inicializarLista(pPessoa);
    return 0;
}
