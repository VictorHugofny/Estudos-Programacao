console.log(Math.ceil(6.1)) // ARREDONDAR

const obj1 = {}
obj1.nome = 'Bola'
obj1['nome'] = 'bola2' // MESMA FORMA DE CRIAR NA LINHA ANTERIOR
console.log(obj1.nome)

function Obj (nome){
    this.nome = nome //criar atributo publico
}
const obj2 = new Obj("Cadeira")
const obj3 = new Obj('Mesa')
console.log(obj2.nome)
console.log(obj3.nome)
// USAR '.' para atribuir valores em itens e Utilizar tbm