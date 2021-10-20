//Crie uma função que receba um array de produtos e retorne o total das despesas.
despesasTotais = [
    {nome: "Jornal online", categoria: "Informação", preco: 50},
    {nome: "Cinema", categoria: "Entretenimento", preco: 150}
    ] 

    function despesasTotais(itens) {
        var total = 0
        for (let item of itens)
        total += item.preco
        return total
        }
