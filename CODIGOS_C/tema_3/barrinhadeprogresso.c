#include <stdio.h>

void barraProgressoVisor(int contadorCorrente, int totalContador){
  float qtdPontosBarra = 10;
  // int cursorEixoX = 77;
  float pontoBarra = contadorCorrente / (totalContador / qtdPontosBarra);
  (int) pontoBarra;
  printf("\e[1;1H\e[2J");
  for (int i = 0; i < pontoBarra; i++){
    // display.setCursor((cursorEixoX), 47);
    printf("> ");
    // cursorEixoX += 5;
  }
}

int main(int argc, char const *argv[]){
    
  for (int i = 0; i < 20; i++){
    barraProgressoVisor(i + 1, 20);
  }
  
  return 0;
}
