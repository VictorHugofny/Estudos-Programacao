#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

typedef struct Node {
  int item;
  struct Node *next;
} Node;

typedef struct List {
  Node *init;
  Node *end;
} List;

List *__list__();
Node *getElementByPosition(Node *node, const int position);
bool removeItem(List *list, const int index);
bool removeEndElement(List *list);
void add(List *list, int item);
Node *getInitList(List *list);
Node *getEndList(List *list);
void initList(List *list);
bool isEmpty(Node *node);
int getSize(List *list);
void show(Node *node);
Node *createNode();
#endif
