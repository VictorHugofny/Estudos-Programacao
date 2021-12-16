const fs = require('fs')

//sincrona
const caminho = __dirname + '/arquivo.json'

//sincrono...
const conteudo = fs.readFileSync(caminho,'utf-8') //ler o arquivo

//assincrona...
fs.readFile(caminho,'utf-8',(err, conteudo) =>{
   const config = conteudo 
})

console.log(conteudo)