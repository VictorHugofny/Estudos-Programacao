Number.prototype.entre = function(inicio,fim) {
    return this >= inicio && this <= fim;
}

const imprimirResultado = function(nota){
    if (nota.entre(9,10)) {
        console.log("quadro de honra")
    } else if(nota.entre(7,8.99)){
        console.log("aprovado")
    } else if(nota.entre(4, 6.99)) {
        console.log("recuperação")
    } else if (nota.entre(0,3.99)){
        console.log("Reprovado")
    } else{
        console.log("nota invalida")
    }
}

imprimirResultado(10);
imprimirResultado(8);
imprimirResultado(6.55);
imprimirResultado(2.3);
imprimirResultado(-1.3);