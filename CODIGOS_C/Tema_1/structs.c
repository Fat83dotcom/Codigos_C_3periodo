#include <stdio.h>
#include <stdio_ext.h>


typedef struct Aluno{
    char nome[50];
    char sobrenome[50];
    char ano[10];
    char serie[5];
    float notas[4];
    float media;
}ALUNO;


void preencherFormularioAluno(ALUNO *aluno){
    printf("Digite o nome do aluno: ");
    fgets(aluno->nome, 50, stdin);
    printf("Digite o sobrenome do aluno: ");
    fgets(aluno->sobrenome, 50, stdin);
    printf("Digite o ano do aluno: ");
    fgets(aluno->ano, 10, stdin);
    printf("Digite a serie do aluno: ");
    fgets(aluno->serie, 5, stdin);
    for (int i = 0; i < 4; i++) {
        printf("Digite a %dª nota do aluno %s: ", i + 1, aluno->nome);
        scanf("%f", &aluno->notas[i]);
    }
}


void imprimirAluno(ALUNO aluno){
    float soma;
    printf("Nome: %s\n", aluno.nome);
    printf("Sobrenome: %s\n", aluno.sobrenome);
    printf("Ano: %s\n", aluno.ano);
    printf("Série: %s\n", aluno.serie);
    printf("Notas: %.2f, %.2f, %.2f, %.2f\n", aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.notas[3]);
    for (int i = 0; i < 4; i++){
        soma += aluno.notas[i];
    }
    aluno.media = soma / 4;
    printf("Nota Média: %.2f\n", aluno.media);
}


int main(int argc, char const *argv[]){
    
    struct Aluno aluno, *pAluno = &aluno;
    printf("%ld bytes\n", sizeof(aluno));

    ALUNO arrayAluno[5];

    for (int i = 0; i < 5; i++){
        preencherFormularioAluno(arrayAluno + i);
        __fpurge(stdin);
    }
    for (int i = 0; i < 5; i++){
        imprimirAluno(arrayAluno[i]);
    }
    
    preencherFormularioAluno(pAluno);
    imprimirAluno(aluno);

    return 0;
}
