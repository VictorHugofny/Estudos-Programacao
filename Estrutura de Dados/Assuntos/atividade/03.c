/* Questão 3. Crie um programa que contenha um vetor de inteiros contendo 5 elementos.
Utilizando apenas aritmetica de ponteiros, leia esse vetor do teclado e imprima o dobro de cada
valor lido.
 */

#include <stdio.h>

#define false 0
#define true 1

int dubleValue(int *value) {
  return *(value)*2;
}

void output(int *vetor) {
  for (int i = 0; i < 5; i++)
    printf("%d\n", dubleValue(&vetor[i]));
}

void input(int *vetor) {
  for (int i = 0; i < 5; i++) {
    printf("\nInforme o valor %i: ", i + 1);
    scanf("%i", &vetor[i]);
  }
}

int main() {

  int vetor[5] = {};
  input(vetor);
  output(vetor);

  return false;
}
