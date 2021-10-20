//Escreva uma função que receba dois parâmetros. O primeiro parâmetro é o elemento que repetirá, enquanto que o segundo será o número de vezes que haverá repetição. Um array será retornado.
function repetir (valor,QtRepetir){
var resultado = []
    for (i=0; i < QtRepetir; i++){
        resultado[i] = valor;
    }
    return resultado
}
console.log(repetir(7,5))