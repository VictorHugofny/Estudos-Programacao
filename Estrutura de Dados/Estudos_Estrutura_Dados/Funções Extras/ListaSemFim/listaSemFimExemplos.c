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

// Função para inserir antes de um valor específico
void inserirAntesValor(Lista* lista, int valorAlvo, int valorNovo) {
    if (lista->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }

    if (lista->inicio->valor == valorAlvo) {
        inserirInicio(lista, valorNovo);
        return;
    }

    Elemento* elementoAnterior = NULL;
    Elemento* elementoAtual = lista->inicio;

    while (elementoAtual != NULL) {
        if (elementoAtual->valor == valorAlvo) {
            Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
            novoElemento->valor = valorNovo;
            novoElemento->proximo = elementoAtual;
            elementoAnterior->proximo = novoElemento;
            break;
        }
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->proximo;
    }
}

// Função para inserir no final da lista se o valor for menor que 100
void inserirFimMenorCem(Lista* lista, int valor) {
    if (valor >= 100) {
        printf("Valor maior ou igual a 100. Não é possível inserir no final.\n");
        return;
    }

    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->valor = valor;
    novoElemento->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoElemento;
    } else {
        Elemento* elementoAtual = lista->inicio;
        while (elementoAtual->proximo != NULL) {
            elementoAtual = elementoAtual->proximo;
        }
        elementoAtual->proximo = novoElemento;
    }
}

// Função para remover o elemento depois de um valor específico
void removerDepoisValor(Lista* lista, int valorAlvo) {
    Elemento* elementoAtual = lista->inicio;

    while (elementoAtual != NULL && elementoAtual->valor != valorAlvo) {
        elementoAtual = elementoAtual->proximo;
    }

    if (elementoAtual == NULL || elementoAtual->proximo == NULL) {
        printf("Valor alvo não encontrado ou não há elemento depois.\n");
        return;
    }

    Elemento* elementoRemovido = elementoAtual->proximo;
    elementoAtual->proximo = elementoRemovido->proximo;
    free(elementoRemovido);
}

// Função para remover o elemento antes de um valor específico
void removerAntesValor(Lista* lista, int valorAlvo) {

    if (lista->inicio == NULL || lista->inicio->valor == valorAlvo) {
        printf("Lista vazia ou valor alvo encontrado no início. Nenhum elemento antes para remover.\n");
        return;
    }

    if (lista->inicio->proximo != NULL && lista->inicio->proximo->valor == valorAlvo) {
        removerInicio(lista);
        return;
    }

    Elemento* elementoAnterior = NULL;
    Elemento* elementoAtual = lista->inicio;

    while (elementoAtual != NULL && elementoAtual->valor != valorAlvo) {
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->proximo;
    }

    if (elementoAtual == NULL) {
        printf("Valor alvo não encontrado na lista. Nenhum elemento antes para remover.\n");
        return;
    }

    Elemento* elementoRemovido = elementoAnterior;
    elementoAnterior = elementoRemovido->proximo;
    free(elementoRemovido);
}

// Função para remover o último elemento da lista se o valor for menor que 100
void removerFimMenorCem(Lista* lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia. Nenhum elemento para remover.\n");
        return;
    }

    Elemento* elementoAnterior = NULL;
    Elemento* elementoAtual = lista->inicio;

    while (elementoAtual->proximo != NULL) {
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->proximo;
    }

    if (elementoAtual->valor < 100) {
        if (elementoAnterior == NULL) {
            lista->inicio = NULL;
        } else {
            elementoAnterior->proximo = NULL;
        }
        free(elementoAtual);
    } else {
        printf("O último elemento não é menor que 100. Nenhum elemento removido.\n");
    }
}

void removerPrimeiroPar(Lista* lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia. Nenhum elemento para remover.\n");
        return;
    }

    Elemento* elementoAtual = lista->inicio;

    if (elementoAtual->valor % 2 == 0) {
        lista->inicio = elementoAtual->proximo;
        free(elementoAtual);
        printf("Primeiro elemento par removido.\n");
        return;
    }

    Elemento* elementoAnterior = NULL;

    while (elementoAtual != NULL && elementoAtual->valor % 2 != 0) {
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->proximo;
    }

    if (elementoAtual != NULL) {
        elementoAnterior->proximo = elementoAtual->proximo;
        free(elementoAtual);
        printf("Primeiro elemento par removido.\n");
    } else {
        printf("Nenhum elemento par encontrado para remoção.\n");
    }
}

void removerUltimoImpar(Lista* lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia. Nenhum elemento para remover.\n");
        return;
    }

    Elemento* elementoAnterior = NULL;
    Elemento* elementoAtual = lista->inicio;

    while (elementoAtual->proximo != NULL) {
        if (elementoAtual->proximo->valor % 2 != 0) {
            elementoAnterior = elementoAtual;
        }
        elementoAtual = elementoAtual->proximo;
    }

    if (elementoAnterior == NULL) {
        printf("Nenhum elemento ímpar encontrado para remoção.\n");
    } else {
        Elemento* elementoRemovido = elementoAnterior->proximo;
        elementoAnterior->proximo = NULL;
        free(elementoRemovido);
        printf("Último elemento ímpar removido.\n");
    }
}

void inserirInicioPositivo(Lista* lista, int valor) {
    if (valor <= 0) {
        printf("Valor inválido. Inserção no início não permitida.\n");
        return;
    }

    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->valor = valor;
    novoElemento->proximo = lista->inicio;
    lista->inicio = novoElemento;
    printf("Inserção no início realizada.\n");
}
