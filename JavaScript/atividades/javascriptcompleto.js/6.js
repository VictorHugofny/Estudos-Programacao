//Escreva uma função que receba um valor booleano ou numérico. Se o parâmetro fornecido for booleano, o
//retorno da função deverá ser o inverso
function inverter (valor){
    var resultado = "booleano ou números esperado, mas o parâmetro é do tipo string"

    if (typeof(valor) == "boolean"){
        resultado = !valor
    }
    else if (typeof(valor) == "number" ){
        resultado = -valor
    }
    return resultado
}
// console.log(typeof(15))
console.log(inverter(true))