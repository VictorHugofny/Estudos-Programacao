#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

/*
Crie um programa que contenha um vetor de inteiros contendo 5 elementos.
Utilizando apenas aritmética de ponteiros, leia esse vetor do teclado e
imprima o dobro de cada valor lido.
*/

int main()
{
int vetor[TAMANHO];
int *ponteiro;
int index;

for (index = 0; index < TAMANHO; ++index)
{
    printf("Informe valores: ");
    scanf("%d", &vetor[index]);
}

printf("Valores informados:\n");

for (index = 0; index < TAMANHO; index++)
{
    printf("%d\n", vetor[index]);
}

printf("Valores dobrados:\n");

for (index = 0; index < TAMANHO; index++)
{
    ponteiro = &vetor[index]; // atribui o endereço de memória da posição atual do vetor ao ponteiro
    *ponteiro *= 2; // multiplica o valor da posição atual do vetor por 2
    printf("%d\n", *ponteiro); // imprime o valor dobrado
}

return 0;