class avo {
    constructor(sobrenome){
        this.sobrenome = sobrenome
    }
}
class pai extends avo {
    constructor(sobrenome,profissao='professor'){   
        super(sobrenome)
        this.profissao = profissao
    }
}

class filho extends pai{
    constructor(){
        super('Silva')
    }
}

const filho1 = new filho
console.log(filho1)