<template>
  <div id="app">
   <h1> Guia Clientes </h1>
   <Client/>
   <Produto/>
  </div>
</template>

<script>
import Client from './components/Client.vue'
import Produto from './components/Produto.vue'

export default {
  name: 'App',
  components:{
    Client,
    Produto
  }
}
</script>

<style>

</style>
