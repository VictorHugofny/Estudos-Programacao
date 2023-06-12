#include <stdbool.h>
#include <stdio.h>

#include "../includes/stack.h"
#include "domain/stack.h"

void menu();

int main() {
  menu();
  Stack *stack = __stack__();
  push(stack, 10);
  push(stack, 20);
  push(stack, 30);
  push(stack, 40);
  push(stack, 50);
  push(stack, 60);
  push(stack, 70);
  push(stack, 80);
  push(stack, 90);

  Node *top = getTop(stack);
  printf("\nAntecessor: %i\n", getPredecessorStack(getTop(stack)));
  invertStack(&stack);
  Stack *newStack = __stack__();
  copyStack(stack, newStack);
  show(getTop(stack));
  return false;
}

void menu() {
  int option;
  do {
    printf("Selecione:");
    scanf("%i", &option);
  } while (option != 0);
}
