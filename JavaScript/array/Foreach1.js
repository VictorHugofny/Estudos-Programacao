const aprovados = ['Hugo','Victor','Laila','Samay']

aprovados.forEach(function(nome,indice){ //foreach percorre o vetor, passando pegando o nome e indice
    console.log(indice+1 , nome)
})

aprovados.forEach(nome => console.log(nome))

const exibiraprovados = aprovado => console.log(aprovado)
aprovados.forEach(exibiraprovados)

aprovados.forEach(function(nome,indice,array){ //parametros 1 - nome, 2 - indice, 3 - array
    console.log(indice+1 , nome, array)
})