//Crie uma função que recebe um número (de 1 a 12 e retorne o mês correspondente como uma string. Por
//exemplo, se a entrada for 2, a função deverá retornar "fevereiro", pois este é o 2° mês.

function mes (dia){
    switch (dia){
        case 1:
            data = "Janeiro"
            break
        case 2:
            data = "Fevereiro"
            break
        case 3:
            data = "Março"
            break
        case 4:
            data = "Abril"
            break
            
        case 5:
            data = "Maio"
            break
        case 6:
            data = "Junho"
            break
        case 7:
            data = "Julho"
            break
        case 8:
            data = "Agosto"
            break
        case 9:
            data = "Setembro"
            break
        case 10:
            data = "Outubro"
            break
        case 11:
            data = "Novembro"
            break
        case 12:
            data = "Dezembro"
            break
    }
    return data
}

console.log(mes(2))
console.log(mes(6))
console.log(mes(9))
console.log(mes(11))