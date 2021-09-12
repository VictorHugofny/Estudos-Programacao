const pessoa = {
    nome: 'hugo',
    idade: 2,
    peso: 13
}

console.log(Object.keys(pessoa))
console.log(Object.values(pessoa))
console.log(Object.entries(pessoa))

Object.entries(pessoa).forEach(e => {
    console.log(e[0], ":", e[1])
})

Object.defineProperty(pessoa, 'dataNascimento',{
    enumerable: true,
    writable: false,
    value:'01/01/199'
})
pessoa.dataNascimento = "teste"
console.log(pessoa.dataNascimento)
console.log(Object.keys(pessoa))

// object.assign (ECMAS 2015)

const dest = {a:1}
const o1 = {b : 2}
const o2 = {c:3, a:4}

const obj = Object.assign(dest,o1,o2) //pega todos os atributos dos objetos e junta tudo
console.log(obj)

Object.freeze(obj)
obj.c = 1234
console.log(obj)