#include <stdio.h>


int main(int argc, char const *argv[]){
    
    int numero = 98399, *p = &numero;
    float pi = 3.1415;
    printf("%X\n", numero); // Impreme um número inteiro em hexadecimal
    printf("%p\n", p); // Imprime o endereço para onde o ponteiro p aponta
    printf("%i\n", *p); //Imprime o conteudo do endereço apontado por p
    printf("%p\n", &p); // IMprime o endereço do ponteiro na memoria
    printf("%.3e\n", pi); // Imprime um numero em notação cientifica com 3 casas decimais
    printf("%0.3f\n", pi); // Imprime um numero de ponto flutuante com 3 casas decimais
    // printf("%-5D\n", pi); não deu certo
    return 0;
}
