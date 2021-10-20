//Object.preventExtensions, limita a criação de atributos, pode apenas modificalos

const produto = Object.preventExtensions({
    nome: 'qualquer', preco: 2, tag:'promocao'
})
console.log('Extensivel',Object.isExtensible(produto))

produto.nome ='Borracha'
produto.descricao = 'borrachao escola branca'
delete produto.tag
console.log(produto)

//Object.seal não consegue adicionar novos e excluir os atributos apenas modificar
const pessoa = {nome: 'Juliana', idade: 35}
Object.seal(pessoa)
console.log('selado',Object.isSealed(pessoa))

pessoa.sobrenome = 'teste'
delete pessoa.nome
pessoa.idade = 29
console.log(pessoa)

//Object.freeze = selado + valores contantes