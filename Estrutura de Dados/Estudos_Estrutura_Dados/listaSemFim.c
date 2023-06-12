#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//estrutura do elemento
typedef struct Elemento{
    int valor;
    struct Elemento *proximo
}Elemento;

//estrutura da lista
typedef struct Lista{
    Elemento *inicio;
}Lista;

//Adicionar uma função para obter o tamanho atual da lista.
int tamanhoLista(Lista *lista){
    Elemento *no = lista->inicio;
    int tamanho = 0;

    if (!no) {
        printf("Lista vazia \n");
        return;
    }

    while (no) {
        no = no->proximo;
        tamanho++;
    }

    //retornando o tamanho
    return tamanho;
}

//inserirElemento no Fim
void inserirFim(Lista *list, int value) {
    Elemento *no = (Elemento *) malloc(sizeof(Elemento));
    no->valor = value;
    no->proximo = NULL;

    if (list->inicio == NULL) {
        list->inicio = no;
    } else {
        Elemento *auxAtual = list->inicio;
        while (auxAtual->proximo != NULL) {
            auxAtual = auxAtual->proximo;
        }
        auxAtual->proximo = no;
    }
}

//com mais logica
// void inserirInicio(Lista *lista, int valor) {
//     Elemento *novoElemento = (Elemento *) malloc(sizeof(Elemento));
//     novoElemento->valor = valor;
//     novoElemento->proximo = NULL;

//     if (lista->inicio == NULL) {
//         lista->inicio = novoElemento;
//     } else {
//         novoElemento->proximo = lista->inicio;
//         lista->inicio = novoElemento;
//     }
// }

void inserirInicio(Lista *lista, int valor) {
    Elemento *novoElemento = (Elemento *) malloc(sizeof(Elemento));
    novoElemento->valor = valor;
    novoElemento->proximo = lista->inicio;;
    lista->inicio = novoElemento;
}

//Crie uma função que insira elementos no inicio da lista.
void insirirInicio(Lista *lista, int valor){
    Elemento* no = (Elemento*)malloc(sizeof(Elemento));
    
    if (!no) {
        printf("Erro ao alocar memória\n");
        return;
    }

    no->valor = valor;
    no->proximo = NULL;

    //verificar se existe um inicio e guardar esse como proximo valor;
    if(lista->inicio){
        no->proximo = lista->inicio;  
    }

    lista->inicio = no;
}

void inserirMeio(Lista *lista, int valor) {
  int tamanho = tamanhoLista(lista);

  if (tamanho == 0) {
    // A lista está vazia, insere no início
    inserirInicio(lista, valor);
    return;
  }

  Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));
  novoElemento->valor = valor;
  novoElemento->proximo = NULL;

  Elemento *elementoAnterior = NULL;
  Elemento *elementoAtual = lista->inicio;
  int meio = tamanho / 2;
  int contador = 0;

  while (elementoAtual && contador < meio) {
    elementoAnterior = elementoAtual;
    elementoAtual = elementoAtual->proximo;
    contador++;
  }

  if (elementoAnterior == NULL) {
    // Inserir no início
    novoElemento->proximo = lista->inicio;
    lista->inicio = novoElemento;
  } else {
    novoElemento->proximo = elementoAtual;
    elementoAnterior->proximo = novoElemento;
  }
}

void inserirMeioPosicao(Lista *lista, int posicao, int valor) {
    if (posicao < 1 || posicao > tamanhoLista(lista) + 1) {
        printf("Posicao invalida\n");
        return;
    }

    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->valor = valor;

    if (posicao == 1) {
        // Inserir no início
        novoElemento->proximo = lista->inicio;
        lista->inicio = novoElemento;
    } 
    //inserir no meio
    else {
        Elemento* elementoAnterior = lista->inicio;
        int contador = 1;

        //valida se chegou na posição correta
        while (contador < posicao - 1) {
            elementoAnterior = elementoAnterior->proximo;
            contador++;
        }

        novoElemento->proximo = elementoAnterior->proximo;
        elementoAnterior->proximo = novoElemento;
    }
}

