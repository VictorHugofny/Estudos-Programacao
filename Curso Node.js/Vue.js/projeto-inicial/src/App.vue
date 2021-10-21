<template>
  <div id="app">
    <h3>Cadastro </h3>
    <hr>
    <input type="text" placeholder="nome" v-model = "nomeField">
    <input type="email" placeholder="email" v-model = "emailField">
    <input type="number" placeholder="idade" v-model = "idadeField">
    <button @click="cadastrarUsuario"> CADASTRAR </button>
    <hr>
   <h1> Guia Clientes </h1>

   
  <div v-for = "(cliente,index) in clientes" :key = "cliente.id">
  <h3>{{index + 1}} </h3>
  <Client :cliente="cliente"/>
  <hr>
  </div>

  </div>
</template>

<script>
import Client from './components/Client.vue'

export default {
  name: 'App',
  data(){
    return {
      nomeField : '',
      emailField : '',
      idadeField : '',
      clientes : [
        {
          id : 1,
          nome : "Victor Hugo",
          email: "victorhugofny@gmail.com",
          idade: 22
        }
      ]
    }
  },
  components:{
    Client,
    //Produto
  },
  methods: {
    cadastrarUsuario: function(){
      this.clientes.push({nome: this.nomeField, email: this.emailField, idade: this.idadeField, id: Date.now()})
      this.nomeField = '';
      this.emailField = '';
      this.idadeField = '';

    }
  }
}
</script>

<style>

</style>
