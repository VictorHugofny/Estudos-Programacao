const filhas = ['Ualeskah','Cibalena']
const filhos = ['Uoxiton','Teste']

const todos = filhas.concat(filhos) //concatena os dois vetores juntando os
console.log(todos)

const todos1 = filhas.concat(filhos, 'fulano') //concatena os dois vetores juntando os
console.log(todos1)

console.log([].concat([1,2],[3,4],5,[[6,5]])) //criando um array com todos os valores passados