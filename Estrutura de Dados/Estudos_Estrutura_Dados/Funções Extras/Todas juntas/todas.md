#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int valor;
    struct Elemento* proximo;
} Elemento;

typedef struct {
    Elemento* topo;
} Controle;

// Função para verificar se uma palavra é um palíndromo
int verificarPalindromo(char* palavra) {
    Pilha* pilha = criarPilha(strlen(palavra));
    int tamanho = strlen(palavra);

    for (int i = 0; i < tamanho; i++) {
        empilhar(pilha, palavra[i]);
    }

    char inverso[tamanho + 1];
    int index = 0;
    while (!vazia(pilha)) {
        inverso[index] = desempilhar(pilha);
        index++;
    }
    inverso[index] = '\0';

    return strcmp(palavra, inverso) == 0;
}

// Função para verificar se uma expressão matemática contendo parênteses está balanceada
int verificarBalanceamento(char* expressao) {
    Pilha* pilha = criarPilha(strlen(expressao));

    int tamanho = strlen(expressao);
    for (int i = 0; i < tamanho; i++) {
        if (expressao[i] == '(') {
            empilhar(pilha, expressao[i]);
        } else if (expressao[i] == ')') {
            if (vazia(pilha)) {
                return 0;
            }
            desempilhar(pilha);
        }
    }

    return vazia(pilha);
}

// Função para inverter uma fila
void inverterFila(Fila* fila) {
    Pilha* pilha = criarPilha(tamanho(fila));

    while (!vazia(fila)) {
        empilhar(pilha, desenfileirar(fila));
    }

    while (!vazia(pilha)) {
        enfileirar(fila, desempilhar(pilha));
    }
}

// Função para remover elementos duplicados de uma lista
void removerDuplicados(Lista* lista) {
    if (lista == NULL || lista->inicio == NULL) {
        return;
    }

    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        while (proximo != NULL && proximo->valor == atual->valor) {
            No* temp = proximo;
            proximo = proximo->proximo;
            free(temp);
        }
        atual->proximo = proximo;
        atual = atual->proximo;
    }
}

// Função para intercalar os elementos de duas listas em uma terceira lista
Lista* intercalarListas(Lista* lista1, Lista* lista2) {
    Lista* novaLista = criarLista();
    No* atual1 = lista1->inicio;
    No* atual2 = lista2->inicio;

    while (atual1 != NULL || atual2 != NULL) {
        if (atual1 != NULL) {
            inserirFim(novaLista, atual1->valor);
            atual1 = atual1->proximo;
        }
        if (atual2 != NULL) {
            inserirFim(novaLista, atual2->valor);
            atual2 = atual2->proximo;
        }
    }

    return novaLista;
}
