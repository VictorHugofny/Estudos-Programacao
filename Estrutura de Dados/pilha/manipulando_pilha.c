// a parte do codigo da pilha dinamica apresentando implemente uma função
// denominada "SEGUNDO" que ao ser CHAMADA imprime o segundo elemento
// to que foi inserido na pilha, caso exista

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

void inverterPilha(Controle *p) {
  // criar nova pilha auxiliar
  Controle aux;
  aux.topo = NULL;

  // copiar elementos da pilha original para a pilha auxiliar
  while (p->topo) {
    Elemento *e = desempilhar(p, p->topo);
    // empilhar elemento na pilha auxiliar
    empilhar(&aux, e->valor);
    free(e);
  }

  // imprimir os elementos da pilha auxiliar
  printf("\nElementos da pilha na ordem inversa:\n");
  imprimir(aux.topo);
}

// verificar se a pilha esta vazia
void pilhaVazia(Elemento *e) {
  if (!e) {
    printf("Pilha esta vazia \n");
  } else {
    printf("O valor do topo é %d\n", e->valor);
  }
}

void verificarValor(Elemento *e, int valor) {
  if (e && e->valor == valor) {
    printf("Valor existe na pilha");
  } else if (e) {
    verificarValor(e->proximo, valor);
  } else {
    printf("Não encontrou o valor");
  }
}

int main() {
  Controle p;
  Controle pCopia;
  int teste = 0;
  p.topo = NULL;
  pCopia.topo = NULL;

  int escolha = 0;
  int valor = 0;
  int valorEscolhido = 0;

  while (escolha != 6) {
    printf("\n\n -----------------------");

    printf("\n 1 - Empilhar");
    printf("\n 2 - Desempilhar");
    printf("\n 3 - Imprimir");
    printf("\n 4 - verificar valor");
    printf("\n 5 - imprimir pilha inversa ");
    printf("\n\n Escolha uma opcao: ");
    scanf("%d", &escolha);

    system("cls || clear");

    if (escolha == 1) {
      printf("Digite o valor que deseja empilhar?");
      scanf("%d", &valor);
      empilhar(&p, valor);
    } else if (escolha == 2) {
      printf("valor desempilhado foi %d \n", desempilhar(&p, p.topo)->valor);
    } else if (escolha == 3) {
      imprimir(p.topo);
    } else if (escolha == 4) {
      printf("Digite o valor que deseja buscar na pilha?");
      scanf("%d", &valorEscolhido);
      verificarValor(p.topo, valorEscolhido);
    } else if (escolha == 5) {
      inverterPilha(&p);
    }
  }
}