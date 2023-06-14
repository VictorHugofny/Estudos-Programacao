#include <stdio.h>

//estrutura da pilha
typedef struct {
  int valor;
  struct Elemento *proximo;
} Elemento;

//estrutura do topo
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

int desempilhar3(Controle *p) {
  if (p->topo == NULL) {
    printf("Pilha vazia\n");
    return -1;
  }

  Elemento *no = p->topo;
  int valor = no->valor;
  p->topo = no->proximo;
  no->proximo = NULL;  // Atribuir NULL ao campo proximo
  free(no);

  return valor;
}



Elemento *desempilhar2(Controle *p) {
  Elemento *no = p->topo;

  if (no) {
    p->topo = no->proximo;
    no->proximo = NULL;
    return no;
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

void restaUm(Controle *p) {
  
    Elemento *noProx = p->topo;
    if(noProx->proximo){
        desempilhar(p, p->topo);
        restaUm(p);
    }else{
        p->topo = noProx;
        printf("\n Parou de desempilhar o valor atual e %d", noProx->valor);
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

  //imprimir os elementos da pilha auxiliar
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

void copiarPilha(Controle *p, Controle *copia) {
  Elemento *no = p->topo;
  while (no != NULL) {
    empilhar(copia, no->valor);
    no = no->proximo;
  }
}

Elemento *pegarTopo(Controle *p) { return p->topo; }

void main() {
  Controle p;
  p.topo = NULL;
  
  Controle p2;
  p2.topo = NULL;

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
            printf("valor desempilhado foi %d \n", desempilhar2(&p)->valor);
            break;
        case 3:
            printf("Pilha 1 \n");
            imprimir(p.topo);
            printf("Pilha 2 \n");
            imprimir(p2.topo);
            break;
        
        // case 5:
        //     printf("Digite o valor que deseja desempilhar?");
        //     scanf("%d", &valor);
        //     verificarValor(p.topo, valor, &p);
        //     break;
        
        case 4:
            restaUm(&p);
            break;

        case 7:
            compararPilhas(&p, &p2);
            break;

        case 8:
            copiarPilha(&p, &p2);
            break;
        default:
            printf("finalizado\n");
            break;
    }
  }
}