function Aula (nome,videoID){
    this.nome = nome
    this.videoID = videoID
}

const aula1 = new Aula('bem vindo',123) //cria um novo objeto - apontando pra função
const aula2 = new Aula('Até',456)

console.log(aula1,aula2)

//sumilando o new

function novo(f,...params){
    const obj = {}
    obj.__proto__ = f.prototype
    f.apply(obj,params)
    return obj
}

const aula3 = novo(Aula,'bem vindo hugo', 123)
console.log(aula3)