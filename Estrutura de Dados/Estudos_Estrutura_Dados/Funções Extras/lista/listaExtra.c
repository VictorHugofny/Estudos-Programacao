#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

void inserirAposPrimeiroMaior(Lista *lista, int valorNovo) {
    Elemento *no = lista->inicio;
    while (no) {
        if (no->valor > 10) {
            Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));
            novoElemento->valor = valorNovo;
            novoElemento->proximo = no->proximo;
            no->proximo = novoElemento;
            if (no == lista->fim) {
                lista->fim = novoElemento;
            }
            return;
        }
        no = no->proximo;
    }

    // Se não houver valor maior que 10, insere o novo elemento no final
    Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));
    novoElemento->valor = valorNovo;
    novoElemento->proximo = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novoElemento;
    } else {
        lista->fim->proximo = novoElemento;
    }
    lista->fim = novoElemento;
}

void removerNumeroEspecifico(Lista *lista, int numero) {
    Elemento *atual = lista->inicio;
    Elemento *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == numero) {
            if (anterior == NULL) {
                // O elemento a ser removido é o primeiro da lista
                lista->inicio = atual->proximo;
            } else {
                // O elemento a ser removido não é o primeiro da lista
                anterior->proximo = atual->proximo;
            }

            // Verifica se o elemento a ser removido é o último da lista
            if (atual == lista->fim) {
                lista->fim = anterior;
            }

            free(atual); // Libera a memória do elemento removido
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("O numero %d nao foi encontrado na lista\n", numero);
}

bool verificarElemento(Lista *lista, int valor) {
    Elemento *no = lista->inicio;

    while (no) {
        if (no->valor == valor) {
            return true;
        }
        no = no->proximo;
    }

    return false;
}

int obterUltimoElemento(Lista *lista) {
    if (lista->fim) {
        return lista->fim->valor;
    }
    return -1; // Valor de retorno inválido, se a lista estiver vazia
}

void removerElementosIguais(Lista *lista, int valor) {
    Elemento *no = lista->inicio;
    Elemento *anterior = NULL;

    while (no) {
        if (no->valor == valor) {
            if (anterior) {
                anterior->proximo = no->proximo;
            } else {
                lista->inicio = no->proximo;
            }
            free(no);
            no = (anterior ? anterior->proximo : lista->inicio);
        } else {
            anterior = no;
            no = no->proximo;
        }
    }
}

bool verificarOrdenacaoCrescente(Lista *lista) {
    Elemento *no = lista->inicio;

    while (no && no->proximo) {
        if (no->valor > no->proximo->valor) {
            return false;
        }
        no = no->proximo;
    }

    return true;
}

void inverterLista(Lista *lista) {
    Elemento *atual = lista->inicio;
    Elemento *anterior = NULL;
    Elemento *proximo = NULL;

    while (atual) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista->fim = lista->inicio;
    lista->inicio = anterior;
}

void inserirElementoPosicao(Lista *lista, int valor, int posicao) {
    if (posicao < 0) {
        printf("Posição inválida\n");
        return;
    }

    Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));
    novoElemento->valor = valor;
    novoElemento->proximo = NULL;

    if (posicao == 0) {
        novoElemento->proximo = lista->inicio;
        lista->inicio = novoElemento;
        if (lista->fim == NULL) {
            lista->fim = novoElemento;
        }
    } else {
        Elemento *no = lista->inicio;
        int contador = 0;
        while (no && contador < posicao - 1) {
            no = no->proximo;
            contador++;
        }
        if (no == NULL) {
            printf("Posição inválida\n");
            return;
        }
        novoElemento->proximo = no->proximo;
        no->proximo = novoElemento;
        if (no == lista->fim) {
            lista->fim = novoElemento;
        }
    }
}

void removerPrimeiroElemento(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("A lista está vazia\n");
        return;
    }

    Elemento *noRemovido = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    free(noRemovido);

    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }
}



