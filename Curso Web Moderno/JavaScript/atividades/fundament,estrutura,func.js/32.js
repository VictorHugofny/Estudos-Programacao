Array.prototype.calcular = function(){
    var contador = 0;
    var somanota = 0;

    for (i=0;i<= this.length-1;i++){
        contador++
        somanota+= this[i]
    }
    var calculo = somanota / contador
    return calculo
    
}
notas = [5,4,6,35,5]
console.log(notas.calcular())