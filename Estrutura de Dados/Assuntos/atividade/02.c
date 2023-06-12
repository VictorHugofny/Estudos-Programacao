/* Questão 2. Crie um programa que contenha um vetor de float contendo 10 elementos.
Imprima o endereço de cada posição desse vetor. */

#include <stdio.h>

#define false 0
#define true 1

int main() {
  int vetor[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
    printf("%d\n", &vetor[i]);
  return false;
}
