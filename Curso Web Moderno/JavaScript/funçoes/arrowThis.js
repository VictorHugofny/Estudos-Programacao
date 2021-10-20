function Pessoa(){
    this.idade = 0

    setInterval(() =>{ //usando arrow o this não varia
        this.idade++
        console.log(this.idade)
    },1000)
}

new Pessoa