#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    float numeros[10] = {10.4, 20.5, 30.4, 40.3, 50.2, 23.4, 44.2, 42.4, 3.3,3.2};
    int i = 0;

    for (i = 0; i < 9; i++) {
      printf("posição: %i endereço de memoria: %d\n", i, &numeros[i]);
    }
}
