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

void imprimirSegundaForma(Elemento *e) {

  while (e != NULL) {
    printf("%d \n", e->valor);
    e = e->proximo;
  }

  printf("\n Pilha vazia \n");
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
int pilhaVazia(Elemento *e) {
  if (!e) {
    printf("Erro: Pilha está vazia\n");
    return 1;
  } else if (!e->valor) {
    printf("Aviso: Pilha não está vazia, mas o elemento no topo é NULL\n");
    return 0;
  } else {
    printf("O valor do topo é %d\n", e->valor);
    return 0;
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
  p.topo = NULL;

  int escolha = 0;
  int valor = 0;
  int valorEscolhido = 0;

  while (escolha != 8) {
    printf("\n\n -----------------------");

    printf("\n 1 - Empilhar");
    printf("\n 2 - Desempilhar");
    printf("\n 3 - Imprimir");
    printf("\n 4 - verificar valor");
    printf("\n 5 - imprimir pilha inversa ");
    printf("\n 6 - imprimir com while");
    printf("\n 7 - verificar se pilha vazia");
    printf("\n\n Escolha uma opcao: ");
    scanf("%d", &escolha);

    system("cls || clear");

    if (escolha == 1) {
      printf("Digite o valor que deseja empilhar?");
      scanf("%d", &valor);
      empilhar(&p, valor);
    } else if (escolha == 2) {
      //&p é a estrutura da pilha que contem dados sobre o topo
      // p.topo é o ultimo elemento adicionado = Elemento e
      printf("valor desempilhado foi %d \n", desempilhar(&p, p.topo)->valor);
    } else if (escolha == 3) {
      imprimir(p.topo);
    } else if (escolha == 4) {
      printf("Digite o valor que deseja buscar na pilha?");
      scanf("%d", &valorEscolhido);
      verificarValor(p.topo, valorEscolhido);
    } else if (escolha == 5) {
      inverterPilha(&p);
    } else if (escolha == 6) {
      imprimirSegundaForma(p.topo);
    } else if (escolha == 7) {
      pilhaVazia(p.topo);
    }
  }
}