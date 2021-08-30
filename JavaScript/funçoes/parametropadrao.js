// estrategia 1 para gerar valor padrão

function soma1(a,b,c){
    a = a || 1;
    b = b || 1;
    c = c || 1;

    return a + b + c;
}
console.log(soma1());
console.log(soma1(1));
console.log(soma1("teste"));
console.log(soma1(1,2,3));
console.log(soma1(0,0,0));
console.log(soma1(1,4,5,6,7));

//estrategia  2,3,4 para gerar valor padrão
function soma2(a,b,c){
    a = a !== undefined ? a : 1 
    b = 1 in arguments ? b : 1 // ele pega o indice para ver se existe o valor
    c = isNaN(c) ? 1 : c //se c é um numero se não ele pega o valor 1
    return a + b + c
}
console.log(soma2(),soma2(3),soma2(1,2,3),soma2(0,0,0))

//valor padrao do es2015 - melhor metodo para usar

function soma3(a =1, b = 1, c =1){ //define os valores padroes aqui
    return a  + b + c;
}
console.log(soma3(),soma3(3),soma3(1,2,3),soma3(0,0,0))