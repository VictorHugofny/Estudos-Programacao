const numbers = [1,2,3,4,5]
const todos = [
    {text:'lavar a louça', done:false},
    {text:'apanhar o lixo', done:true},
    {text:'dobrar as roupas', done:true},
]
const cars = ['gol','civic','hb20']

// não é uma boa pratica
numbers.forEach(function(number, index){
    numbers[index] = number + 0
})

//criar uma nova array
const newNumbers = numbers.map(function(number){
    return number + 1
})

//reduce redux o vetor a uma variavel
const total = numbers.reduce(function(total, next){
    return total + next
})

const concluida = todos.filter(function(todo){
    return todo.done === true
})

const find = todos.find(function(todo){
    return todo.text === 'dobrar as roupas'
})

const index = todos.findIndex(function(todo){
    return todo.text ==='lavar a louça'
})

const hasFusca = cars.some(function(car){
    return car === 'fusca'
})

console.log(numbers)
console.log(newNumbers)
console.log(total)
console.log(concluida)
console.log(find)
console.log(index)
console.log(hasFusca)