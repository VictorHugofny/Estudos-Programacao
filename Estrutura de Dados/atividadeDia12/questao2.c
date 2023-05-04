//crie uma struct para carro com os seguintes dados: modelo, valor, e ano
//no mesmo arquivo da struct pessoa.

//a) atualize a struct pessoa, pois agora a pessoa ira possuir um carro

//b) crei uma função que recebe um ponteiro que a ponta para uma pessoa
//e insira os dados do carro dessa pessoa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char modelo[50];
    float valor;
    int ano;
} Carro;

typedef struct {
    int idade;
    float peso;
    float altura;
    float imc;
    Carro carro;
} Pessoa;




void calcularImc(Pessoa *pessoa){
    pessoa->imc = pessoa->peso / (pessoa->altura * pessoa->altura);
}

void inserirCarro(Pessoa *pessoa){
    Carro carroAux;
    carroAux = pessoa->carro;
    carroAux.ano = 1999;
    strcpy(carroAux.modelo, "Gol");
    carroAux.valor = 2.500;

    pessoa->carro = carroAux;
}

void main(){
    Pessoa maria;
    Pessoa *pPessoa = &maria;
    
    pPessoa->idade = 23;
    pPessoa->altura = 1.83;
    pPessoa->peso = 75;
    pPessoa->imc = 0;

    calcularImc(pPessoa);
    // printf("ALTURA: %.2f IDADE: %d PESO:%.2f \n", maria.altura, maria.idade, maria.peso);
    // printf("o IMC de maria é %.2f \n", maria.imc);
    inserirCarro(pPessoa);
    printf("Carro Modelo: %s Ano: %d Valor: %f ", maria.carro.modelo, maria.carro.ano, maria.carro.valor);
}