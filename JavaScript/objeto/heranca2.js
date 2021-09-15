    //cadeia de prototipos (protype chain)

    const avo = { attr1: 'A'}

    const pai = {__proto__: avo, attr2:'B', attr3: '3'}

    const filho = {__proto__: pai, attr3:'C'}

    console.log(filho.attr1) //ele buscou o atributo na herança do objeto anterior
    console.log(filho.attr0) // não existi na herança esse atributo
    console.log(filho.attr2, filho.attr3)

const carro = {
    velAtual: 0,
    velMax: 200,
    acelerarmax(delta){
        if (this.velAtual + delta <= this.velMax ){
            this.velAtual += delta
        } else{
            this.velAtual = this.velMax
        }
    },
    status(){
        return `${this.velAtual} "KM/h de" ${this.velMax} "Km/h"`
    }
}
const ferrari = {
    modelo : 'f40',
    velMax: 324 //sobreescrever o valor da variavel - shadowing
}
const volvo = {
    modelo:'V40',
    status(){
        return `${this.modelo} : ${super.status()} `
    }
}
Object.setPrototypeOf(ferrari, carro) //estabeceu a relação de herança entre carro e ferrari
Object.setPrototypeOf(volvo, carro)
console.log(ferrari)
ferrari.acelerarmax(300)
console.log(ferrari.status())
volvo.acelerarmax(500)
console.log(volvo.status())