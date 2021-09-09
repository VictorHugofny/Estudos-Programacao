const sequencia  = {
    _valor: 1, //convenção escrita pra avisar para nn modificar
    get valor(){ //pegar valor
        return this._valor++
    },
    set valor(valor){ //setar valor definir 
        if (valor > this._valor){
            this._valor = valor
        }
    }

}

console.log(sequencia.valor, sequencia.valor)
sequencia.valor = 1000
console.log(sequencia.valor, sequencia.valor)
sequencia.valor = 900
console.log(sequencia.valor, sequencia.valor)