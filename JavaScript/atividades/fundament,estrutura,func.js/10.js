verificarInt = (a) => {
    teste = false;
    if(a % 3 == 0){
        teste = true;
    }
    return teste;
}
console.log(verificarInt(6))