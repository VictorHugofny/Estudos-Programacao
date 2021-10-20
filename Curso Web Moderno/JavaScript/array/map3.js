Array.prototype.map2 = function(callback){ //Criando a função map
        const newArray = []
        for (let i = 0; i<this.length; i++){
         newArray.push(callback(this[i],i,this))
    }
    return newArray
}

const carrinho = [
    '{"nome": "borracha", "preco": 3.45}',
    '{"nome": "Caderno", "preco": 5.45}',
    '{"nome": "Kit de Lapis", "preco": 6.77}',
    '{"nome": "Caneta", "preco": 8.88}',   
]
//retornar um array apenas os preços
const paraobjeto = json => JSON.parse(json) //transformando o json em objeto
const apenasobjeto = produto => produto.preco //pegando o elemento do objeto

const resultado = carrinho.map2(paraobjeto).map2(apenasobjeto)
console.log(resultado)