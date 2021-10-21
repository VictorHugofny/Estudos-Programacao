<template>
<div id = "cliente">
  <h4> Nome: {{nome}} </h4>
  <hr>
  <p>Email: {{email}} </p>
  <hr>
  <p>Idade: {{idade}} </p>
</div>
</template>

<script>
export default {
    data(){
        return {
          
        }
    },
    props:{
        nome: String,
        email: String,
        idade : Number
    }
}
</script>

<style>
#cliente{
    color: rgb(0, 0, 0);
    background-color: rgb(221, 219, 219);
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