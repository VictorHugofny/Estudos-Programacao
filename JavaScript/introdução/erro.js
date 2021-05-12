function tratarErro(erro){
    throw 10;
}

function imprimirNomeGritado(obj){
    try{
    console.log(obj.name.toUpperCase()+'!!!')
    }catch(e){
        tratarErro(e)
        console.log('erro');
    } finally{
        console.log('final')
    }
}

const obj = { name:'roberto'}
imprimirNomeGritado(obj)