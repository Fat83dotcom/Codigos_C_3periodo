#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    
    unsigned long int *num;
    int qtdQuadrados;

    do{
        printf("Digite um número inteiro para a definir a quantidade de quadrados mostrados: ");
        scanf("%d", &qtdQuadrados);
        if (qtdQuadrados > 46000){
            printf("Digite um número entre 0 e 46000.\n");
        }
    } while (qtdQuadrados > 46000);
    
    
    num = calloc(qtdQuadrados, sizeof(unsigned long int));

    for (int i = 0; i < qtdQuadrados; i++){
        *(num + i) = i * i;
    }
    for (int i = 0; i < qtdQuadrados; i++){
        printf("%ld\n", *(num + i));
    }
    free(num);
    printf("%ld\n", sizeof(num));
    
    
    return 0;
}
