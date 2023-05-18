#include <stdio.h>
#include <stdlib.h>

//desafios
//✅ 1: Implementar uma função para verificar se um determinado valor está presente na fila.
//✅ 2: Adicionar uma função para obter o tamanho atual da fila.
//✅ 3: Modificar a função de remoção para retornar o valor removido em vez de apenas imprimi-lo.
//4: Implementar uma função para inverter a ordem dos elementos na fila.
//5: Adicionar validação para evitar a inserção de valores duplicados na fila.
//6: Implementar uma função para esvaziar completamente a fila.
//7: Adicionar suporte para operações de fila circular, em que a inserção após o fim da fila resulta em uma nova inserção no início.
//8: Modificar a função de impressão para exibir a posição de cada elemento na fila.
//9: Implementar uma função para mesclar duas filas em uma única fila resultante.
//10: Adicionar uma função para ordenar os elementos da fila em ordem crescente ou decrescente.

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
        valorRemovido = removerElemento(fila1);
        inserir(fila2, valorRemovido);
    }

    printf ("\n Toda pilha foi copiada \n");
    imprimir(fila2);
}

//Implementar uma função para verificar se um determinado valor está presente na fila
//sem remover elementos da fila
int verificarValor(Fila *fila, int valor){
    Elemento *atual = fila->inicio;

    if (!atual) {
        printf("Fila vazia \n");
        return;
    }

    //função recursiva para olhar todos elementos da fila sem remover
    while (atual) {
        atual = atual->proximo;
        if(atual && atual->valor && atual->valor == valor){
            return 1;
        }
    }

    //não encontrou valor
    return 0;
}

//removendo elementos da fila;
int verificarValor2(Fila *fila, int valor){
    int valorAtual = 0;

    while(!filaVazia(fila->inicio)){
        valorAtual = removerElemento(fila);
        //encontrou o valor repetido;
        if(valorAtual == valor){
            return 1;
        }
    }

    //não encontrou valor
    return 0;
}

//Adicionar uma função para obter o tamanho atual da fila.
int tamanhoFila(Fila *fila){
    Elemento *no = fila->inicio;
    int tamanho = 0;

    if (!no) {
        printf("Fila vazia \n");
        return;
    }

    while (no) {
        no = no->proximo;
        tamanho++;
    }

    //retornando o tamanho
    return tamanho;
}

//Crie uma função que insira elementos no inicio da lista.
void insirirInicio(Fila *fila, int valor){
    Elemento* no = (Elemento*)malloc(sizeof(Elemento));

    if (!no) {
        printf("Erro ao alocar memória\n");
        return;
    }

    no->valor = valor;

    if(fila->inicio){
        no->proximo = fila->inicio;
    }else{
        no->proximo = NULL;
        fila->fim = no;
    }

    fila->inicio = no;
}

void main(){
    // Fila fila;
    // criarFila(&fila);
    Fila *fila1 = criarFila();
    Fila *fila2 = criarFila();
    int escolha = 0;
    int valor = 0;
    int valorEscolhido = 0;
    int escolhaFila = 0;
    
    while (escolha != 9) {
    printf("----------------------- \n");
    printf("\n 1 - Inserir Elemento");
    printf("\n 2 - Remover elemento");
    printf("\n 3 - Imprimir toda a fila");
    printf("\n 4 - Copiar todos elementos da primeira fila para a segunda");
    printf("\n 5 - Verificar se existe um valor na fila");
    printf("\n 6 - Verificar o tamanho da fila");
    printf("\n 7 - Insirir elemento no inicio (Fila)");
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
        scanf("%d", &valorEscolhido);
        if(verificarValor(fila1, valorEscolhido)){
            printf("\nO Valor %d foi encontrado dentro da Fila \n", valorEscolhido);
        }else{
            printf("\nA fila nao possui esse valor \n");
        }
    }

    else if(escolha == 6){
        printf("O tamanho da fila eh %d \n", tamanhoFila(fila1));
    }
    else if(escolha == 7){
        printf("Digite o valor que deseja entrar na fila ?");
        scanf("%d", &valor);
        insirirInicio(fila1, valor);
    }
  }
}
