#include <stdio.h>
#include <stdio_ext.h>


int main(int argc, char const *argv[]){
    FILE *pArquivo, *pArquivoSalvadorLeiuras;
    int caracter;

    if (argc != 2){
        printf("Sintaxe: \n\n%s Arquivo\n\n", argv[0]);
        return 0;
    }

    pArquivo = fopen(argv[1], "r");
    pArquivoSalvadorLeiuras = fopen("salvadorArquivos.txt", "a+");

    if (pArquivo == NULL){
        printf("Não foi possivel abrir o arquivo: %s\n", argv[1]);
        return 1;
    }
    if (pArquivoSalvadorLeiuras == NULL){
        printf("Arquivo salvador nao pode ser aberto.");
        return 1;
    }
    
    while ((caracter = fgetc(pArquivo)) != EOF){
        putchar(caracter);
        fputc(caracter, pArquivoSalvadorLeiuras);

    }
    fclose(pArquivo);
    fclose(pArquivoSalvadorLeiuras);
    
    return 2;
}
