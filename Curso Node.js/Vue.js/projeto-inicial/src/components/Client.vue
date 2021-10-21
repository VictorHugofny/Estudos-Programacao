<template>
<div :class = "{'cliente': !insPremium, 'cliente-premium': insPremium}">
  <h4> Nome: {{cliente.nome}} </h4>
  <hr>
  <p>Email: {{cliente.email}} </p>
  <hr>
  <p v-if = "showIdade == true">Idade: {{cliente.idade}} </p>
  <p v-else> Idade escondida </p>
  <button @click="mudarCor($event)" > MUDAR COR </button>
</div>
</template>

<script>
export default {
    data(){
        return {
            insPremium : false
        }
    },
    props:{
        cliente: Object,
        showIdade: Boolean
    },
    methods:{
        mudarCor: function($event){
            console.log($event)
            this.insPremium = !this.insPremium
        }
    }
}
</script>

<style>
.cliente{
    color: rgb(0, 0, 0);
    background-color: rgb(221, 219, 219);
    max-width: 600px;
    border: aqua solid 3px;
    height: 200px;
    padding-left: 2%;
    margin-top: 2%;
}

.cliente-premium{
    color: rgb(255, 230, 0);
    background-color: rgb(0, 0, 0);
    max-width: 600px;
    border: aqua solid 3px;
    height: 200px;
    padding-left: 2%;
    margin-top: 2%;
}

#nome{
    color: rgb(150, 251, 251);
}
</style>