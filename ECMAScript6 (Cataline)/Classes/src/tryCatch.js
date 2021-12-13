//promise
const myPromisse = () => new Promise((resolve,reject) =>{
    setTimeout(()=>{
        reject('erro')
    },2000)
})

//myPromisse().then((response)=>{ // se for resolvido
//    console.log(response)})

// const exec = async () =>{ }

async function exec(){ //esperar
    try{
        await myPromisse()
        console.log('primeira vez')
    }catch(error){ // caso não passe pelo primeiro (erro)
        console.log(error)
    } finally {
        console.log('finalizado')
    }
}

exec()