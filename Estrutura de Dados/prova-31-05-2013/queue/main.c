#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/queue.h"
#include "domain/queue.h"

int main() {
  Queue *queue = __queue__();
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);

  show(getInitQueue(queue));
  int middleValue = getMiddleValue(queue);
  printf("\n\n%i ", middleValue);
  return false;
}
