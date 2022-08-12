function convidados(...nomes){
    console.log(nomes);
}

convidados("Victor","Hugo")

function sorteador (...numeros){
    
    const numeroGerado = Math.floor(Math.random() * numeros.length) 
    console.log(numeros[numeroGerado])
}

sorteador(1,24,35,42,45,6)