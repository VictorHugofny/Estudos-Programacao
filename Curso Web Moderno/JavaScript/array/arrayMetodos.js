const pilotos = ['rubins','alonso','raikone','massa']
pilotos.pop() //remove ultimo elemento
console.log(pilotos)

pilotos.push('Verstappen') //adiciona um elemento na ultima posição
console.log(pilotos)

pilotos.shift()//remove o primeiro elemento
console.log(pilotos)

pilotos.unshift('Hamilton') // adiciona como primeiro elemento
console.log(pilotos)

//splice pode adicionar e remover elementos
//adicionar
pilotos.splice(2,0,'Bottas','massa')//primeiro valor é o indice, segundo é remover quantidade
console.log(pilotos)
pilotos.splice(3,1) //removeu um elemento no indice 3
console.log(pilotos)

const algunsPiloto = pilotos.slice(2) //novo array cm elementos a partir do indice
console.log(algunsPiloto)

const algunspiloto2 = pilotos.slice(1,4) //indice 1 até o 4
console.log(algunspiloto2)