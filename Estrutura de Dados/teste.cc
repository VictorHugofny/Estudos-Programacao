#include<stdio.h>


int main(void){
    int a = 2;
    int b = 3;

    float c = (float) (2 + 3) / 2;

    printf("%f", c);

    //alocação de memoria, fzr cast pra forçar um tipo de dado
    //int *p = (int*) malloc (sizeof(int));
    //FREE(p)
    return 0;
}