#include <stdio.h>

typedef struct {
  char nome[20];
  int idade;
} Pessoa;

int main() {
  Pessoa p1;
  p1.idade = 30;
  sprintf(p1.nome, "%s", "Hugo");

  printf("Nome: %s\nIdade: %d\n", p1.nome, p1.idade);

  return 0;
}