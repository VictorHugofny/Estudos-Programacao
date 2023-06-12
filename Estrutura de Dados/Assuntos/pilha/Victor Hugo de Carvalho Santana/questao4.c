
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


void verificarValor(Elemento *e, int valor, Controle *p) {
  if (e && e->valor == valor) {
    printf("Valor existe na pilha");

    // criar nova pilha auxiliar
    Controle aux;
    aux.topo = NULL;

    //copiar elementos da pilha original para a pilha auxiliar
    while (p->topo) {
        Elemento *e = desempilhar(p, p->topo);
        // empilhar elemento na pilha auxiliar
        empilhar(&aux, e->valor);
        free(e);
    }

    imprimir(aux.topo);
    printf("tudo desempilhado");

  } else if (e) {
    verificarValor(e->proximo, valor, &p);
  } else {
    printf("Não encontrou o valor");
  }
}

void main() {
  Controle p;
  p.topo = NULL;

  int escolha = 0;
  int valor = 0;

  while (escolha != 7) {
    printf("\n\n -----------------------");

    printf("\n 1 - Empilhar");
    printf("\n 2 - Desempilhar");
    printf("\n 3 - Imprimir");
    printf("\n 4 - RestaUm");
    printf("\n 5 - Verificar Valor e remover valor da pilha");
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
        
        case 5:
            printf("Digite o valor que deseja desempilhar?");
            scanf("%d", &valor);
            verificarValor(p.topo, valor, &p);
            break;
        
        default:
            printf("finalizado\n");
            break;
    }
  }
}