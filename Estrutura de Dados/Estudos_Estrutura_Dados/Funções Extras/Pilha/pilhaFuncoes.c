#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int valor;
    struct Elemento* proximo;
} Elemento;

typedef struct Controle {
    Elemento* topo;
} Controle;

// Função para criar uma nova pilha
Controle* criarPilha() {
    Controle* p = (Controle*)malloc(sizeof(Controle));
    p->topo = NULL;
    return p;
}

// Função para empilhar um elemento na pilha
void empilhar(Controle* p, int val) {
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->valor = val;
    novo->proximo = p->topo;
    p->topo = novo;
}

// Função para desempilhar um elemento da pilha
void desempilhar(Controle* p) {
    if (p->topo != NULL) {
        Elemento* topo = p->topo;
        p->topo = topo->proximo;
        free(topo);
    } else {
        printf("Pilha vazia\n");
    }
}

// Função para imprimir os elementos da pilha
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

// Função para verificar se a pilha está vazia
int pilhaVazia(Controle* p) {
    return (p->topo == NULL);
}

// Função para obter o valor do topo da pilha
int topoPilha(Controle* p) {
    if (p->topo != NULL) {
        return p->topo->valor;
    } else {
        printf("Pilha vazia\n");
        return -1; // Valor de erro
    }
}

// Função para somar todos os elementos da pilha
int somaElementos(Controle* p) {
    int soma = 0;
    Elemento* atual = p->topo;
    while (atual != NULL) {
        soma += atual->valor;
        atual = atual->proximo;
    }
    return soma;
}

// Função para encontrar o maior elemento da pilha
int maiorElemento(Controle* p) {
    int maior = -1; // Valor inicial inválido
    Elemento* atual = p->topo;
    while (atual != NULL) {
        if (atual->valor > maior) {
            maior = atual->valor;
        }
        atual = atual->proximo;
    }
    return maior;
}

int main() {
    Controle* pilha = criarPilha();

    empilhar(pilha, 10);
    empilhar(pilha, 5);
    empilhar(pilha, 8);
    empilhar(pilha, 3);

    printf("Pilha original:\n");
    imprimir(pilha);

    printf("Valor do topo da pilha: %d\n", topoPilha(pilha));
    printf("Soma dos elementos da pilha: %d\n", somaElementos(pilha));
    printf("Maior elemento da pilha: %d\n", maiorElemento(pilha));

    desempilhar(pilha);
    printf("Pilha após desempilhar um elemento:\n");
    imprimir(pilha);

    return 0;
}
