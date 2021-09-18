Array.prototype.filter2 = function(callback){
    const newArray = []
    for (let i =0; i<this.length ; i++){
        if(callback(this[i],i,this)){
            newArray.push(this[i])
        }
    }
    return newArray
}

//Filtrar um array, criar um subarray
const produtos = [
    {nome:'Notebook', preco: 2499, fragil: true},
    {nome:'Ipad', preco: 4100, fragil: true},
    {nome:'Copo de plastico', preco: 12.45, fragil: true},
    {nome:'Copo de Vidro', preco: 5.99, fragil: false}
]
const caro = produto => produto.preco >= 500
const fragil = produto => produto.fragil

console.log(produtos.filter2(caro).filter2(fragil)) 