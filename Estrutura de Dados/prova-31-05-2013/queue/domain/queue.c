#include <stdbool.h>
#include <stdio.h>

#include "../../includes/queue.h"

bool isOdd(int quantityElement) { return quantityElement % 2 != 0; }

int getMiddleValue(Queue *queue) {
  Node *node = getInitQueue(queue);
  const int quantityElement = getSize(queue);
  if (!isOdd(quantityElement)) return 0;
  int count = 0;
  const int middleValueIndex = quantityElement / 2;
  while (!isEmpty(node)) {
    if (middleValueIndex == count) return node->item;
    node = node->next;
    count++;
  }
  return middleValueIndex;
}
