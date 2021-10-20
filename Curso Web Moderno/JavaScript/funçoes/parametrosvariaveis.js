function soma(){
    let soma = 0
    for (i in arguments) { //passando os parametros
        soma += arguments[i]; // soma = arguments + soma
    }
    return soma
}

console.log(soma())
console.log(soma(1))
console.log(soma(1, 2, 3, 4))
console.log(soma(1,3,4, "teste"))
console.log(soma("a", "b", "c"))

