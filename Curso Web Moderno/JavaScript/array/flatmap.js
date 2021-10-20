const escola = [
    {nome:'Turma aluno1', 
    alunos:[{
        nome:'hugo',nota:9
    },{
        nome:'victorh',nota:10
    }]
},{
    nome:'Turma M2',
    alunos: [{
        nome:'Laila',
        nota: 8
    },{
        nome:'Samay',
        nota:7.5
    }]
}    
]

const getnota = aluno => aluno.nota //função pegar nota
const getNotasDaTurma = turma => turma.alunos.map(getnota) //função pegar o aluno da turma

const notas1 = escola.map(getNotasDaTurma)
console.log(notas1)

Array.prototype.flatMap = function(callback){ //concatenar o map
    return Array.prototype.concat.apply([],this.map(callback))
}

const notas2 = escola.flatMap(getNotasDaTurma)
console.log(notas2)