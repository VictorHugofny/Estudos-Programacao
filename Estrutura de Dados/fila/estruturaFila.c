#include <stdio.h>

//estrutura do elemento
typedef struct Elemento{
    int valor;
    struct Elemento *proximo
}Elemento;

//estrutura da fila
typedef struct Fila{
    Elemento *inicio;
    Elemento *fim;
}Fila;

void inserir(Fila *fila, int val) {
  Elemento *no = (Elemento *)malloc(sizeof(Elemento));
  
  no->valor = val;
  no->proximo = NULL;

  if(!fila->inicio){
    fila->inicio = no;
  }else{
    fila->fim->proximo = no;
  }

  fila->fim = no;
}

void imprimir(Fila *fila) {
  Elemento *atual = fila->inicio;

  if (!atual) {
    printf("Fila vazia \n");
    return;
  }

  while (atual) {
    printf("%d \n", atual->valor);
    atual = atual->proximo;
  } 
}

int filaVazia(Elemento *e){
  if(e != NULL){
    return 0;
  }else{
    return 1;
  }
}
//remover elementos da fila
void *removerElemento(Fila *fila) {

  if(filaVazia(fila->inicio)){
      printf("Fila vazia (Nao eh possivel remover elementos) \n");
      return;
  }

  printf("Valor removido da fila: %d \n", fila->inicio->valor);
  fila->inicio = fila->inicio->proximo;
}

Fila* criarFila(){
    Fila *fila = (Fila*)malloc(sizeof(fila));
    fila->fim = NULL;
    fila->inicio = NULL;
    printf("Pilha criada \n");
    return fila;
}

// void criarFila(Fila *fila){
//     fila->fim = NULL;
//     fila->inicio = NULL;
//     printf("Pilha criada \n");
// }

void main(){
    // Fila fila;
    // criarFila(&fila);
    Fila *fi = criarFila();
    int escolha = 0;
    int valor = 0;
    
    while (escolha != 9) {
    printf("----------------------- \n");
    printf("\n 1 - Inserir Elemento");
    printf("\n 2 - Remover elemento");
    printf("\n 3 - Imprimir toda a fila");
    printf("\n 9 - Finalizar");
    printf("\n\nEscolha uma opcao: ");
    scanf("%d", &escolha);

    system("cls || clear");

    if (escolha == 1) {
      printf("Digite o valor que deseja entrar na fila ? ");
      scanf("%d", &valor);
      inserir(fi, valor);
    } else if (escolha == 2) {
      removerElemento(fi);
    } else if (escolha == 3) {
      imprimir(fi);
    } 
  }
}