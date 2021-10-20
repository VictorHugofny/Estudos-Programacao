 const alunos = [
     {nome:'hugo',nota:7.3, bolsista: false},
     {nome:'victor',nota:9.2,bolsista: true},
     {nome:'teste',nota:8.2,bolsista: true}
 ]

const resultado1 = alunos.map(a => a.nota) //pegar todas as notas para o novo vetor
console.log('Notas :',resultado1)

//pegar os dois ultimos elementos do vetor e vai fazendo loop reduzindo e somando cm os proximos
const resultado = alunos.map(a => a.nota).reduce(function(acumulador,atual){ 
     console.log(acumulador,atual)
     return acumulador + atual
 },10) //criando um valor inicial no reduce
 console.log(resultado)