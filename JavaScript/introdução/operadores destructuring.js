// novo recurso do ES2015

const pessoa = {
    nome:'ane',
    idade:5,
    endereco: {
        logradouro: 'rua abc',
        numero: 1000
    }
}

const{nome,idade} = pessoa // tirar do objeto os elementos nome,idade
console.log(nome,idade)

const {nome:n, idade: i} = pessoa // tirar elementos e criar variaveis dentro
console.log(n,i)

const { endereco: { logradouro,numero }} = pessoa
console.log(logradouro,numero)