#include <stdio.h>

void incrementar(int *ponteiro) {
  (*ponteiro)++; // incrementa o valor apontado pelo ponteiro
}

int main() {
  int x = 10;
  printf("Valor de x antes da função: %d\n", x);

  incrementar(&x); // passando o endereço de x como argumento

  printf("Valor de x depois da função: %d\n", x);

  return 0;
}


//para criar um ponteiro é necessario int *p = &variavel
// *p acesso o valor do ponteiro
// p acesso o endereço do ponteiro