//PAR NOME/VALOR
const saudacao = "opa"

function exec(){
    const saudacao = "falaa"
    return saudacao
}
exec()
console.log(saudacao)
console.log(exec())
//objetos são grupos aninhados de pares nome/valor

const cliente = {
    nome:'Pedro',
    idade: 32,
    peso: 90,
    endereço:{
        logradouro: "Rua muito legal",
        numero:123
    }
}
console.log(cliente)