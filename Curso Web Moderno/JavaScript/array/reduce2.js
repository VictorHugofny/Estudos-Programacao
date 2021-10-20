const alunos = [
    {nome:'hugo',nota:7.3, bolsista: false},
    {nome:'victor',nota:9.2,bolsista: true},
    {nome:'teste',nota:8.2,bolsista: true}
]
//desafio todos os alunos são bolsista
const todosbolsistas = (resultado, bolsista) => resultado && bolsista
console.log(alunos.map(a=>a.bolsista).reduce(todosbolsistas))

// algum aluno é bolsista?
const algumbolsistas = (resultado, bolsista) => resultado || bolsista 
console.log(alunos.map(a=>a.bolsista).reduce(algumbolsistas))
