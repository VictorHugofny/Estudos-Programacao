#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

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

for(index = 0; index < 5; ++index)

{

 printf("Informe valores: ");

 scanf("%d", &vetor[index]);

}

 

for(index = 0; index < 5; index++)

{

 printf("Valores %d\n", vetor[index]);

}

 

for(index = 0; index < 1; index++)

{

 ponteiro = vetor[0] * 2;

 printf("Vetor posicao 0 %d\n", ponteiro);

 ponteiro = vetor[1] * 2;

 printf("Vetor posicao 1 %d\n", ponteiro);

 ponteiro = vetor[2] * 2;

 printf("Vetor posicao 2 %d\n", ponteiro);

 ponteiro = vetor[3] * 2;

 printf("Vetor posicao 3 %d\n", ponteiro);

 ponteiro = vetor[4] * 2;

 printf("Vetor posicao 4 %d\n", ponteiro);

 

 //printf("Valor %d\n", &vetor[0]);

}

 

return 0;

}

