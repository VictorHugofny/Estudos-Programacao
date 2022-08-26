//importando express
const { response } = require('express');
const express = require('express');

const server = express();

//avisar que o usuario vai enviar dados
server.use(express.json());

//query params = ?nome=nodejs
//route params = /curso/teste
// request body = {nome: 'teste', tipo: 'testando'}

//CRUD, Create, Read, Update, Delete
const cursos = ['Node JS', 'Javascript', 'React Native'];

//MIDDLEWARE GLOBAL
server.use((req,res,next)=>{
    console.log('REQUISIÇÃO CHAMADA ' + req.url)
    return next();
});

//criando função pra validar se passou o nome no post e put
function checkCurso (req, res, next){
    if(!req.body.name){
        return res.status(400).json({error:'nome obrigatorio'})
    }

    return next();
}

//criando função pra validar se passou o nome no post e put
function checkId (req, res, next){
    const curso = cursos[req.params.index];
    if(!curso){
        return res.status(400).json({error:'id não existe'})
    }

    return next();
}

//listando todos os cursos
server.get('/cursos',(req, res)=>{
    return res.json(cursos);
})
//localhost:3000/curso
//dados recebido da requisição
//dados enviados como resposta

//listando um curso em especifico
server.get('/cursos/:index',checkId,(req, res)=>{
    const index = req.params.index;
    const nome = req.query.nome;
    return res.json(cursos[index])
})

//criando um novo curso
server.post('/cursos',checkCurso, (req, res)=>{
    //const name = req.body.name;
    const {name} = req.body;
    cursos.push(name);

    return res.json(cursos);
});

//atualizando um curso
server.put('/cursos/:index',checkId,checkCurso,(req,res)=>{
    const {index} = req.params;
    const { name } = req.body;
    //atualizando o nome
    cursos[index] = name;

    return res.json(cursos);
})

//delete curso
server.delete('/cursos/:index',checkId,(req,res)=>{
    const {index} = req.params;
    cursos.splice(index,1);
    return res.json(cursos);
})

server.listen(3000);