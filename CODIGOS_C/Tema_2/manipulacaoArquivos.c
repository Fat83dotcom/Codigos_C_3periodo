#include <stdio.h>
#include <stdio_ext.h>


int main(int argc, char const *argv[]){
    
    FILE *arquivo1, *arquivo2;
    int letra;

    arquivo1 = fopen("manipulation.txt", "a+");
    arquivo2 = fopen("manipulation2.txt", "a+");

    if (arquivo1 == NULL){
        printf("O arquivo1 não pode ser aberto.");
        return 0;
    }
    else{
        printf("deu certo\n");
        fputc("d", arquivo1);
        // printf("%c", stdin);
        while ((letra = fgetc(arquivo1)) != EOF){
            putchar(letra);
        }
        
        fclose(arquivo1);
        return 1;
    }
    
    
    return 0;
}
