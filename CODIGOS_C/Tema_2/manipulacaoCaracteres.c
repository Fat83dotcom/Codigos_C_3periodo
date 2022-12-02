#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>


int main(int argc, char const *argv[]){
    char caracter;

    do{
        printf("Digite um caractere: ");
        scanf("%c", &caracter);
        isupper(caracter) != 0 ? printf("Maiusculo\n") : printf("Minusculo\n");
        isalpha(caracter) != 0 ? printf("É Alfabetico\n") : printf("Não é Alfabetico\n");
        isdigit(caracter) != 0 ? printf("É digito\n") : printf("Não é digito\n");
        isascii(caracter) != 0 ? printf("É ASCII\n") : printf("Não é ASCII\n");

        __fpurge(stdin);
        
    } while (1);
    
    return 0;
}
