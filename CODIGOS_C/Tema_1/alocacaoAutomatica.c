#include <stdio.h>

long int fatorial(int numero){
    long int execucao;
    execucao = numero < 2 ? 1 : numero * fatorial(numero - 1); printf("%ld\n", execucao);
    return execucao;
}

int main(int argc, char const *argv[]) {
    
    printf("%ld \n", fatorial(20));

    return 0;
}
