#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>


typedef struct {
    char dia[2];
    char mes[2];
    char ano[4];
}Data;

typedef struct {
    char nome[50];
    char sobrenome[50];
    float salario;
    Data dtNasc;
    Data dtContrato;
}Funcionario;

void recebeDados(Funcionario *funcionario, int tamArrayFunc){;
    for (int i = 0; i < tamArrayFunc; i++){
        printf("Digite o nome do funcionario: ");
        __fpurge(stdin);
        fgets(funcionario[i].nome, 50, stdin);
        printf("Digite o sobrenome do funcionario: ");
        __fpurge(stdin);
        fgets(funcionario[i].sobrenome, 50, stdin);
        printf("Digite o salário do funcionario: ");
        __fpurge(stdin);
        scanf("%f", &funcionario[i].salario);
        printf("Digite a data de Nascimento:\n");
        printf("Dia: ");
        __fpurge(stdin);
        fgets(funcionario[i].dtNasc.dia, 2, stdin);
        printf("Mês: ");
        __fpurge(stdin);
        fgets(funcionario[i].dtNasc.mes, 2, stdin);
        printf("Ano: ");
        __fpurge(stdin);
        fgets(funcionario[i].dtNasc.ano, 4, stdin);
        printf("Digite a data do contrato:\n");
        printf("Dia: ");
        __fpurge(stdin);
        fgets(funcionario[i].dtContrato.dia, 2, stdin);
        printf("Mês: ");
        __fpurge(stdin);
        fgets(funcionario[i].dtContrato.mes, 2, stdin);
        printf("Ano: ");
        __fpurge(stdin);
        fgets(funcionario[i].dtContrato.ano, 4, stdin);
        for (int i = 0; i < 50; i++){
            printf("*");
            if (i == 49){
                printf("\n");
            }
        }
    } 
}

void imprimirDados(Funcionario *funcionario){
    int tamArray;
    for (tamArray = 0; *(funcionario + tamArray); tamArray++);
    
    for (int i = 0; i < tamArray; i++){
        printf("%s", funcionario[i].nome);
    }
}

void gravarArquivo(Funcionario funcionario){
    FILE *arquivo;
    arquivo = fopen("arquivo_struct_funcionario.txt", "a+");

}

int main(int argc, char const *argv[]){
    int qtdFuncionarios;
    printf("Quantos funcionarios deseja cadastrar: ");
    scanf("%d", &qtdFuncionarios);
    Funcionario funcionario[qtdFuncionarios];

    recebeDados(funcionario, qtdFuncionarios);
    imprimirDados(funcionario);

    return 0;
}
