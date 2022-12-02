#include <stdio.h>

int main(int argc, char const *argv[]){
    
    int numero, *pnumero;
    pnumero = &numero;
    numero = 20;
    printf("Conteudo da variavel numero apontado pelo ponteiro: %d\n", *pnumero);
    printf("Endereço da variavel numero: %X\n", &numero);
    printf("Endereço armazenado por pnumero: %X\n", pnumero);
    printf("Endereço de pnumero: %X\n", &pnumero);
    return 0;
}
