#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct Node {
  int item;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
} Stack;

Stack *__stack__();
void push(Stack *stack, int item);
Node *getTop(Stack *stack);
int getSize(Stack *stack);
bool isEmpty(Node *node);
int pop(Stack *stack);
void show(Node *node);
#endif
