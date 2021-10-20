const alunos = [
    {nome:'hugo', nota: 9.4},
    {nome: 'victor',nota:8.5}
]

//imperativo
let total1 = 0

for(let i=0; i< alunos.length; i++){
    total1 += alunos[i].nota
}
console.log(total1 / alunos.length)

//declarativo - melhor para reuso
const getnota = aluno => aluno.nota //função para pegar as notas
const soma = (total,atual) => total + atual //função para somar as notas
const total2 = alunos.map(getnota).reduce(soma) //criando um novo vetor
console.log(total2/alunos.length)