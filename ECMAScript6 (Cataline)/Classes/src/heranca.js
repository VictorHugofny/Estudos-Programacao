class Veiculo {
    constructor(rodas){
        this.rodas = rodas
    }

    acelerar(){
        console.log('acelerou')
    }
}

class Moto extends Veiculo { //herdando conteudos de veiculo
    constructor(rodas, capacete){
        super(rodas) //new Veiculo(2)
        this.capacete = capacete
    }
    empinar(){
        console.log(`empinou com ${this.rodas} rodas`)
    }
    taUsandoCapacete(){
        console.log(this.capacete)
    }
}

const bross = new Moto(2,false)

bross.taUsandoCapacete()