// Função para inserir depois de um valor específico
void inserirDepoisValor(Lista* lista, int valorAlvo, int valorNovo) {
    Elemento* elementoAtual = lista->inicio;
    while (elementoAtual != NULL) {
        if (elementoAtual->valor == valorAlvo) {
            Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
            novoElemento->valor = valorNovo;
            novoElemento->proximo = elementoAtual->proximo;
            elementoAtual->proximo = novoElemento;
            break;
        }
        elementoAtual = elementoAtual->proximo;
    }
}
//remover elementos da lista 
//FUNÇÃO PADRÃO DE REMOVER ELEMENTO
int removerElementoInicio(Lista *lista) {
  int valorRemovido = 0;

  if(!lista->inicio){
      printf("Lista vazia (Nao eh possivel remover elementos) \n");
      return 0;
  }

  valorRemovido = lista->inicio->valor;
  //o novo inicio se torna o proximo valor (anterior do inicio)
  lista->inicio = lista->inicio->proximo;

  return valorRemovido;
}

//remover valor Par
void removerPar(Lista *lista){
  Elemento *aux = lista->inicio;
  //para liberar memoria
  Elemento *temp;

  if(lista->inicio->valor %2 == 0){
    temp = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    printf("Elemento removido %d \n", temp->valor);
    free(temp);
  }else{
    while (aux && aux->proximo && aux->proximo->valor%2 != 0){
      aux = aux->proximo;
    }

    if (aux && aux->proximo) {
      temp = aux->proximo;
      aux->proximo = aux->proximo->proximo;
      printf("Elemento removido %d \n", temp->valor);
      free(temp);
    }else{
      printf("Nenhum elemento removido");
    }
  }
}

//Aqui está uma função para remover o elemento do fim da lista:
void removerFim(Lista *lista) {
  if (!lista->inicio) {
    printf("Lista vazia\n");
    return;
  }

  Elemento *aux = lista->inicio;
  Elemento *anterior = NULL;

  // Percorrer a lista até o penúltimo elemento
  while (aux->proximo) {
    anterior = aux;
    aux = aux->proximo;
  }

  if (anterior) {
    // Caso exista um elemento anterior ao último, no fim da fila
    anterior->proximo = NULL;
  } else {
    // Caso a lista tenha apenas um elemento
    lista->inicio = NULL;
  }

  printf("Elemento removido: %d", aux->valor);

  // Liberar a memória do elemento removido
  free(aux);
}

void removerMeio(Lista *lista) {
  if (!lista->inicio) {
    printf("Lista vazia\n");
    return;
  }

  int tamanho = tamanhoLista(lista);
  int meio = tamanho / 2;

  if (meio == 0) {
    printf("A lista contém apenas um elemento\n");
    return;
  }

  Elemento *elementoAnterior = NULL;
  Elemento *elementoAtual = lista->inicio;
  int contador = 0;

  while (elementoAtual && contador < meio) {
      elementoAnterior = elementoAtual;
      elementoAtual = elementoAtual->proximo;
      contador++;
  }

  if (elementoAnterior == NULL) {
      // Remover o primeiro elemento
      lista->inicio = elementoAtual->proximo;
  } else {
      elementoAnterior->proximo = elementoAtual->proximo;
  }
  printf("Valor removido %d \n", elementoAtual->valor);
  free(elementoAtual);
}

void removerMeioPosicao(Lista *lista, int posicao) {
    int tamanho = tamanhoLista(lista);

    if (posicao < 1 || posicao > tamanho) {
        printf("Posicao invalida\n");
        return;
    }

    if (posicao == 1) {
        // Remover o primeiro elemento
        Elemento* elementoRemovido = lista->inicio;
        lista->inicio = elementoRemovido->proximo;
        free(elementoRemovido);
    } else {
        Elemento* elementoAnterior = lista->inicio;
        int contador = 1;

        // Percorrer até o elemento anterior ao que será removido
        while (contador < posicao - 1) {
            elementoAnterior = elementoAnterior->proximo;
            contador++;
        }

        Elemento* elementoRemovido = elementoAnterior->proximo;
        elementoAnterior->proximo = elementoRemovido->proximo;
        printf("Valor Removido: %d \n", elementoRemovido->valor);
        free(elementoRemovido);
    }

    printf("Elemento removido da posicao %d\n", posicao);
}

