#include <stdio.h>
//alocação dinamica
//sizeof, malloc, calloc

//FIFO -> FILA
//LIFO -> PILHA -> ULTIMO A ENTRAR É O PRIMEIRO SAIR

//estrutura da pilha
typedef struct {
  int valor;
  struct Elemento *proximo;
} Elemento;

//estrutura do topo
typedef struct {
  Elemento *topo;
} Controle;

//push
void empilhar(Controle *p, int val) {
  Elemento *no = malloc(sizeof(Elemento));
  no->valor = val;
  no->proximo = p->topo;
  p->topo = no;
}

//pop
void desempilhar(Controle *p, Elemento *e){
    p->topo = e->proximo;
    e->proximo = NULL;
    printf("%d foi desempilhado \n", e->valor);
}
void imprimir(Elemento *e) {
  if (e) {
    printf("%d \n", e->valor);
    // função recursiva
    imprimir(e->proximo);
  } else {
    printf("Pilha vazia");
  }
}

int main() {
  Controle p;
  p.topo = NULL;

  empilhar(&p, 32);
  
  empilhar(&p, 12);
  empilhar(&p, 52);
  desempilhar(&p, p.topo);
  printf("abaixo dados imprimidos \n");
  imprimir(p.topo);
} 