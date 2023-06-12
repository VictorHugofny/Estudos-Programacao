#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct Node {
  int item;
  struct Node *next;
} Node;

typedef struct Queue {
  Node *init;
  Node *end;
} Queue;

Queue *__queue__();
void enqueue(Queue *queue, int item);
Node *getInitQueue(Queue *queue);
void initQueue(Queue *queue);
void dequeue(Queue *queue);
int getSize(Queue *queue);
bool isEmpty(Node *node);
void show(Node *node);
#endif
