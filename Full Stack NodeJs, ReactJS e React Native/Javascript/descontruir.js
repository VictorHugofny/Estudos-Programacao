let pessoa = {
    nome:'hugo',
    idade:'22'
}

//descontruir objetos

const {nome, idade:idadeNovo} = pessoa;
console.log(nome, idadeNovo)

//descontruir array
let nomes = ['hugo','victor','teste']

const {0:hugo, 1:ceret} = nomes
console.log(ceret)

let [primeiroNome] = nomes;
console.log(primeiroNome)