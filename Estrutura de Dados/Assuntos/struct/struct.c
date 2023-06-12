#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa{
    int idade;
    float peso;
    char sexo;
    //char nome[30];
};

int main(){
    struct Pessoa maria, joana, victor, turma[10];
    
    turma[0].idade = 23;
    turma[0].sexo = 'f';
    turma[0].peso = 67;
    //maria.nome = 'Maria teste';

    printf("%d", turma[0].idade);
}