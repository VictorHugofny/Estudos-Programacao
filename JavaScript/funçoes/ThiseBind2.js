function pessoa(){
    this.idade = 0;
    const self = this; //criando uma constante para o this não variar

    setInterval(function(){
        this.idade++ // usar o self aqui no lugar do this...
        console.log(this.idade)
    }.bind(this),1000) //tempo para reacontecer função
}

new pessoa //instanciando o objeto

