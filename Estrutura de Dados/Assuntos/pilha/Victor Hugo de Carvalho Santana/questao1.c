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
    printf("Não a valor para desempilhar \n");
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


void restaUm(Controle *p, Elemento *e) {
    
  if (e->proximo) {
    desempilhar(&p, p->topo);
    printf("Desempilhou %d", e->valor);
  } else{
    printf("Parou de desempilhar o valor atual é %d", e->valor);
  }
}




void main() {
  Controle p;
  p.topo = NULL;

  int escolha = 0;
  int valor = 0;

  while (escolha != 5) {
    printf("\n\n -----------------------");

    printf("\n 1 - Empilhar");
    printf("\n 2 - Desempilhar");
    printf("\n 3 - Imprimir");
    printf("\n 5 - Finalizar");
    printf("\n\n Escolha uma opcao: ");
    scanf("%d", &escolha);

    system("cls || clear");

    switch (escolha) {
        case 1:
            printf("Digite o valor que deseja empilhar?");
            scanf("%d", &valor);
            empilhar(&p, valor);
            break;
        case 2:
            printf("valor desempilhado foi %d \n", desempilhar(&p, p.topo)->valor);
            break;
        case 3:
            imprimir(p.topo);
            break;
        
        default:
            printf("finalizado\n");
            break;
    }
  }
}