const contadorA = require('./instanciaUnica')
const contadorB = require('./instanciaUnica')

const contadorC = require('./instanciaNova')() //retorna uma função factory
const contadorD = require('./instanciaNova')()

contadorA.inc()
contadorB.inc()
console.log(contadorB.valor)

contadorC.inc()
contadorD.inc()
console.log(contadorD.valor)