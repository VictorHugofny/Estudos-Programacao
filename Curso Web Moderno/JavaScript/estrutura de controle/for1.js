let contador = 1;

while (contador <= 10){
    contador++; // ou   contador = contador + 1
    console.log("contador " + contador);
}

for(let i = 1; i <= 10; i++){
    console.log(`i = ${i}`);
}

const notas = [6,5,4,3,2,7]

for(let i = 0; i<notas.length; i++){
    console.log(`nota = ${notas[i]}`)
}