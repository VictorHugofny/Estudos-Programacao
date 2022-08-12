
function acao(){
    document.write("Executando... <br>")
}

//ele roda em uma intervalo de tempo
setInterval(acao, 1000)

setInterval(()=>{
    document.write('teste <br>');
}, 2000)

//apos esse tempo de 3 segundos vai chamar a função
setTimeout(acao, 3000)