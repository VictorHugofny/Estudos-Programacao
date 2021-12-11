//promise

const myPromisse = () => new Promise((resolve,reject) =>{
    setTimeout(()=>{
        resolve('ok')
    },2000)
})

//myPromisse().then((response)=>{ // se for resolvido
//    console.log(response)})

// const exec = async () =>{}

async function exec(){ //esperar
    await myPromisse() //até a promessa ser feita
    console.log('primeira vez')

    await myPromisse() //até a promessa ser feita
    console.log('segunda vez')
}

exec()