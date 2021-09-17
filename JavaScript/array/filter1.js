//Filtrar um array, criar um subarray
const produtos = [
    {nome:'Notebook', preco: 2499, fragil: true},
    {nome:'Ipad', preco: 4100, fragil: true},
    {nome:'Copo de plastico', preco: 12.45, fragil: true},
    {nome:'Copo de Vidro', preco: 5.99, fragil: false}
]

console.log(produtos.filter(function(p){ // p = elementos do array
    return p.preco > 2525 //retorna o vetor completo , se o return for true
    //resultado do return precisa ser verdadeiro ou falso
}))
console.log(produtos.filter(function(p){ // p = elementos do array
    return p.fragil == true //resultado do return precisa ser verdadeiro ou falso
}))

//function caro (produto){
//    return produto.preco >= 500 
//}
const caro = produto => produto.preco >= 500
const fragil = produto => produto.fragil

console.log(produtos.filter(caro).filter(fragil)) 