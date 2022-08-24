//importando express
const express = require('express');

const server = express();

//localhost:3000/curso
//dados recebido da requisição
//dados enviados como resposta
server.get('/curso',(req, res)=>{
    return res.json({curso:'json'})
})

server.listen(3000);