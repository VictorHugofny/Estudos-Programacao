const a = 1
const b = 2
const c = 3

const obj1 = { a:a,b:b,c:c}
const obj2 = {a, b, c}

console.log(obj1,obj2)

const nomeatt = 'nota'
const valorattr = 7.87
const obj3 = {}
obj3[nomeatt] = valorattr
console.log(obj3)

const obj4 = {[nomeatt]: valorattr}
console.log(obj4)

const obj5 = {
    funcao: function(){
        //..
    },
    funcao2(){
        // nova forma de criar função
    }
}
console.log(obj5)