#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;  // declaração do ponteiro p, que aponta para o endereço de memória de x
    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Valor de p: %p\n", p);
    printf("Valor apontado por p: %d\n", *p);  // acessa o valor apontado por p
    *p = 20;  // altera o valor apontado por p
    printf("Novo valor de x: %d\n", x);  // o valor de x foi alterado
    return 0;
}