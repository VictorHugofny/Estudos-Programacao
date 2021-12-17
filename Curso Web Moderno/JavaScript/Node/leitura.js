const fs = require('fs')

//sincrona
const caminho = __dirname + '/arquivo.json'

//sincrono...
const conteudo = fs.readFileSync(caminho,'utf-8') //ler o arquivo

//assincrona...
fs.readFile(caminho,'utf-8',(err, conteudo) =>{
   const config = JSON.parse(conteudo)
   console.log(`${config.db.host}:${config.db.port}`) 
})

//ja puxa como objeto direto
const config = require ('./arquivo.json')
console.log(config.db)

fs.readdir(__dirname,(err,arquivos)=>{
   console.log('conteudo pasta')
   console.log(arquivos)
})