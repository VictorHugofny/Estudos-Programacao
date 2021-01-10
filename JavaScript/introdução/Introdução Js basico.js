//STRING

const nome = "hugo"
const template = ` olá  ${nome}`
console.log (template) 

//boleanos
// || = OU && = E

// ARRAY
var valores = [1, "hugo", 2, 3]

console.log(valores[1])
valores[4] = "teste"
console.log(valores)
console.log(valores.length) // tamanho
valores.push ({id: 3}, false, null, hugo = 2) // push colocar valores dentro do array
console.log(valores)
console.log (valores.pop()) // pop remove o ultimo elemento do array e imprimi
console.log(valores)
delete valores[0] // deletar elemento de acordo cm o indice

console.log(typeof valores)

//OBJETO
// OBJETO PODE SER COLOCADO DENTRO DE OUTRO OBJETO
const teste = { parte: 2, hugo: 2, obj: {test : 1, carro : "azul"}}
teste.nome = "celular ultra mega"
teste.preço = 5.7
console.log (teste)

// se passar um objeto de uma variavel para outra tipo A = B, se passa o endereço apenas
// se passar um tipo primitivo, exemplo inteiro, se faz uma copia do valor para a varivel
// usar NULL para a variavel tipo a = null, limpando o endereço da memoria
// evitar usar UNDEFINED dentro do codigo

testando = {nome : "victor"}
console.log (testando)