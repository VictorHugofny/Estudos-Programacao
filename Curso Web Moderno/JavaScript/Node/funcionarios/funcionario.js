const url = 'http://files.cod3r.com.br/curso-js/funcionarios.json'
const axios = require('axios')

const chineses = f => f.pais === 'China' //comparando se Pais é igual
const mulheres = f => f.genero === 'F' //comparando
const menorSalario = (funcionario, funcAtual) =>{
    return funcionario.salario < funcAtual.salario ? funcionario : funcAtual // pegar o menor salario
}

axios.get(url).then(response =>{
    const funcionarios = response.data
    const funcionario = funcionarios.filter(chineses).filter(mulheres).reduce(menorSalario)
    console.log(funcionario)
})

console.log('teste')