void imprimir(Lista *lista) {
  Elemento *atual = lista->inicio;
  int posicao = 0;
  if (!atual) {
    printf("Lista vazia \n");
    return;
  }

  while (atual) {
    posicao++;
    printf("Posicao %d : Valor %d \n",posicao, atual->valor);
    atual = atual->proximo;
  } 
}

Lista* criarLista(){
    Lista *lista = (Lista*)malloc(sizeof(lista));
    lista->inicio = NULL;
    printf("Pilha criada \n");
    return lista;
}

int main() {
    Lista *lista = criarLista();
    int escolha = 0;
    int valor = 0;
      
    while (escolha != 99) {
      printf("----------------------- \n");
      printf("\n 1 - Inserir elemento no Inicio (Lista)");
      printf("\n 2 - Inserir elemento no Fim (Lista)");
      printf("\n 3 - Imprimir tabela");
      printf("\n 4 - Ver tamanho da tabela");
      printf("\n 5 - Remover elemento do inicio (Lista)");
      printf("\n 6 - Remover elemento do fim (Lista)");
      printf("\n 7 - Remover elemento Par (Lista)");
      printf("\n 8 - Remover elemento do Meio (Tamanho da Lista)");
      printf("\n 9 - inserir meio de acordo com tamanho da fila (Tamanho da Lista)");
      printf("\n 10 - inserir na posição escolhida de acordo com tamanho da fila");
      printf("\n 11 - remover elemento posição escolhida de acordo com tamanho da fila");
      printf("\n 12 - inserir novo elemento depois de um valor especifico");
      
      printf("\n 99 - Finalizar");
      printf("\n\nEscolha uma opcao: ");
      scanf("%d", &escolha);

      system("cls || clear");

      switch (escolha) {

          case 1: {
              printf("Digite o valor que deseja inserir na lista: ");
              scanf("%d", &valor);
              insirirInicio(lista, valor);
              break;
          }

          case 2: {
              printf("Digite o valor que deseja inserir na lista: ");
              scanf("%d", &valor);
              inserirFim(lista, valor);
              break;
          }

          case 3: {
              printf("Imprimir Lista: \n");
              imprimir(lista);
              break;
          }

          case 4: {
              printf("Tamanho da lista: %d \n", tamanhoLista(lista));
              break;
          }

          case 5: {
              printf("Elemento Removido: %d \n", removerElementoInicio(lista));
              break;
          }

          case 6: {
              removerFim(lista);
              break;
          }

          case 7: {
              removerPar(lista);
              break;
          }

          case 8: {
              removerMeio(lista);
              break;
          }

          case 9: {
              printf("Digite o valor que deseja inserir na lista: ");
              scanf("%d", &valor);
              inserirMeio(lista, valor);
              break;
          }

          case 10: {
              int posicao = 0;
              printf("Digite o valor que deseja inserir na lista: ");
              scanf("%d", &valor);
              printf("Digite a posicao que deseja inserir: ");
              scanf("%d", &posicao);
              inserirMeioPosicao(lista, posicao, valor);
              break;
          }

          case 11: {
              int posicao = 0;
              printf("Digite a posicao que deseja remover: ");
              scanf("%d", &posicao);
              removerMeioPosicao(lista, posicao);
              break;
          }

          case 12: {
              int valorBuscado = 0;
              printf("Digite o valor que deseja inserir apos: ");
              scanf("%d", &valorBuscado);
              printf("Digite o novo valor: ");
              scanf("%d", &valor);
              inserirDepoisValor(lista, valorBuscado, valor);
              break;
          }
      
          default:
              printf("Opcao invalida!\n");
              break;
      }
    }

    return 0;

}