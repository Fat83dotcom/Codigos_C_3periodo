#include <stdio.h>
#include <stdlib.h>

void imprimirTaboada(){
    FILE *arquivoLocal;
    char* letraMulti[1], letraIgual[1];
    int numArquivo1, numArquivo2, numArquivo3;
    arquivoLocal = fopen("resultado_taboada.txt", "r");
    fseek(arquivoLocal, 0, SEEK_SET);
    while (fscanf(arquivoLocal, "%d %s %d %s %d\n", \
        &numArquivo1, letraMulti, &numArquivo2, letraIgual, &numArquivo3) != EOF){
        printf("%d %s %d %s %d\n", numArquivo1, letraMulti, numArquivo2, letraIgual, numArquivo3);
    }
    fclose(arquivoLocal);
}

int main(int argc, char const *argv[]){
    
    int *resultadoTaboada, tamanhoTaboada, taboada;
    int opcao;
    
    do {
        printf("Deseja consultar a última taboada realizada? 0(Sim)/1(Não): ");
        scanf("%d", &opcao);
        if (opcao == 0) {
            imprimirTaboada();
        }
        else{
            break;
        }
    } while (1);
    FILE *arquivo;
    printf("Digite qual taboada deseja saber: ");
    scanf("%d", &taboada);
    do{
        printf("Digite o tamanho da taboada: ");
        scanf("%d", &tamanhoTaboada);
        if (tamanhoTaboada < 10){printf("Você digitou %d, o numero deve ser maior ou igual a 10 !!\n", tamanhoTaboada);} 
    } while (tamanhoTaboada < 10);

    tamanhoTaboada = tamanhoTaboada + 1;
    resultadoTaboada = (int*) malloc(tamanhoTaboada * sizeof(int));
    arquivo = fopen("resultado_taboada.txt", "w+");

    for (int i = 0; i < tamanhoTaboada; i++){
        resultadoTaboada[i] = taboada * i;
        fprintf(arquivo, "%d %s %d %s %d\n", taboada, "X", i, "=", resultadoTaboada[i]);
    }
    for (int i = 0; i < tamanhoTaboada; i++){
        printf("%d X %d = %d\n", taboada, i, resultadoTaboada[i]);
    }
    free(resultadoTaboada);
    fclose(arquivo);
    
    return 0;
}
