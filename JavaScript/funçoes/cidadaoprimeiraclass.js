//função em jss é fisrt class object 
//higher-order function

//criar de forma literal
function fun1(){
    console.log("teste");
}

//armazenar em uma variavel
const fun2 = function(){
    console.log("teste2");
}
// Armazenar em um array
const array = [function(a,b){return a+b}];
const array1 = [fun1,fun2];

console.log(array[0](2,3))

//armazenar em um atributo de objeto
const obj = {}
obj.falar = function(){
    return "opa"
}
console.log(obj.falar())

// Passar função como parametro
function run(fun){
    fun()
}
run(function(){
    console.log("executando")
})

// Uma função pode retornar/conter um função 
function soma(a,b){
    return function(c){
        console.log(a + b + c)
    }
    }
soma(2,3)(4)

const cincomais = soma(2,3)
cincomais(4)

//nova forma de criar função
