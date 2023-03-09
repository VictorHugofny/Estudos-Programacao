#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int vet[6] = {1, 2, 3, 4, 5, 6};
  int i = 0;
  int *p;
  p = &vet;

  //*aponta para valor, sem "*" aponta para endereço
  //aritmedica de ponteiros usando ou não &
  for (i = 0; i < 6; i++) {
    printf("valor: %i ", vet[i]);
    printf("endereço de memoria: %i \n", &vet[i]);
  }

  printf("\n");
  printf("Abaixo usando ponteiro \n \n");

  for (i = 0; i < 6; i++) {
    printf("Valor no ponteiro: %i Endereço no ponteiro: %d\n", *p + i, p + i);
  }

  return 0;
}