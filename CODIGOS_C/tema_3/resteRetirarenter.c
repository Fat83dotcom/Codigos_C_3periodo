#include <stdio.h>
#include <string.h>

void eliminarEnter(char *str){
    int tamStr = strlen(str);
    for (int i = 0; i < (tamStr + 1); i++){
        if (str[i] == '\n'){
            str[i] = '\0';
        }
    }
}


int main(int argc, char const *argv[]){
    FILE *a;
    a = fopen("teste.txt", "a");
    char str[10];
    fgets(str, 10, stdin);
    
    eliminarEnter(str);
    fprintf(a, "%s" ,str);
    fprintf(a, "%s" ,str);
    fprintf(a, "%s" ,str);
    printf("%s", str);
    fclose(a);
    return 0;
}
