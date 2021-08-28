var a = 1;

while(a <= 5){
    console.log("teste" + a);
    a = a + 1;
}

function getInteiroAleatorioEntre(min, max){
    const valor = Math.random() * (max - min) + min
    return Math.floor(valor)
}

let opcao = 0;

while (opcao != -1){
    opcao = getInteiroAleatorioEntre(-1,10)
    console.log("Opção escolida foi "  +  opcao)
}

console.log('Até a proxima!')