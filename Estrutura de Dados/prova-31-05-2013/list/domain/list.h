#include <stdbool.h>

#include "../../includes/list.h"

const char *filter(const char *array[], const int size, const char *option);
void insertAfterFirstGreater(List *list, int item, const int firstGreater);
bool removeElementFirstGreater(List *list, const int firstGreater);
void orderList(List **list, const char *type);
void addOnlyInit(List *list, const int item);
void decreasing(List *list);
void crescent(List *list);
