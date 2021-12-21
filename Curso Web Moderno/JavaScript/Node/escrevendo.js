const fs = require ('fs')

const produto = {
    nome: 'celular',
    preco: 13232,
    desconto: 0.15
}

fs.writeFile(__dirname+'/arquivo.json',JSON.stringify(produto),err =>{
    console.log(err || 'Arquivo Salvo')
})