function rand([min=0, max=1000]){
    if (min>max)[min,max] = [max,min] // inverter caso o maximo e minimo sejam invertidos
    const valor = Math.random()*(max-min) + min
    return Math.floor(valor)
}

console.log(rand([50,40]))
console.log(rand([992]))
console.log (rand([, 10])) // passa so o segundo valor
console.log (rand([]))