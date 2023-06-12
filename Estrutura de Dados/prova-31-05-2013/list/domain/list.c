#include "../../includes/list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertAfterFirstGreater(List *list, int item, const int firstGreater) {
  Node *node = createNode();
  node->item = item;
  node->next = NULL;
  Node *initList = getInitList(list);
  if (isEmpty(initList)) {
    list->init = node;
    list->end = node;
    return;
  }
  Node *auxNode = initList;
  while (!isEmpty(auxNode)) {
    if (auxNode->item > firstGreater) {
      node->next = auxNode->next;
      auxNode->next = node;
      break;
    }
    auxNode = auxNode->next;
  }
  auxNode->next = node;
}

bool removeElementFirstGreater(List *list, const int firstGreater) {
  Node *node = getInitList(list);
  int currentNodeValue = 0;
  int count = 0;
  while (!isEmpty(node)) {
    if (node->item > firstGreater) {
      currentNodeValue = node->item;
      count++;
      break;
    };
    node = node->next;
    count++;
  }
  const bool isRemoved = removeItem(list, count);
  if (!isRemoved) return false;
  return true;
}

void addOnlyInit(List *list, const int item) {
  Node *node = createNode();
  node->item = item;
  node->next = getInitList(list);
  list->init = node;
}

const char *filter(const char *array[], const int size, const char *option) {
  for (int i = 0; i < size; i++)
    if (strcmp(option, array[i]) == 0) return array[i];
  return "";
}

void crescent(List *list) {
  Node *node = getInitList(list);
  Node *auxNode = NULL;
  while (!isEmpty(node)) {
    auxNode = node->next;
    while (!isEmpty(auxNode)) {
      if (node->item > auxNode->item) {
        int bigger = node->item;
        node->item = auxNode->item;
        auxNode->item = bigger;
      }
      auxNode = auxNode->next;
    }
    node = node->next;
  }
}

void decreasing(List *list) {
  Node *node = getInitList(list);
  Node *auxNode = NULL;
  while (!isEmpty(node)) {
    auxNode = node->next;
    while (!isEmpty(auxNode)) {
      if (node->item < auxNode->item) {
        int smaller = node->item;
        node->item = auxNode->item;
        auxNode->item = smaller;
      }
      auxNode = auxNode->next;
    }
    node = node->next;
  }
}

void orderList(List **list, const char *type) {
  const char *options[] = {"crescente", "decrescente"};
  if (strcmp(type, options[0]) == 0) {
    printf("%s ", options[0]);
    crescent(*list);
  }
  if (strcmp(type, options[1]) == 0) {
    printf("%s ", options[1]);
    decreasing(*list);
  }
}
