//Crie uma função que receba dois números e retorne se o primeiro é maior ou igual ao segundo.
function comparar(val1,val2){
    if (val1 == val2){
        resultado = "valores iguais"
    }
    else if (val1 >= val2){
        resultado = "Primeiro valor é maior"
    }
    else{
        resultado = "Segundo valor é maior"
    }
return resultado
}

console.log(comparar(5,10))