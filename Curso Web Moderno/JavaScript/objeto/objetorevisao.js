//coleçao dinamica de pares chave/valor

const produto = new Object //instanciando objeto

produto.nome ="cadeira"
produto['marca do produto'] = "Generica"
produto.preco = 220

console.log(produto)

delete produto.preco
delete produto['marca do produto']
console.log(produto)

const carro = {
    modelo: 'Gol',
    Valor: 8900,
    proprietario: {
        nome: 'Hugo',
        idade: 56,
        endereco:{
            logradouro:'Rua ABC',
            numero:123
        }
    },
    condutores: [{
        nome:'victor',
        idade:21
    },{
        nome:'Ana',
        idade: 42
    }],
CalcularValorSeguro: function(){

}}
console.log(carro)
carro.proprietario.endereco.numero = 1000
console.log(carro)
carro['proprietario']['endereco']['logradouro'] = 'av gigante'
console.log(carro)

delete carro.condutores
delete carro.proprietario.endereco
delete carro.CalcularValorSeguro

console.log(carro)
console.log(carro.condutores)
