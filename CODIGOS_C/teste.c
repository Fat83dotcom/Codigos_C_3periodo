#include <stdio.h>

int main(int argc, char const *argv[]) {
    // int numero, numero1, numero2, soma, *pnumero;
    // pnumero = &numero;
    // soma = sizeof(numero) + sizeof(numero1) + sizeof(numero2);
    // printf("Digite um numero: ");
    // scanf("%d", &numero);
    // printf("O numero vezes 5 é %d\n", numero * 5);
    // printf("Endereço apontado por pnumero(valor): %p\n", pnumero);
    // printf("Conteudo da variavel numero(hexadecimal): %p\n", *pnumero);
    // printf("Endereço do ponteiro pnumero: %p\n", &pnumero);
    // printf("Endereços : numero: %p, numero1: %p, numero2: %p\n", &numero, &numero1, &numero2);
    // printf("%d\n", sizeof(numero));
    // printf("%d bytes é o tamanho total da memoria alocada\n", soma);

    int x, y, *p;y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;
    printf("x = %d\ny = %d\np = %d\n", x, y, *p);
    return 0;
}
