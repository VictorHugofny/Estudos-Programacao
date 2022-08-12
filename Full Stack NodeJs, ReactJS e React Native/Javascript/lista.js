let lista = ['victor','hugo','carvalho']
let teste

//percorrer um array
lista.map((item)=>{
    item += '2'
    console.log(item)
})
console.log(lista)

//filtrar dados de um array, retornar varios valores
let novo = lista.filter((item => item == "victor"))

console.log(novo)


let numero = [1,2,3,4,5,6]
//reduzir um array

numero = numero.reduce((acumulador, numero, indice, original) =>{
    return acumulador += numero;
})
console.log(numero)


//buscar no array
//usando para fazer buscar, retorna apenas um
let listagem = [5,3,"hugo"]

let busca = listagem.find((item)=>{
    return item === "hugo"
})

 console.log(busca)