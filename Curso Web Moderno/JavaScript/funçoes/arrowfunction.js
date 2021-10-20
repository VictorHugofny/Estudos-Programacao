let dobro = function(a){
    return 2 * a;
}
//função arrow
dobro = (a) =>{
    return 2 * a
}

dobro = a => 2 * a //return implicito
console.log(dobro(Math.PI))

let ola = function () {
    return 'ola'
}
// refazendo com a função arrow

ola = () => 'ola'
ola = _ => 'ola' //possui um parametro
console.log(ola())