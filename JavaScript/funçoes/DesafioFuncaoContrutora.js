function pessoa(nome){
    this.nome = nome
    this.falar = function() {
        console.log('meu nome é', this.nome)
    }
}

const p1 = new pessoa('hugo')
p1.falar()

