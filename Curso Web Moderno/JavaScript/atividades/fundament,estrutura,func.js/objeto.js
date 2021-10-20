class pessoa {
    constructor(nome){
        this.nome = nome;
        this["🎃"] = "emoji"
    }
}
objeto = new pessoa('seila')
console.log(objeto["🎃"])