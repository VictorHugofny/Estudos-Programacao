numeros = [1,2,3,4,5,6,7,8,9,10]
pares = []
impar = []

for (i in numeros){
    if(numeros[i] % 2 == 0){
        pares[i] = numeros[i]
    }else{
        impar[i] = numeros[i]
    }
}
console.log("Pares -")
for (i in pares){
    console.log(pares[i])
}
console.log("Impar -")
for (i in impar){
    console.log(impar[i])
}

