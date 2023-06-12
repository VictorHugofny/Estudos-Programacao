/* Questão 1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para
inteiro, real, e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de cada
variável usando os ponteiros. Imprima os valores das variáveis antes e após a modificação.
 */

#include <stdio.h>

#define false 0
#define true 1

int main() {
  int inteiro = 1;
  float real = 3.5;
  char caractere = 'C';

  int *ponteiroInteiro = &inteiro;
  float *ponteiroReal = &real;
  char *ponteiroChar = &caractere;

  printf("%i\n", inteiro);
  printf("%f\n", real);
  printf("%s\n", &caractere);

  *ponteiroInteiro = 5;
  *ponteiroReal = 10.5;
  *ponteiroChar = 'D';

  printf("%i\n", inteiro);
  printf("%f\n", real);
  printf("%s\n", &caractere);

  return false;
}
