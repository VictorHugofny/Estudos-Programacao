//transformar um array em outro novo, transformar os elementos mantendo o mesmo tamanho do vetor
const nums = [1,2,3,4,5]
//for com propósito
let = resultado = nums.map(function(e){
    return e*2 //necessario retornar sempre
})
console.log(resultado)

const soma10 = e => e + 10 //funçao arrow - retorna (e) + 10 - parametro (e)
const triplo = e => e * 3
const paradinheiro = e => 'R$' + parseFloat(e).toFixed(2) //to fixed limita casas decimais

resultado = nums.map(soma10).map(triplo).map(paradinheiro) //junta tds arrays em um novo
console.log(resultado)