function criarproduto(nome,preco){
    return{
        nome,
        preco,
        desconto:0.1,
    }
}
console.log(criarproduto('notebook',2199.9))
sabonete = new criarproduto('computador',1)
console.log(sabonete)