for (var i = 0; i<10 ; i++){
    console.log(i);
}

console.log('i=',i)

//array
const funcs = []

for(var i =0; i< 10; i++){
    funcs.push(function(){
console.log(i)
    })
}

funcs[2]()
funcs[8]()

//array
const funcs = []

for(let i =0; i< 10; i++){
    funcs.push(function(){
console.log(i)
    })
}

funcs[2]()
funcs[8]()