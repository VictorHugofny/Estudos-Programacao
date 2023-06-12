#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n, i;
  int *vetor;

  // lê o tamanho do vetor do usuário
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  // aloca memória dinamicamente para o vetor
  vetor = (int*) malloc(n * sizeof(int));

  // inicializa a semente do gerador de números aleatórios
  srand(time(NULL));

  // preenche o vetor com valores aleatórios entre 1 e 100
  for (i = 0; i < n; i++) {
    vetor[i] = rand() % 100 + 1;
  }

  // imprime o vetor
  printf("Vetor gerado: ");
  for (i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  // libera a memória alocada
  free(vetor);

  return 0;
}
