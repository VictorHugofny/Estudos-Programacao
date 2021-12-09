const numbers = [1,2,3,4,5]

const [first, second, ...rest] = numbers

console.log(rest)

const sum = (...params) =>{
    return params.reduce((total, next) => total + next)
}

console.log(sum(5,5,10,10))

//spred

const number1 = [1,2,3,4,5]
const number2 = [6,7,8]

const numeros = [...number1, ...number2]

console.log(numeros)