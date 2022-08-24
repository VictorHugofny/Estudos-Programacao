//importando express
const express = require('express');

const server = express();

//query params = ?nome=nodejs

//route params = /curso/teste

// request body = {nome: 'teste', tipo: 'testando'}

//localhost:3000/curso
//dados recebido da requisição
//dados enviados como resposta
server.get('/curso/:id',(req, res)=>{
    const id = req.params.id;
    const nome = req.query.nome;
    return res.json({curso:'json ' + id})
})

server.listen(3000);