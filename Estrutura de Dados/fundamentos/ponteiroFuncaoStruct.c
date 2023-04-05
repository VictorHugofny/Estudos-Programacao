#include <stdio.h>

// definindo a struct
typedef struct {
  int codigo;
  char nome[50];
} Produto;

// função que recebe um ponteiro para Produto e preenche seus campos
void preencheProduto(Produto *p, int codigo, char *nome) {
  p->codigo = codigo;
  strcpy(p->nome, nome);
}

// função que recebe um ponteiro para Produto e imprime seus campos
void imprimeProduto(Produto *p) {
  printf("Codigo: %d\nNome: %s\n", p->codigo, p->nome);
}

int main() {
  // declarando uma variável do tipo Produto
  Produto p1;
  
  // preenchendo a variável p1 utilizando a função preencheProduto
  preencheProduto(&p1, 1, "Produto 1");
  
  // imprimindo a variável p1 utilizando a função imprimeProduto
  imprimeProduto(&p1);
  
  return 0;
}