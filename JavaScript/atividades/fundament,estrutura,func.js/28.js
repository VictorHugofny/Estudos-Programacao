numeros = [1,2,3,4,5,6,7,8,9,10]
pares = []
impar = []

numeros.forEach(e => {
    if(e % 2 == 0){
        pares.push(e)
    }else{
        impar.push(e) 
    }
});
console.log("Pares -")
for (i in pares){
    console.log(pares[i])
}
console.log("Impar -")
for (i in impar){
    console.log(impar[i])
}

