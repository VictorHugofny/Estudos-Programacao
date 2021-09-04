function triangulo(a,b,c){
    if (a == b && a == c){
        console.log("equilatero")
    }
    else if(a == b || b == c || a == c){
        console.log("isosceles")
    }
    else{
        console.log("escaleno")
    }
}
triangulo(5,4,3)