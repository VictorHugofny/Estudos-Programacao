const porta = 3001

const express = require('express')
const app = express()
const bancoDeDados = require('./bancoDados')

app.get('/produtos',(req,res,next)=>{
    res.send(bancoDeDados.getProdutos()) //converter para JSON
})

app.get('/produtos/:id',(req, res,next)=>{
    res.send(bancoDeDados.getProduto(req.params.id))
})
app.post('/produtos',(req,res,next)=>{
    const produto = bancoDeDados.salvarProduto({
        nome: req.body.name,
        preco: req.body.preco
    })
    res.send(produto) // JSON
    
})

app.listen(porta,()=>{
    console.log('Servidor esta executando na porta ' + porta)
})