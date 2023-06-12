#include "../includes/queue.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/errors.h"

void initQueue(Queue *queue) {
  queue->init = NULL;
  queue->end = NULL;
}

Queue *__queue__() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  initQueue(queue);
  return queue;
}

Node *getInitQueue(Queue *queue) { return queue->init; }

bool isEmpty(Node *node) {
  if (!node) return true;
  return false;
}

int getSize(Queue *queue) {
  Node *node = getInitQueue(queue);
  int count = 0;
  while (!isEmpty(node)) {
    count++;
    node = node->next;
  }
  return count;
}

Node *createNode(const int item) {
  Node *node = (Node *)malloc(sizeof(node));
  if (!node) AllocationMemoryError();
  node->item = item;
  node->next = NULL;
}

void enqueue(Queue *queue, int item) {
  Node *node = createNode(item);
  if (isEmpty(getInitQueue(queue)))
    queue->init = node;
  else
    queue->end->next = node;
  queue->end = node;
}

void dequeue(Queue *queue) {
  Node *node = getInitQueue(queue);
  if (isEmpty(node)) return;
  queue->init = node->next;
  free(node);
}

void show(Node *node) {
  if (!isEmpty(node)) {
    printf("%i ", node->item);
    show(node->next);
  }
}
