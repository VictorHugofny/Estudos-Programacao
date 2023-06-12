#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int valor;
    struct Elemento* proximo;
} Elemento;

typedef struct {
    Elemento* topo;
} Controle;

// Função para empilhar elementos de uma pilha em outra
void empilharPilha(Controle* p1, Controle* p2) {
    Controle aux;
    aux.topo = NULL;

    // Desempilhar elementos da pilha 2 e empilhar na pilha auxiliar
    while (p2->topo != NULL) {
        Elemento* e = p2->topo;
        p2->topo = e->proximo;

        e->proximo = aux.topo;
        aux.topo = e;
    }

    // Desempilhar elementos da pilha auxiliar e empilhar na pilha 1
    while (aux.topo != NULL) {
        Elemento* e = aux.topo;
        aux.topo = e->proximo;

        e->proximo = p1->topo;
        p1->topo = e;
    }
}

// Função para desempilhar elementos da pilha até encontrar um valor específico
void desempilharPilhaParcial(Controle* p, int valor) {
    while (p->topo != NULL && p->topo->valor != valor) {
        Elemento* e = p->topo;
        p->topo = e->proximo;
        free(e);
    }
}

// Função para comparar os elementos do topo de duas pilhas
int compararTopsPilhas(Controle* p1, Controle* p2) {
    if (p1->topo == NULL || p2->topo == NULL) {
        return 0; // Pilhas vazias, elementos diferentes
    }

    return p1->topo->valor == p2->topo->valor;
}

// Função para criar uma cópia invertida de uma pilha
Controle* copiarPilhaInvertida(Controle* p) {
    Controle* copia = (Controle*)malloc(sizeof(Controle));
    copia->topo = NULL;

    Controle aux;
    aux.topo = NULL;

    // Desempilhar elementos da pilha original e empilhar na pilha auxiliar
    while (p->topo != NULL) {
        Elemento* e = p->topo;
        p->topo = e->proximo;

        e->proximo = aux.topo;
        aux.topo = e;
    }

    // Copiar elementos da pilha auxiliar para a pilha de cópia
    while (aux.topo != NULL) {
        Elemento* e = aux.topo;
        aux.topo = e->proximo;

        e->proximo = copia->topo;
        copia->topo = e;
    }

    return copia;
}

// Função para intercalar os elementos de duas pilhas de forma alternada
Controle* intercalarPilhas(Controle* p1, Controle* p2) {
    Controle* intercalada = (Controle*)malloc(sizeof(Controle));
    intercalada->topo = NULL;

    while (p1->topo != NULL || p2->topo != NULL) {
        if (p1->topo != NULL) {
            Elemento* e1 = p1->topo;
            p1->topo = e1->proximo;

            e1->proximo = intercalada->topo;
            intercalada->topo = e1;
        }

        if (p2->topo != NULL) {
            Elemento* e2 = p2->topo;
            p2->topo = e2->proximo;

            e2->proximo = intercalada->topo;
            intercalada->topo = e2;
        }
    }

    return intercalada;
}

// Função para obter o tamanho da pilha
int tamanhoPilha(Controle* p) {
    int tamanho = 0;
    Elemento* atual = p->topo;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

void imprimir(Controle* p) {
    Elemento* atual = p->topo;
    if (atual == NULL) {
        printf("Pilha vazia\n");
    } else {
        printf("Elementos da pilha:\n");
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

void empilhar(Controle* p, int val) {
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->valor = val;
    novo->proximo = p->topo;
    p->topo = novo;
}

void desempilhar(Controle* p) {
    if (p->topo != NULL) {
        Elemento* topo = p->topo;
        p->topo = topo->proximo;
        free(topo);
    } else {
        printf("Pilha vazia\n");
    }
}

int main() {
    Controle p1;
    p1.topo = NULL;

    Controle p2;
    p2.topo = NULL;

    // Exemplo de uso das novas funções
    empilhar(&p1, 1);
    empilhar(&p1, 2);
    empilhar(&p1, 3);

    empilhar(&p2, 4);
    empilhar(&p2, 5);
    empilhar(&p2, 6);

    printf("Pilha 1:\n");
    imprimir(&p1);
    printf("Pilha 2:\n");
    imprimir(&p2);

    empilharPilha(&p1, &p2);
    printf("Pilha 1 após empilhar elementos da pilha 2:\n");
    imprimir(&p1);

    desempilharPilhaParcial(&p1, 3);
    printf("Pilha 1 após desempilhar elementos até o valor 3:\n");
    imprimir(&p1);

    int comparacao = compararTopsPilhas(&p1, &p2);
    if (comparacao) {
        printf("Os elementos do topo das pilhas 1 e 2 são iguais\n");
    } else {
        printf("Os elementos do topo das pilhas 1 e 2 são diferentes\n");
    }

    Controle* pilhaInvertida = copiarPilhaInvertida(&p1);
    printf("Cópia invertida da pilha 1:\n");
    imprimir(pilhaInvertida);

    Controle* pilhaIntercalada = intercalarPilhas(&p1, &p2);
    printf("Pilha intercalada das pilhas 1 e 2:\n");
    imprimir(pilhaIntercalada);

    int tamanho = tamanhoPilha(&p1);
    printf("Tamanho da pilha 1: %d\n", tamanho);

    return 0;
}
