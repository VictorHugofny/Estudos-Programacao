#include "../../includes/stack.h"

#include <stdio.h>

#include "stack.h"

int getPredecessorStack(Node *node) {
  if (!isEmpty(node) && !isEmpty(node->next) && !isEmpty(node->next->next))
    return node->next->item;
}

void invertStack(Stack **stack) {
  Stack *auxStack = __stack__();
  while (!isEmpty(getTop(*stack))) push(auxStack, pop(*stack));
  *stack = auxStack;
}

void copyStack(Stack *stack, Stack *copy) {
  Node *node = getTop(stack);
  while (!isEmpty(node)) {
    push(copy, node->item);
    node = node->next;
  }
}
