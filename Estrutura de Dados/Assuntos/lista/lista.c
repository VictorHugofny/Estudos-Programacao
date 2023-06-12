#include <stdio.h>
#include <stdlib.h>

//desafios
//✅ 1: Implementar uma função para verificar se um determinado valor está presente na lista.
//✅ 2: Adicionar uma função para obter o tamanho atual da lista.
//✅ 3: Modificar a função de remoção para retornar o valor removido em vez de apenas imprimi-lo.
//4: Implementar uma função para inverter a ordem dos elementos na lista.
//5: Adicionar validação para evitar a inserção de valores duplicados na lista.
//6: Implementar uma função para esvaziar completamente a lista.
//7: Adicionar suporte para operações de lista circular, em que a inserção após o fim da lista resulta em uma nova inserção no início.
//8: Modificar a função de impressão para exibir a posição de cada elemento na lista.
//9: Implementar uma função para mesclar duas listas em uma única lista resultante.
//10: Adicionar uma função para ordenar os elementos da lista em ordem crescente ou decrescente.

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
//remover elementos da lista
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

Elemento* removerElementoFim(Elemento *fila) {
    if (fila && fila->proximo) {

        if(fila->proximo->proximo == NULL){
            printf("Valor removido: %d", fila->proximo->valor);
            fila->proximo = NULL;
            return fila;       
        }

        else{
            removerElementoFim(fila->proximo);
        }
        
    } else {
        removerElementoFim(fila->proximo);
    }
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

    if(lista->inicio){
        no->proximo = lista->inicio;  
    }else{
        no->proximo = NULL;
        lista->fim = no;
    }

    lista->inicio = no;
}


Elemento* inserirFim(Elemento *fila, int valor) {
    Elemento *novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->valor = valor;
    novoElemento->proximo = NULL;

    if (fila == NULL) {
        //Se a fila estiver vazia, o novo elemento se torna o primeiro elemento da fila
        return novoElemento;
    } else {
        fila->proximo = inserirFim(fila->proximo, valor);
        return fila;
    }
}

int listaVazia(Elemento *e){
  if(e != NULL){
    return 0;
  }else{
    return 1;
  }
}

// Node *getInitList(List *list) { return list->init; }

// Node *getEndList(List *list) { return list->end; }

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
                lista = inserirFim(lista, valor);
                break;
            }

            case 3: {
                printf("Valor removido da fila %d: ", removerElementoInicio(lista));
                break;
            }

            case 4: {
                lista = removerElementoFim(lista);
                break;
            }
           
            // case 5: {
            //     printf("Digite o valor que deseja procurar na lista: ");
            //     scanf("%d", &valorEscolhido);
            //     if (verificarValor(lista, valorEscolhido)) {
            //         printf("\nO Valor %d foi encontrado dentro da Lista \n", valorEscolhido);
            //     } else {
            //         printf("\nA lista nao possui esse valor \n");
            //     }
            //     break;
            // }

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
