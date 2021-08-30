const pessoa ={
    saudacao:'bom dia',
    falar(){ //nova forma de criar função
        console.log(this.saudacao) //para puxar dentro do objeto
    }
}

pessoa.falar();

const falar = pessoa.falar // armazenar dentro da variavel, causa conflito pelo menos nome
falar() //conflito entre paradigmas: funcinal e objeto

const falarDePessoa = pessoa.falar.bind(pessoa); //referencia o objeto junto do atributo
// garantir que ela aponte para o lugar certo e retorne o valor0
falarDePessoa()