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

void inserir(Fila* fila, int val) {
    Elemento* no = (Elemento*)malloc(sizeof(Elemento));

    if (!no) {
        printf("Erro ao alocar memória\n");
        return;
    }

    no->valor = val;
    no->proximo = NULL;

    if (!fila->inicio) {
        fila->inicio = no;
    } else {
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
int *removerElemento(Fila *fila) {
  int aux = 0;
  if(filaVazia(fila->inicio)){
      printf("Fila vazia (Nao eh possivel remover elementos) \n");
      return;
  }

  printf("Valor removido da fila: %d \n", fila->inicio->valor);
  aux = fila->inicio->valor;
  fila->inicio = fila->inicio->proximo;

  return aux;
}

Fila* criarFila(){
    Fila *fila = (Fila*)malloc(sizeof(fila));
    fila->fim = NULL;
    fila->inicio = NULL;
    printf("Pilha criada \n");
    return fila;
}

void copiarFila(Fila *fila1, Fila *fila2){
    int valorRemovido = 0;
    
    while(!filaVazia(fila1->inicio)){
        printf("rodou?");
        valorRemovido = removerElemento(fila1);
        inserir(fila2, valorRemovido);
    }

    printf ("Toda pilha foi copiada \n");
    imprimir(fila2);
}


//Implementar uma função para verificar se um determinado valor está presente na fila.
int verificarValor(Fila *fila, valor){
    int valorAtual = 0;

    while(!filaVazia(fila->inicio)){
        valorAtual = removerElemento(filaVazia);
        
        //encontrou o valor repetido;
        if(valorAtual == valor){
            return 1;
        }
    }

    //não encontrou valor
    return 0;
}

void main(){
    // Fila fila;
    // criarFila(&fila);
    Fila *fila1 = criarFila();
    Fila *fila2 = criarFila();
    int escolha = 0;
    int valor = 0;
    int escolhaFila = 0;
    
    while (escolha != 9) {
    printf("----------------------- \n");
    printf("\n 1 - Inserir Elemento");
    printf("\n 2 - Remover elemento");
    printf("\n 3 - Imprimir toda a fila");
    printf("\n 4 - Copiar todos elementos da primeira fila para a segunda");
    printf("\n 5 - Verificar se existe um valor na fila");
    printf("\n 9 - Finalizar");
    printf("\n\nEscolha uma opcao: ");
    scanf("%d", &escolha);

    system("cls || clear");

    if(escolha == 1 || escolha == 2){
        printf("\nDeseja inserir na primeira ou segunda fila? ");
        printf("\n1: primeira fila");
        printf("\n2: segunda fila");
        printf("\n\nEscolha uma opcao: ");
        scanf("%d", &escolhaFila);

        system("cls || clear");
        if (escolha == 1) {
            printf("Digite o valor que deseja entrar na fila ? ");
            scanf("%d", &valor);
            if(escolhaFila == 1){
                inserir(fila1, valor);
            }else{
                inserir(fila2, valor);
            }
            
        } else if (escolha == 2) {
            if(escolhaFila == 1){
                removerElemento(fila1);
            }else{
                removerElemento(fila2);
            }
        }
    }  

    if (escolha == 3) {
      printf("----Primeira fila--- \n");
      imprimir(fila1);
      printf("----Segunda fila--- \n");
      imprimir(fila2);
    }

    else if(escolha == 4){
        copiarFila(fila1, fila2);
    }

    else if(escolha == 5){
        printf("Digite o valor que deseja procurar na fila: ");
        scanf("%d", &valor);
        if(verificarValor(fila1, valor)){
            printf("O Valor %d foi encontrado dentro da Fila \n", valor);
        }else{
            printf("A fila não possui esse valor \n")
        }
    }
  }
}