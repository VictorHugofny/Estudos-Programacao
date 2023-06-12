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
    Elemento *fim;
}Lista;


void imprimir(Lista *lista) {
  Elemento *atual = lista->inicio;

  if (!atual) {
    printf("Lista vazia \n");
    return;
  }

  while (atual) {
    printf("%d \n", atual->valor);
    atual = atual->proximo;
  } 
}

int listaVazia(Elemento *e){

  if(e != NULL){
    return 0;
  }else{
    return 1;
  }
}

//remover elementos da lista //FUNÇÃO PADRÃO DE REMOVER ELEMENTO
int removerElementoInicio(Lista *lista) {
  int valorRemovido = 0;

  if(listaVazia(lista->inicio)){
      printf("Lista vazia (Nao eh possivel remover elementos) \n");
      return;
  }

  valorRemovido = lista->inicio->valor;
  lista->inicio = lista->inicio->proximo;

  return valorRemovido;
}

int removeElementoFim(Lista *lista) {
  if (lista->inicio == NULL) {
    printf("A lista está vazia\n");
    return 0;
  }

  Elemento *no = lista->inicio;
  Elemento *previousNode = NULL;

  //percorrer toda a lista até chegar no ultimo elemento
  //guardar o valor anterior ao ultimo
  while (no->proximo != NULL) {
    previousNode = no;
    no = no->proximo;
  }

  if (previousNode != NULL)
    previousNode->proximo = NULL;
  else
    lista->inicio = NULL;
  //o fim se torna o valor anterior ao ultimo
  lista->fim = previousNode;
  free(no); // Liberar a memória do último elemento removido
  return 1;
}

int removerFim2(Lista *lista) {
    if (listaVazia(lista->inicio)) {
        printf("A lista está vazia\n");
        return 0;
    }

    Elemento* elementoAnterior = NULL;
    Elemento* elementoAtual = lista->inicio;

    while (elementoAtual->proximo != NULL) {
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->proximo;
    }

    int valorRemovido = elementoAtual->valor;

    if (elementoAnterior == NULL) {
        // A lista possui apenas um elemento
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        elementoAnterior->proximo = NULL;
        lista->fim = elementoAnterior;
    }

    free(elementoAtual);

    return valorRemovido;
}

Lista* criarLista(){
    Lista *lista = (Lista*)malloc(sizeof(lista));
    lista->fim = NULL;
    lista->inicio = NULL;
    printf("Pilha criada \n");
    return lista;
}

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

//Crie uma função que insira elementos no inicio da lista.
void insirirInicio(Lista *lista, int valor){
    Elemento* no = (Elemento*)malloc(sizeof(Elemento));

    if (!no) {
        printf("Erro ao alocar memória\n");
        return;
    }

    no->valor = valor;
    
    //verificar se existe um inicio e guardar esse como proximo valor;
    if(lista->inicio){
        no->proximo = lista->inicio;  
    }else{
        no->proximo = NULL;
        lista->fim = no;
    }

    lista->inicio = no;
}

//função padrão de inserir
void inserir(Lista* lista, int val) {
    Elemento* no = (Elemento*)malloc(sizeof(Elemento));

    if (!no) {
        printf("Erro ao alocar memória\n");
        return;
    }

    no->valor = val;
    no->proximo = NULL;

    if (!lista->inicio) {
        lista->inicio = no;
    } else {
        lista->fim->proximo = no;
    }

    lista->fim = no;
}

// Elemento* inserirFim2(Elemento *lista, int valor) {
//     Elemento *novoElemento = (Elemento*)malloc(sizeof(Elemento));
//     novoElemento->valor = valor;
//     novoElemento->proximo = NULL;

//     if (lista == NULL) {
//         //Se a fila estiver vazia, o novo elemento se torna o primeiro elemento da fila
//         return novoElemento;
//     } else {
//         lista->proximo = inserirFim2(lista->proximo, valor);
//         return lista;
//     }
// }

void inserirFim(Lista *lista, int valor) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));

    if (!novoElemento) {
        printf("Erro ao alocar memória\n");
        return;
    }

    novoElemento->valor = valor;
    novoElemento->proximo = NULL;

    if (lista->inicio == NULL) {
        // Se a lista estiver vazia, o novo elemento se torna o primeiro e o último elemento da lista
        lista->inicio = novoElemento;
        lista->fim = novoElemento;
    } else {
        // Caso contrário, adiciona o novo elemento no final da lista
        lista->fim->proximo = novoElemento;
        lista->fim = novoElemento;
    }
}

void inserirMeio(Lista *lista, int posicao, int valor) {
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

    if (posicao == tamanhoLista(lista) + 1) {
        // Inserir no fim
        lista->fim = novoElemento;
    }
}

