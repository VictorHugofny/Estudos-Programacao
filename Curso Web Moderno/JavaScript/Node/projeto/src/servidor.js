const porta = 3001

const express = require('express')
const app = express()

app.get('/produtos',(req,res,next)=>{
    console.log("Middley1..")
    next() // ir para a proxima função
})

app.get('/produtos',(req,res,next)=>{
    res.send({nome:'Notebook',Preco: 123.45}) //converter para JSON
})



app.listen(porta,()=>{
    console.log('Servidor esta executando na porta ' + porta)
})