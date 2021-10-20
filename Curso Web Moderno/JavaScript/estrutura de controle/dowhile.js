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

// ele executara a primeira vez e dps vai entrar no while 

do {
    opcao = getInteiroAleatorioEntre(-1,10)
    console.log("Opção escolida foi "  +  opcao)
} while (opcao != -1)

console.log('Até a proxima!')