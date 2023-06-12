#include <stdio.h>
#include <stdlib.h>
#define ICMS 18;

int main(void){
    struct pessoa{
        float altura;
        float peso;
        int idade;
    };

    struct pessoa maria;
    struct pessoa *pt;
    pt = &maria;

    pt->idade = 32;

    printf("Idade de Maria: %d", maria.idade);
    return 0;

        
};

