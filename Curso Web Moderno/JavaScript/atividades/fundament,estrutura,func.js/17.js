calcularsalario = (plano,salario) =>{
salariototal = 0;

var planos = {A: 10, B: 20, C: 30}
aux = salario / 100 * planos[plano]
salariototal = aux + salario
return salariototal}

console.log(calcularsalario("A",1500))