const todos = [
    {text:'lavar a louça', done:false},
    {text:'apanhar o lixo', done:true},
    {text:'dobrar as roupas', done:true},
]


const concluida = todos.filter((todo) => todo.done)

console.log(concluida)

const anything = () => {
    return "hello world"
} 

const anything1 = () => 'hellow world2'

console.log(anything() + ' ' + anything1())