 class Lancamento {
     constructor(nome = 'Generico',valor = 0){
         this.nome = nome
         this.valor = valor
     }
 }
 class CicloFinanceiro {
     constructor(mes,ano){
         this.mes=mes
         this.ano = ano
         this.lancamentos = []
     }

     addLancamentos(...lancamentos){
         lancamentos.forEach(l => this.lancamentos.push(l))
     }
     sumario(){
         let valorconsolidado = 0
         this.lancamentos.forEach(l=>{
             valorconsolidado+= l.valor
         })
         return valorconsolidado
     }
 }

 const salario = new Lancamento('salario',45000)
 const contadeluz = new Lancamento('salario',-220)

 const conta = new CicloFinanceiro(6,2018)
 conta.addLancamentos(salario,contadeluz)
 console.log(conta.sumario())