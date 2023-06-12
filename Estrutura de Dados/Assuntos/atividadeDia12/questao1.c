//crie uma estrutura para pessoa onde ser armazenado os seguintes dados: idade, peso, altura, imc.
//crie uma instancia da estrutura denominada maria
//crie um ponteiro que armazena o endereço de "maria"
//insira os dados de idade, peso, e altura na estrutura, atraves do ponteiro
//crie uma função que recebe o ponteiro criado em (b), calcula o mic com os dados ja inseridos e atualiza o IMC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idade;
    float peso;
    float altura;
    float imc;
} Pessoa;

void calcularImc(Pessoa *pessoa){
    pessoa->imc = pessoa->peso / (pessoa->altura * pessoa->altura);
}

void main(){
    Pessoa maria;
    Pessoa *pPessoa = &maria;
    
    pPessoa->idade = 23;
    pPessoa->altura = 1.83;
    pPessoa->peso = 75;
    pPessoa->imc = 0;

    calcularImc(pPessoa);
    printf("ALTURA: %.2f IDADE: %d PESO:%.2f \n", maria.altura, maria.idade, maria.peso);
    printf("o IMC de maria é %.2f \n", maria.imc);
}