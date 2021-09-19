// A ideia do reduce, é produzir um único valor a partir de um array

const numeros = [1, 2, 3, 4];
const somar = (acumulado, proximovalor) => acumulado + proximovalor;
const total = numeros.reduce(somar);
console.log(total); // 10