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

typedef struct Elemento {
    int valor;
    struct Elemento* proximo;
} Elemento;

typedef struct {
    Elemento* topo;
} Controle;

//Função para verificar se uma lista está ordenada de forma crescente:
bool listaOrdenadaCrescente(Lista* lista) {
    if (listaVazia(lista)) {
        printf("Lista vazia.\n");
        return false;
    }

    Elemento* elementoAtual = lista->inicio;
    int valorAnterior = elementoAtual->valor;

    while (elementoAtual != NULL) {
        if (elementoAtual->valor < valorAnterior) {
            return false;
        }
        valorAnterior = elementoAtual->valor;
        elementoAtual = elementoAtual->proximo;
    }

    return true;
}

//Função para inverter a ordem dos elementos em uma lista:
void inverterLista(Lista* lista) {
    if (listaVazia(lista)) {
        printf("Lista vazia. Nada a ser invertido.\n");
        return;
    }

    Controle* pilhaAuxiliar;
    pilhaAuxiliar->topo = NULL;

    while (!listaVazia(lista)) {
        int valor = removerInicio(lista);
        push(pilhaAuxiliar, valor);
    }

    while (!pilhaVazia(pilhaAuxiliar)) {
        int valor = pop(pilhaAuxiliar);
        inserirFim(lista, valor);
    }

    destruirPilha(pilhaAuxiliar);

    printf("Lista invertida com sucesso.\n");
}

//Função para encontrar o maior elemento em uma lista:
int encontrarMaiorElemento(Lista* lista) {
    if (listaVazia(lista)) {
        printf("Lista vazia. Nenhum elemento encontrado.\n");
        return -1;
    }

    int maior = lista->inicio->valor;
    Elemento* elementoAtual = lista->inicio->proximo;

    while (elementoAtual != NULL) {
        if (elementoAtual->valor > maior) {
            maior = elementoAtual->valor;
        }
        elementoAtual = elementoAtual->proximo;
    }

    return maior;
}

void ordenarListaCrescente(Lista* lista) {
    if (listaVazia(lista)) {
        printf("Lista vazia. Nada a ser ordenado.\n");
        return;
    }

    int troca;
    Elemento* elementoAtual;
    Elemento* elementoProximo = NULL;

    do {
        troca = 0;
        elementoAtual = lista->inicio;

        while (elementoAtual->proximo != elementoProximo) {
            if (elementoAtual->valor > elementoAtual->proximo->valor) {
                trocarElementos(elementoAtual, elementoAtual->proximo);
                troca = 1;
            }
            elementoAtual = elementoAtual->proximo;
        }
        elementoProximo = elementoAtual;

    } while (troca);

    printf("Lista ordenada em ordem crescente.\n");
}

void trocarElementos(Elemento* elementoA, Elemento* elementoB) {
    int temp = elementoA->valor;
    elementoA->valor = elementoB->valor;
    elementoB->valor = temp;
}

void ordenarListaDecrescente(Lista* lista) {
    if (listaVazia(lista)) {
        printf("Lista vazia. Nada a ser ordenado.\n");
        return;
    }

    int troca;
    Elemento* elementoAtual;
    Elemento* elementoProximo = NULL;

    do {
        troca = 0;
        elementoAtual = lista->inicio;

        while (elementoAtual->proximo != elementoProximo) {
            if (elementoAtual->valor < elementoAtual->proximo->valor) {
                trocarElementos(elementoAtual, elementoAtual->proximo);
                troca = 1;
            }
            elementoAtual = elementoAtual->proximo;
        }
        elementoProximo = elementoAtual;

    } while (troca);

    printf("Lista ordenada em ordem decrescente.\n");
}

//Função para intercalar duas listas:
Lista* intercalarListas(Lista* lista1, Lista* lista2) {
    if (listaVazia(lista1))
        return lista2;
    if (listaVazia(lista2))
        return lista1;

    Lista* listaIntercalada = criarLista();
    Elemento* atualLista1 = lista1->inicio;
    Elemento* atualLista2 = lista2->inicio;

    while (atualLista1 && atualLista2) {
        inserirFim(listaIntercalada, atualLista1->valor);
        inserirFim(listaIntercalada, atualLista2->valor);
        atualLista1 = atualLista1->proximo;
        atualLista2 = atualLista2->proximo;
    }

    while (atualLista1) {
        inserirFim(listaIntercalada, atualLista1->valor);
        atualLista1 = atualLista1->proximo;
    }

    while (atualLista2) {
        inserirFim(listaIntercalada, atualLista2->valor);
        atualLista2 = atualLista2->proximo;
    }

    return listaIntercalada;
}

