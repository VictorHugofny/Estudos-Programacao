//importando express
const express = require('express');

const server = express();

//query params = ?nome=nodejs
//route params = /curso/teste
// request body = {nome: 'teste', tipo: 'testando'}

//CRUD, Create, Read, Update, Delete


const cursos = ['Node JS', 'Javascript', 'React Native'];

//listando todos os cursos
server.get('/cursos',(req, res)=>{
    return res.json(cursos);
})
//localhost:3000/curso
//dados recebido da requisição
//dados enviados como resposta
server.get('/cursos/:index',(req, res)=>{
    const index = req.params.index;
    const nome = req.query.nome;
    return res.json(cursos[index])
})

server.post('/cursos',(req, res)=>{
    //const name = req.body.name;
    const {name} = req.body
    cursos.push(name)
    return res.json(cursos)
});

server.listen(3000);