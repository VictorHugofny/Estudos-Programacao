#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i;
  int *vetor;

  // lê o tamanho do vetor do usuário
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  // aloca memória dinamicamente para o vetor
  vetor = (int*) malloc(n * sizeof(int));

  // lê os valores do usuário e armazena no vetor
  for (i = 0; i < n; i++) {
    printf("Digite o valor para a posição %d: ", i);
    scanf("%d", &vetor[i]);
  }

  // imprime o vetor
  printf("Vetor lido: ");
  for (i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  // libera a memória alocada
  free(vetor);

  return 0;
}
