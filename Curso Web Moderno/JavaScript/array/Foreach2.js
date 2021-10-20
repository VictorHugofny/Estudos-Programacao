Array.prototype.forEach2 =  function(callback){
    for (let i = 0; i<this.length; i++){
        callback(this[i],i,this)
    }
}

const aprovados = ['Hugo','Victor','Laila','Samay']

aprovados.forEach2(function(nome,indice,array){ //foreach percorre o vetor, passando pegando o nome e indice
    console.log(indice+1 , nome,array)
})
