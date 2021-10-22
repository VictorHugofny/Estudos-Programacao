<template>
<div :class = "{'cliente': !insPremium, 'cliente-premium': insPremium}">
  <h4> Nome: {{cliente.nome}} </h4>
  <p>Email: {{cliente.email | processaEmail}} </p>
  <p v-if = "showIdade == true">Idade: {{cliente.idade}} </p>
  <p v-else> Idade escondida </p>
  <button @click="mudarCor($event)" > MUDAR COR </button>
  <button @click="emitirEventoDeletar"> DELETAR </button>
  <h4>ID Especial = {{idEspecial}} </h4>
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
        },
        emitirEventoDeletar: function(){
        console.log("teste")
        this.$emit("Delete",{idcliente: this.cliente.id, component : this})
    },
        testar: function(){
            console.log("testandooo")
            alert("alerta")
        }
    },
    filters: {
        processaEmail: function(value){
            return "-" + value.toUpperCase()
        }
    },
    computed: {
        idEspecial : function(){
            return (this.cliente.email + this.cliente.nome + this.cliente.id).toUpperCase();
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
    max-width: 800px;
    border: aqua solid 3px;
    height: 400px;
    padding-left: 2%;
    margin-top: 2%;
}

#nome{
    color: rgb(150, 251, 251);
}
</style>