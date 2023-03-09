#include <stdio.h>
#include <stdlib.h>

void alterarValor(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void) {
  int a, b;
  a = 10;
  b = 20;

  alterarValor(&a,&b);
  printf("A: %d e B: %d", a, b);

  return 0;
}