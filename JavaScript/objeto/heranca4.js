function MeuObjeto(){
    console.log(MeuObjeto.prototype)
}
const obj1 = new MeuObjeto
const obj2 = new MeuObjeto

console.log(obj1.__proto__ === obj2.__proto__) //aponta para a função que criou o objeto
console.log(MeuObjeto.prototype === obj1.__proto__)

MeuObjeto.prototype.nome = 'anonimo'

MeuObjeto.prototype.falar = function(){
    console.log(`bom dia meu nome é ${this.nome}`)
}

obj1.falar()
obj2.nome = 'rafael'
obj2.falar()

const obj3 = {}
obj3.__proto__ = MeuObjeto.prototype
obj3.nome ="teste"
obj3.falar()

//resumindo
console.log((new MeuObjeto).__proto__ === MeuObjeto.prototype)
console.log(MeuObjeto.__proto__ === Function.prototype)
console.log(Function.prototype.__proto__ === Object.prototype)
console.log(Object.prototype.__proto__)