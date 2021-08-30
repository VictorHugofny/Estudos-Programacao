const imprimir = function (x,y){
    return x, y;
}
const soma = (x,y) => x + y

const mult = (x,y) => x*y

const div = (x,y) => x/y

const sub = (x,y) => x-y

const imprimirResultado = function(a,b,operacao = imprimir){
    console.log(operacao(a,b))
}

imprimirResultado(3,4)
imprimirResultado(3,4, soma)
imprimirResultado(3,4, mult)
imprimirResultado(3,4, sub)
imprimirResultado(3,4, div)