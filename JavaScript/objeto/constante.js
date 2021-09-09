
const pessoa = {nome:'hugo'} //sempre vai apontar pra um endereço da memoria
pessoa.nome = 'Victor'//não modificou a constante pessoa continua no mesmo endereço
console.log(pessoa)

// pessoa = {nome:'ana'} (vai dar erro por ser uma constante não pode ir para outro endereço)

Object.freeze(pessoa) //congelar objeto, ele não pode ser modificado

pessoa.nome = 'maria'
pessoa.end ='rua abc'
delete pessoa.nome

console.log(pessoa)
console.log(pessoa.nome)