//Função para obter a união de duas listas (removendo elementos duplicados):
Lista* uniaoListas(Lista* lista1, Lista* lista2) {
    Lista* listaUniao = criarLista();
    Elemento* atual = lista1->inicio;

    while (atual) {
        inserirFimSemRepeticao(listaUniao, atual->valor);
        atual = atual->proximo;
    }

    atual = lista2->inicio;

    while (atual) {
        inserirFimSemRepeticao(listaUniao, atual->valor);
        atual = atual->proximo;
    }

    return listaUniao;
}

//Função para verificar se duas listas são iguais:
bool listasIguais(Lista* lista1, Lista* lista2) {
    Elemento* atualLista1 = lista1->inicio;
    Elemento* atualLista2 = lista2->inicio;

    while (atualLista1 && atualLista2) {
        if (atualLista1->valor != atualLista2->valor)
            return false;
        atualLista1 = atualLista1->proximo;
        atualLista2 = atualLista2->proximo;
    }

    return (atualLista1 == NULL && atualLista2 == NULL);
}

void inverterLista(Lista* lista) {
    Elemento* anterior = NULL;
    Elemento* atual = lista->inicio;
    Elemento* proximo = NULL;

    while (atual) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista->inicio = anterior;
}

void dividirLista(Lista* lista, int valor, Lista** listaMenor, Lista** listaMaior) {
    *listaMenor = criarLista();
    *listaMaior = criarLista();

    Elemento* atual = lista->inicio;

    while (atual) {
        if (atual->valor <= valor)
            inserirFim(*listaMenor, atual->valor);
        else
            inserirFim(*listaMaior, atual->valor);

        atual = atual->proximo;
    }
}

//Função para mesclar duas listas ordenadas em uma única lista ordenada:
Lista* mergeSortedLists(Lista* lista1, Lista* lista2) {
    Lista* mergedList = criarLista();
    Elemento* atual1 = lista1->inicio;
    Elemento* atual2 = lista2->inicio;

    while (atual1 && atual2) {
        if (atual1->valor <= atual2->valor) {
            inserirFim(mergedList, atual1->valor);
            atual1 = atual1->proximo;
        } else {
            inserirFim(mergedList, atual2->valor);
            atual2 = atual2->proximo;
        }
    }

    while (atual1) {
        inserirFim(mergedList, atual1->valor);
        atual1 = atual1->proximo;
    }

    while (atual2) {
        inserirFim(mergedList, atual2->valor);
        atual2 = atual2->proximo;
    }

    return mergedList;
}

//Função para remover elementos duplicados de uma lista:
void removerDuplicados(Lista* lista) {
    Elemento* atual = lista->inicio;

    while (atual) {
        Elemento* iter = atual;
        while (iter->proximo) {
            if (iter->proximo->valor == atual->valor) {
                Elemento* duplicado = iter->proximo;
                iter->proximo = iter->proximo->proximo;
                free(duplicado);
            } else {
                iter = iter->proximo;
            }
        }
        atual = atual->proximo;
    }
}

//Função para encontrar a interseção entre duas listas:
Lista* encontrarIntersecao(Lista* lista1, Lista* lista2) {
    Lista* intersecao = criarLista();
    Elemento* atual1 = lista1->inicio;

    while (atual1) {
        Elemento* atual2 = lista2->inicio;
        while (atual2) {
            if (atual1->valor == atual2->valor) {
                inserirFim(intersecao, atual1->valor);
                break;
            }
            atual2 = atual2->proximo;
        }
        atual1 = atual1->proximo;
    }

    return intersecao;
}

//Função para encontrar o valor mínimo e máximo em uma lista:
void encontrarMinimoMaximo(Lista* lista, int* minimo, int* maximo) {
    if (lista->inicio == NULL) {
        *minimo = 0;
        *maximo = 0;
        return;
    }

    Elemento* atual = lista->inicio;
    *minimo = atual->valor;
    *maximo = atual->valor;

    while (atual) {
        if (atual->valor < *minimo) {
            *minimo = atual->valor;
        }

        if (atual->valor > *maximo) {
            *maximo = atual->valor;
        }

        atual = atual->proximo;
    }
}
