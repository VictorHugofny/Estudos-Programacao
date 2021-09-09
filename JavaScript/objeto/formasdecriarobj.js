//usando a notação literal
const obj1 = {}
console.log(obj1)

//object em js
console.log(typeof new Object)
const obj2 = new Object
console.log(obj2)

//funçoes contrutoras
function produto (nome, preco, desc){
    this.nome=nome //torna global - publico
    this.GetPrecoComDesconto = () =>{
        return preco * (1 - desc)
    }
}
const p1 = new produto('caneta',7.99,0.15)
const p2 = new produto('notebook',237.99,0.25)

console.log(p1.GetPrecoComDesconto(),p2.GetPrecoComDesconto())

//Função factory
function criarfuncionario(nome,salariobase,faltas){
    return {
        nome,
        salariobase,
        faltas,
        getSalario(){
            return(salariobase/30) * (30 - faltas)
        }
    }
}

const f1 = criarfuncionario('Hugo',7980,4)
const f2 = criarfuncionario('Victor',11400,1)

console.log(f1.getSalario())
console.log(f2.getSalario())

//Object.create
const filha = Object.create(null)
filha.nome  = 'Ana'

console.log(filha)

 //Uma funçao famosa que retorna um objeto
 const fromJSON = JSON.parse('{"info": "Sou um json"')
 console.log(fromJSON.info)