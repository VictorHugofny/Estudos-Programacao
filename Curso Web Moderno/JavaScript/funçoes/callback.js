const fabricantes =["mercedes","audi","gol","bmw"]

function imprimir (nome,indice){
    console.log(`${indice +1}- ${nome}`)
}

//cria um for para cada elemento do vetor
fabricantes.forEach(imprimir) //usar a função em cada elemento do array

fabricantes.forEach(fabricante => console.log(fabricante))