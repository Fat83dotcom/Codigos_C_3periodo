#include <stdio.h>

static int numero1 = 0; // variavel global, alocação estátcica

void incremental() {
    int numero2 = 0; // variavel local, alocação automatica(stack)
    static int numero3 = 0; // variavel local, alocação estática
    printf("numero1: %d, numero2: %d, numero3: %d \n", numero1, numero2, numero3);
    numero1++; numero2++; numero3++;
}

int main(int argc, char const *argv[]) {

    for (int i = 0; i < 40; i++) {
        incremental();
    }
    
    return 0;
}
/*Saida:
numero1: 0, numero2: 0, numero3: 0 
numero1: 1, numero2: 0, numero3: 1 
numero1: 2, numero2: 0, numero3: 2 
numero1: 3, numero2: 0, numero3: 3 
numero1: 4, numero2: 0, numero3: 4 
numero1: 5, numero2: 0, numero3: 5 
numero1: 6, numero2: 0, numero3: 6 
numero1: 7, numero2: 0, numero3: 7 
numero1: 8, numero2: 0, numero3: 8 
numero1: 9, numero2: 0, numero3: 9 
numero1: 10, numero2: 0, numero3: 10 
numero1: 11, numero2: 0, numero3: 11 
numero1: 12, numero2: 0, numero3: 12 
numero1: 13, numero2: 0, numero3: 13 
numero1: 14, numero2: 0, numero3: 14 
numero1: 15, numero2: 0, numero3: 15 
numero1: 16, numero2: 0, numero3: 16 
numero1: 17, numero2: 0, numero3: 17 
numero1: 18, numero2: 0, numero3: 18 
numero1: 19, numero2: 0, numero3: 19 
numero1: 20, numero2: 0, numero3: 20 
numero1: 21, numero2: 0, numero3: 21 
numero1: 22, numero2: 0, numero3: 22 
numero1: 23, numero2: 0, numero3: 23 
numero1: 24, numero2: 0, numero3: 24 
numero1: 25, numero2: 0, numero3: 25 
numero1: 26, numero2: 0, numero3: 26 
numero1: 27, numero2: 0, numero3: 27 
numero1: 28, numero2: 0, numero3: 28 
numero1: 29, numero2: 0, numero3: 29 
numero1: 30, numero2: 0, numero3: 30 
numero1: 31, numero2: 0, numero3: 31 
numero1: 32, numero2: 0, numero3: 32 
numero1: 33, numero2: 0, numero3: 33 
numero1: 34, numero2: 0, numero3: 34 
numero1: 35, numero2: 0, numero3: 35 
numero1: 36, numero2: 0, numero3: 36 
numero1: 37, numero2: 0, numero3: 37 
numero1: 38, numero2: 0, numero3: 38 
numero1: 39, numero2: 0, numero3: 39
*/