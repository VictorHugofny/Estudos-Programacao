let primeiro = [1,2,3]

let numero = [4,5,10]

//spread operator
//juntar dois arrays
numero.push(...primeiro)
console.log(numero)

let pessoa = {
    nome: "victor",
    idade: 22
}
let novaPessoa = {
    ...pessoa,
    status: "novo",
    cidade: "campo"
}

console.log(novaPessoa)

function novoUsuario(info){
    let data = {
        ...info,
        status: "ativo",
        codigo: "232323"
    }
    return console.log(data)
}

novoUsuario({nome:"hugo"})