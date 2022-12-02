#include <stdio.h>
#include <stdio_ext.h>

typedef struct Endereco{
    char logradouro[50];
    char numero[5];
    char bairro[50];
    char cep[9];
    char cidade[50];
    char estado[50];
    char referencia[100];
}ENDERECO;

typedef struct Data{
    char dia[2];
    char mes[3];
    char ano[4];
}DATA;

typedef struct Departamento{
    int id;
    char nomeDepartamento[50];
}DEPARTAMENTO;

typedef struct Funcionario{
    char nome[50];
    char sobrenome[50];
    char funcao[30];
    ENDERECO endereco;
    DEPARTAMENTO departamento;
    DATA nascimento;
};


int main(int argc, char const *argv[]){
    
    return 0;
}