void inserirMeioPorValor(Lista *lista, int valor) {
    if (listaVazia(lista->inicio)) {
        printf("Lista vazia, inserindo no início\n");
        insirirInicio(lista, valor);
        return;
    }

    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->valor = valor;

    Elemento* elementoAnterior = NULL;
    Elemento* elementoAtual = lista->inicio;

    while (elementoAtual != NULL && elementoAtual->valor < valor) {
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->proximo;
    }

    if (elementoAnterior == NULL) {
        // Inserir no início
        novoElemento->proximo = lista->inicio;
        lista->inicio = novoElemento;
    } else {
        novoElemento->proximo = elementoAnterior->proximo;
        elementoAnterior->proximo = novoElemento;
    }

    if (elementoAtual == NULL) {
        // Inserir no fim
        lista->fim = novoElemento;
    }
}

void inserirMeioValor(Lista *lista, int valor) {
    if (listaVazia(lista->inicio)) {
        printf("Lista vazia, inserindo no início\n");
        insirirInicio(lista, valor);
        return;
    }

    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->valor = valor;
    novoElemento->proximo = NULL;

    Elemento* elementoAnterior = NULL;
    Elemento* elementoAtual = lista->inicio;

    // Percorrer a lista até encontrar o local de inserção
    while (elementoAtual && elementoAtual->valor < valor) {
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->proximo;
    }

    if (elementoAnterior == NULL) {
        // Inserir no início da lista
        novoElemento->proximo = lista->inicio;
        lista->inicio = novoElemento;
    } else {
        // Inserir no meio da lista
        novoElemento->proximo = elementoAnterior->proximo;
        elementoAnterior->proximo = novoElemento;
    }
}

// int removeElementFirstGreater(List *list, const int firstGreater) {
//   Node *node = getInitList(list);
//   int currentNodeValue = 0;
//   int count = 0;
//   while (!isEmpty(node)) {
//     if (node->item > firstGreater) {
//       currentNodeValue = node->item;
//       count++;
//       break;
//     };
//     node = node->next;
//     count++;
//   }
//   const bool isRemoved = removeItem(list, count);
//   if (!isRemoved) return 0;
//   return 1;
// }

void inserirAposPrimeiroMaior(Lista *lista, int valor, const int firstGreater) {
    Elemento *novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->valor = valor;
    novoElemento->proximo = NULL;

    if (listaVazia(lista->inicio)) {
        // Inserir no início da lista vazia
        lista->inicio = novoElemento;
        lista->fim = novoElemento;
        return;
    }

    Elemento *noAtual = lista->inicio;

    while (noAtual != NULL) {
        if (noAtual->valor > firstGreater) {
            novoElemento->proximo = noAtual->proximo;
            noAtual->proximo = novoElemento;
            break;
        }
        noAtual = noAtual->proximo;
    }

    if (noAtual == NULL) {
        // Inserir no fim da lista
        lista->fim->proximo = novoElemento;
        lista->fim = novoElemento;
    }
}

int removerMeio(Lista *lista, int valor) {
    if (listaVazia(lista->inicio)) {
        printf("A lista está vazia\n");
        return 0;
    }

    Elemento* elementoAnterior = NULL;
    Elemento* elementoAtual = lista->inicio;

    while (elementoAtual != NULL && elementoAtual->valor != valor) {
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->proximo;
    }

    if (elementoAtual == NULL) {
        printf("O valor não foi encontrado na lista\n");
        return 0;
    }

    if (elementoAnterior == NULL) {
        // Remover no início
        lista->inicio = elementoAtual->proximo;
    } else {
        elementoAnterior->proximo = elementoAtual->proximo;
    }

    if (elementoAtual == lista->fim) {
        // Remover no fim
        lista->fim = elementoAnterior;
    }

    int valorRemovido = elementoAtual->valor;
    free(elementoAtual);

    return valorRemovido;
}

int main() {
    Lista *lista = criarLista();
    int escolha = 0;
    int valor = 0;
    int valorEscolhido = 0;
    //int escolhaLista = 0;
    
    while (escolha != 99) {
        printf("----------------------- \n");
        printf("\n 1 - Inserir elemento no Inicio (Lista)");
        printf("\n 2 - Inserir elemento no Fim (Lista)");
        printf("\n 3 - Remover elemento do Inicio");
        printf("\n 4 - Remover elemento do Fim");
        printf("\n 5 - Remover Um numero especifico");
        printf("\n 6 - Imprimir toda a lista");
        printf("\n 7 - Verificar o tamanho da lista");
        
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
                printf("Valor removido da fila %d: ", removerElementoInicio(lista));
                break;
            }

            case 4: {
                removeElementoFim(lista);
                break;
            }

            case 6: {
                printf("----lista--- \n");
                imprimir(lista);
                break;
            }

            case 7: {
                printf("O tamanho da lista eh %d \n", tamanhoLista(lista));
                break;
            }
        
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    return 0;

}
