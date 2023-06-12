#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void concatenarFilas(Fila* fila1, Fila* fila2) {
    if (filaVazia(fila2->inicio)) {
        printf("A segunda fila está vazia.\n");
        return;
    }

    if (filaVazia(fila1->inicio)) {
        fila1->inicio = fila2->inicio;
        fila1->fim = fila2->fim;
    } else {
        fila1->fim->proximo = fila2->inicio;
        fila1->fim = fila2->fim;
    }

    fila2->inicio = NULL;
    fila2->fim = NULL;

    printf("As filas foram concatenadas.\n");
}

void dividirFila(Fila* fila, int valor) {
    if (filaVazia(fila->inicio)) {
        printf("A fila está vazia.\n");
        return;
    }

    Fila* fila1 = criarFila();
    Fila* fila2 = criarFila();

    Elemento* atual = fila->inicio;
    while (atual) {
        if (atual->valor >= valor) {
            inserir(fila1, atual->valor);
        } else {
            inserir(fila2, atual->valor);
        }
        atual = atual->proximo;
    }

    printf("A fila foi dividida.\n");
    printf("Elementos maiores ou iguais a %d:\n", valor);
    imprimir(fila1);
    printf("Elementos menores que %d:\n", valor);
    imprimir(fila2);
}

void inverterFila(Fila* fila) {
    Elemento* anterior = NULL;
    Elemento* atual = fila->inicio;
    Elemento* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    fila->fim = fila->inicio;
    fila->inicio = anterior;

    printf("A fila foi invertida.\n");
}


int encontrarMaiorElemento(Fila* fila) {
    if (filaVazia(fila->inicio)) {
        printf("A fila está vazia.\n");
        return -1;
    }

    int maior = fila->inicio->valor;
    Elemento* atual = fila->inicio;

    while (atual != NULL) {
        if (atual->valor > maior) {
            maior = atual->valor;
        }
        atual = atual->proximo;
    }

    return maior;
}

void removerElementoPosicao(Fila* fila, int posicao) {
    if (filaVazia(fila->inicio)) {
        printf("A fila está vazia.\n");
        return;
    }

    if (posicao <= 0 || posicao > tamanhoFila(fila)) {
        printf("Posição inválida.\n");
        return;
    }

    if (posicao == 1) {
        removerElemento(fila);
        return;
    }

    Elemento* anterior = NULL;
    Elemento* atual = fila->inicio;
    int contador = 1;

    while (contador < posicao) {
        anterior = atual;
        atual = atual->proximo;
        contador++;
    }

    anterior->proximo = atual->proximo;

    if (atual == fila->fim) {
        fila->fim = anterior;
    }

    free(atual);
    printf("O elemento na posição %d foi removido.\n", posicao);
}


Fila* intercalarFilasAlternadamente(Fila* fila1, Fila* fila2) {
    Fila* filaIntercalada = criarFila();

    Elemento* atual1 = fila1->inicio;
    Elemento* atual2 = fila2->inicio;

    while (atual1 != NULL || atual2 != NULL) {
        if (atual1 != NULL) {
            inserir(filaIntercalada, atual1->valor);
            atual1 = atual1->proximo;
        }

        if (atual2 != NULL) {
            inserir(filaIntercalada, atual2->valor);
            atual2 = atual2->proximo;
        }
    }

    return filaIntercalada;
}
