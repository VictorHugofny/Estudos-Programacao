{
    {
        {
            {
            var sera = "sera??"
            }
        }
    }
}
console.log(sera)

function teste(){
    var local = 123
    console.log(local)

}
teste()
console.log(local) // não funciona pq a variavel esta dentro da função

var numero = 1
{
    var numero = 2
    console.log("dentro =",numero)
}
console.log("fora",numero)