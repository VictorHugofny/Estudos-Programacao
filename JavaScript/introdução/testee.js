A = [
    [10,2,1],
    [1,5,1],
    [2,3,10],
];

b = [6,-8,6];

n = b.length

x = b;

xk = x
console.log(x)

for(var i = 1; i<4; i++){
    soma = 0;
    for(var j = 1; j< b.length  ; j++){
        if ((i-1) != (j-1)) {
            soma += A[i-1][j-1] * x[j-1];
            console.log(j-1);
        }
    }
    console.log("valor de j", j)
    xk[i-1] = (1/ A[i-1][i-1] * (b[i-1] - soma));
}
console.log("\n XK =", xk);