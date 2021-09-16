console.log(typeof Array, typeof new Array, typeof [])

let aprovados = new Array('Bia','Carlos','Ana')
console.log(aprovados)

aprovados = ['Bia','Carlos','Ana']
console.log(aprovados[0])
console.log(aprovados[1])
console.log(aprovados[2])

aprovados[3] = 'paulo'
aprovados.push('HUGO') //adicionar novos elementos no array
console.log(aprovados.length)

aprovados[9] = 'teste'
console.log(aprovados.length)
console.log(aprovados[8] === undefined)

console.log(aprovados)
aprovados.sort() //função para ordenar os valores do vetor
console.log(aprovados)

 delete aprovados[1]
 console.log(aprovados)

 aprovados = ['bia','carlos','ana']
 aprovados.splice(1,1) //excluir um elemento
 aprovados.splice(1,2,'hugo','victor') //adicionar/substituir elementos
 console.log(aprovados)
