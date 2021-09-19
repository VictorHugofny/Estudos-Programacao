function mult (val1,val2){
var resultado = 0

    if (val1 >= 0 && val2 >= 0){
        for (i = 1; i < val2; i++){
        val1 += val2 
        }
    }
    return val1
}
console.log(mult(5,5))