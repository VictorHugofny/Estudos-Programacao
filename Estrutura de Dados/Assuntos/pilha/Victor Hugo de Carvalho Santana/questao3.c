//crie uma pilha com menu para as opções de Empilhar, Desempilhar, e imprimir.
// Implemente a função "primeiro" que exibi o 1 elemento inserido na pilha
#include <stdio.h>

// estrutura da pilha
typedef struct {
  int valor;
  struct Elemento *proximo;
} Elemento;

// estrutura do topo
typedef struct {
  Elemento *topo;
} Controle;

// push
void empilhar(Controle *p, int val) {
  Elemento *no = (Elemento *)malloc(sizeof(Elemento));
  no->valor = val;
  no->proximo = p->topo;
  p->topo = no;
}

Elemento *desempilhar(Controle *p, Elemento *e) {
  if (e) {
    p->topo = e->proximo;
    e->proximo = NULL;
    return e;
  } else {
    return p;
  }
}

void imprimir(Elemento *e) {

  if (e) {
    printf("%d \n", e->valor);
    // função recursiva
    imprimir(e->proximo);
  } else {
    printf("\n Pilha vazia \n");
  }
}


void restaUm(Controle *p) {
    Elemento *noAtual = p->topo;
    if(noAtual->proximo != NULL){
        desempilhar(p, noAtual);
        restaUm(p);
        Elemento *noProx = p->topo;
        noAtual->valor = noProx->valor;
    } else {
        printf("\n Parou de desempilhar o valor atual e %d", noAtual->valor);
    }
}


void compararPilhas(Controle *p, Controle *p2){
    int validacao = 0;

    while (p->topo) {
      Elemento *e = desempilhar(p, p->topo);
      Elemento *e2 = desempilhar(p2, p2->topo);
      
      if(e->valor != e2->valor){
        validacao = 1;
      }
    }

    if(validacao == 1){
      printf("Pilhas diferentes");
    }else{
      printf("pilhas iguais");
    }
}

void main() {
  Controle p;
  p.topo = NULL;

  empilhar(&p, 1);
  empilhar(&p, 3);
  empilhar(&p, 3);

  Controle p2;
  p2.topo = NULL;
  
  empilhar(&p2, 1);
  empilhar(&p2, 2);
  empilhar(&p2, 3);

  int escolha = 0;
  int valor = 0;

  while (escolha != 5) {
    printf("\n\n -----------------------");

    printf("\n 1 - comparar pilhas");
    printf("\n\n Escolha uma opcao: ");
    scanf("%d", &escolha);

    system("cls || clear");

    switch (escolha) {
        case 1:
            compararPilhas(&p, &p2);
            break;
        
        case 2:
            imprimir(p.topo);
            break;
        
        default:
            printf("finalizado\n");
            break;
    }
  }
}