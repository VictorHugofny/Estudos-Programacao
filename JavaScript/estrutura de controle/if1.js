function soBoaNoticia(nota){
    if (nota >= 7){
        console.log("aprovado", "sua nota foi", + nota)
    }
    else if(nota >= 3){
        console.log("recuperação", "sua nota foi", + nota)
    }
    else{
        console.log("reprovado", "sua nota foi", + nota)
    }
}

a = 2;
soBoaNoticia(a);

soBoaNoticia();
soBoaNoticia(null);
soBoaNoticia(undefined);
soBoaNoticia("");
soBoaNoticia("  ");
soBoaNoticia(NaN);
soBoaNoticia([]);
soBoaNoticia({});