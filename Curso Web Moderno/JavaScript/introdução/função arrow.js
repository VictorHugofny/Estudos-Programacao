//armazanendo uma função em uma variavel

const imprimirSoma = function(a,b){
console.log(a+b)
}
imprimirSoma(2,3);

//armazenando uma função arrow em uma variavel

const soma =(a,b) => {
    return a+b;
}

console.log(soma(2,3))

//retorno implicito
const diminuir = (a,b) => a-b
console.log(diminuir(2,3))

//diminuindo a função
const imprimir2 = a =>console.log(a);
imprimir2("legal")