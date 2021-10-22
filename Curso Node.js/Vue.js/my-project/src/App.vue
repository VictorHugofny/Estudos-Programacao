<template>
  <div id="app">
    <h3>Cadastro </h3>
    <hr>
    <small id = "nomeerro" v-show = "erroNome"> NOME INVALIDO </small> <br>
    <input type="text" placeholder="nome" v-model = "nomeField">
    <input type="email" placeholder="email" v-model = "emailField">
    <input type="number" placeholder="idade" v-model = "idadeField">
    <button class="button is-black" @click="cadastrarUsuario"> CADASTRAR </button>


    
    <hr>
   <h1> Guia Clientes </h1>

   
  <div v-for = "(cliente,index) in clientes" :key = "cliente.id">
  <h3>{{index + 1}} </h3>
  <Client :cliente="cliente" @Delete = "deletarUsuario($event)"/>
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
      erroNome: false,
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
      if (this.nomeField == "" || this.nomeField == " " || this.nomeField.length <3){
        this.erroNome = true
      }else{
        this.clientes.push({nome: this.nomeField, email: this.emailField, idade: this.idadeField, id: Date.now()})
        this.nomeField = '';
        this.emailField = '';
        this.idadeField = '';
        this.erroNome = false
      }
      
    },
    deletarUsuario: function($event){
      console.log($event.idcliente)
      let id = $event.idcliente

      let novoArray = this.clientes.filter(cliente => cliente.id != id) //filtrar array com base no id
      this.clientes = novoArray
    }
    
  },
 
  }
</script>

<style>
  #nomeerro{
    color: red;
  }
</style>
