let voceComprouProdutos = new Promise(function (resolve,reject){ //resolução e rejeição
    setTimeout( function(){
        let produtos = ['camisa','sapato','calça']
        resolve(produtos)
    },3000) 
})

//exemplo de uso
// if () { resolve }
//else () { reject }

voceComprouProdutos.then(function(products){ //then espera a promessa ser resolvida
    console.log(products)
}).catch(function(error){ //caso entre no reject
    console.log(error)
})