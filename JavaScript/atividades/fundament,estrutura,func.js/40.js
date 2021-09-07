//Faça uma função que receba como parâmetro um vetor de notas e mostre os conceitos de cada uma de
//modo que de 0,0 a 4,9 seja atribuído o conceito D, de 5,0 a 6,9 seja atribuído o conceito C, de 7,0 a 8,9 o
//conceito B e de 9,0 a 10,0 o conceito A

conceito = (vetor) =>{
    var tipo = []

    for(i in vetor){
        var nota = vetor[i]

        if (nota > 0 && nota < 5){
            tipo[i] = "D"
       }else if (nota >= 5 && nota < 7 ){
            tipo[i]  = "C"
       }else if (nota >= 7 && nota < 9){
            tipo[i]  = "B"
       }else if (nota >= 9 && nota <=10){
            tipo[i]  = "A"
       }else{
           tipo[i]  = "tase"
       } 
    }
    return tipo
}

console.log(conceito([5,6,7,8,9]))