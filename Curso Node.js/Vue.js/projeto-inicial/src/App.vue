<template>
  <div id="app">
   <h1> Guia Clientes </h1>
   <input type="text" v-model = "nomeDoVictor">
   <Client :nome = "nomeDoVictor" email ="victorhugofny@gmail.com" idade = "20"/>
   <Client nome = "Victor" email ="dualviciobrs@gmail.com" idade = "22"/>
   <Client nome ="Funny" email ="hugoheadshot@gmail.com" idade = "20"/>
   <Client nome = "Teste" email ="testando@gmail.com" idade = "22"/>
   <Produto/>
  </div>
</template>

<script>
import Client from './components/Client.vue'
import Produto from './components/Produto.vue'

export default {
  name: 'App',
  data(){
    return {
      nomeDoVictor : "Victor Hugo"
    }
  },
  components:{
    Client,
    Produto
  }
}
</script>

<style>

</style>
