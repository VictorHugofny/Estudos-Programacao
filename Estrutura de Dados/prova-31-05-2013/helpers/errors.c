#include "../includes/errors.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void AllocationMemoryError() {
  printf("Erro na alocação de memória");
  exit(true);
}
