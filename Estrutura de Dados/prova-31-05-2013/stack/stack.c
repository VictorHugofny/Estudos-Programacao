#include "../includes/stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/errors.h"

Stack *__stack__() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (!stack) AllocationMemoryError();
  stack->top = NULL;
  return stack;
}

Node *createNode(int item) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (!node) AllocationMemoryError();
  node->item = item;
  node->next = NULL;
  return node;
}

Node *getTop(Stack *stack) { return stack->top; }

bool isEmpty(Node *node) {
  if (!node) return true;
  return false;
}

void push(Stack *stack, int item) {
  Node *node = createNode(item);
  node->next = stack->top;
  stack->top = node;
}

int pop(Stack *stack) {
  Node *node = getTop(stack);
  if (isEmpty(getTop(stack))) return 0;
  const int backup = node->item;
  stack->top = node->next;
  node->next = NULL;
  return backup;
}

void show(Node *node) {
  if (!isEmpty(node)) {
    printf("\n%i ", node->item);
    show(node->next);
  }
}
