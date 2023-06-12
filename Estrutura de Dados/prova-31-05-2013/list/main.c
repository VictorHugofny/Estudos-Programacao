#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/list.h"
#include "domain/list.h"

int main() {
  List *list = __list__();
  add(list, 50);
  add(list, 10);
  add(list, 20);
  add(list, 40);
  add(list, 30);
  add(list, 60);
  removeEndElement(list);
  // removeItem(list, 1);
  // insertAfterFirstGreater(list, 35, 20);
  // addOnlyInit(list, 100);
  // addOnlyInit(list, 200);
  // orderList(&list, "decrescente");
  // show(getInitList(list));
  // orderList(&list, "crescente");
  show(getInitList(list));
  return false;
}
