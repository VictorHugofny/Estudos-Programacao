const notas = [7.7, 6.5,5.2,8.9,3,5,4]

//sem callback
const notasBaixas = []
for (let i in notas){
    if (notas[i] < 7){
        notasBaixas.push(notas[i])
    }
}

console.log(notasBaixas, "notas menores que 7")

//Com callback
const notasBaixas2 = notas.filter(function(nota){ 
    return nota < 7
})
console.log(notasBaixas2, "notas menores que 7 com callback")

const notasBaixas3 = notas.filter(nota => nota < 7)
console.log(notasBaixas3, "notas menores que 7 com callback2")

const notasmenorque7 = nota => nota < 7
const notasBaixas4 = notas.filter(notasmenorque7)
console.log(notasBaixas4, "notas menores que 7 com callback3")