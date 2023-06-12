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

void concatenarListas(Lista *lista1, Lista *lista2) {
    if (lista1->inicio == NULL) {
        lista1->inicio = lista2->inicio;
    } else {
        lista1->fim->proximo = lista2->inicio;
    }
    lista1->fim = lista2->fim;
    free(lista2); // Liberar a estrutura da segunda lista, mas não os elementos individuais
}

int saoListasIguais(Lista *lista1, Lista *lista2) {
    Elemento *atual1 = lista1->inicio;
    Elemento *atual2 = lista2->inicio;

    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->valor != atual2->valor) {
            return 0; // As listas são diferentes
        }
        atual1 = atual1->proximo;
        atual2 = atual2->proximo;
    }

    // Verifica se as duas listas chegaram ao fim ao mesmo tempo
    if (atual1 == NULL && atual2 == NULL) {
        return 1; // As listas são iguais
    } else {
        return 0; // As listas têm tamanhos diferentes
    }
}

void listaParaFila(Lista *lista, Fila *fila) {
    Elemento *atual = lista->inicio;

    while (atual != NULL) {
        inserir(fila, atual->valor);
        atual = atual->proximo;
    }
}

void filaParaLista(Fila *fila, Lista *lista) {
    while (!filaVazia(fila)) {
        int valor = remover(fila);
        inserir(lista, valor);
    }
}

void listaParaPilha(Lista *lista, Pilha *pilha) {
    Elemento *atual = lista->inicio;

    while (atual != NULL) {
        empilhar(pilha, atual->valor);
        atual = atual->proximo;
    }
}

void pilhaParaLista(Pilha *pilha, Lista *lista) {
    while (!pilhaVazia(pilha)) {
        int valor = desempilhar(pilha);
        insirirInicio(lista, valor);
    }
}

Lista* mesclarListas(Lista* listaA, Lista* listaB) {
    Lista* listaMerged = criarLista();
    Elemento* atualA = listaA->inicio;
    Elemento* atualB = listaB->inicio;

    while (atualA && atualB) {
        if (atualA->valor <= atualB->valor) {
            inserir(listaMerged, atualA->valor);
            atualA = atualA->proximo;
        } else {
            inserir(listaMerged, atualB->valor);
            atualB = atualB->proximo;
        }
    }

    while (atualA) {
        inserir(listaMerged, atualA->valor);
        atualA = atualA->proximo;
    }

    while (atualB) {
        inserir(listaMerged, atualB->valor);
        atualB = atualB->proximo;
    }

    return listaMerged;
}

Lista* elementosComuns(Lista* listaA, Lista* listaB) {
    Lista* listaComum = criarLista();
    Elemento* atualA = listaA->inicio;
    Elemento* atualB = listaB->inicio;

    while (atualA && atualB) {
        if (atualA->valor < atualB->valor) {
            atualA = atualA->proximo;
        } else if (atualA->valor > atualB->valor) {
            atualB = atualB->proximo;
        } else {
            inserir(listaComum, atualA->valor);
            atualA = atualA->proximo;
            atualB = atualB->proximo;
        }
    }

    return listaComum;
}
