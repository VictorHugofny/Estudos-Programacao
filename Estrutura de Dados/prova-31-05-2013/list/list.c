#include "../includes/list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/errors.h"

void initList(List *list) {
  list->init = NULL;
  list->end = NULL;
}

List *__list__() {
  List *list = (List *)malloc(sizeof(List));
  if (!list) AllocationMemoryError();
  initList(list);
  return list;
}

bool isEmpty(Node *node) {
  if (!node) return true;
  return false;
}

Node *createNode() {
  Node *node = (Node *)malloc(sizeof(Node));
  if (isEmpty(node)) AllocationMemoryError();
  return node;
}

Node *getInitList(List *list) { return list->init; }

Node *getEndList(List *list) { return list->end; }

int getSize(List *list) {
  Node *node = getInitList(list);
  int count = 0;
  while (!isEmpty(node)) {
    count++;
    node = node->next;
  }
  return count;
}

void add(List *list, int item) {
  Node *node = createNode();
  if (isEmpty(node)) AllocationMemoryError();
  node->item = item;
  node->next = NULL;
  if (!getInitList(list))
    list->init = node;
  else
    list->end->next = node;
  list->end = node;
}

Node *getElementByPosition(Node *node, const int position) {
  int count = 0;
  Node *previousNode = NULL;
  while (!isEmpty(node) && count < position) {
    previousNode = node;
    node = node->next;
    count++;
  }
  return previousNode;
}

bool removeEndElement(List *list) {
  Node *node = getInitList(list);
  Node *previousNode = NULL;
  while (!isEmpty(node->next)) {
    previousNode = node;
    node = node->next;
  }
  list->end = previousNode;
  if (isEmpty(previousNode))
    list->init = NULL;
  else
    previousNode->next = NULL;
  return true;
}

bool removeItem(List *list, int position) {
  if (isEmpty(getInitList(list))) return false;
  if (!position) return removeEndElement(list);
  const int quantityElement = getSize(list);
  bool isValidPosition = position <= quantityElement;
  if (!isValidPosition) return false;
  Node *previousNode = NULL;
  int count = 0;
  const int realIndex = position - 1;
  bool isInitList = realIndex == 0;
  if (isInitList) {
    list->init = list->init->next;
    return true;
  }
  Node *node = getElementByPosition(getInitList(list), realIndex);
  if (isEmpty(node)) return false;
  previousNode = node;
  node = node->next;
  previousNode->next = node->next;
  if (isEmpty(previousNode->next)) list->end = previousNode;
  return true;
}

void show(Node *node) {
  if (!isEmpty(node)) {
    printf("%i ", node->item);
    show(node->next);
  }
}
