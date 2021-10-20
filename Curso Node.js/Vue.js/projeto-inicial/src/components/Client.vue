<template>
<div id = "cliente">
  <h2 id = "nome">{{nome}}</h2>
  <h2>Descrição do cliente: {{descricao}}</h2>
  <h2>Cliente aqui! </h2>
  {{nome}}
</div>
</template>

<script>
export default {
    data(){
        return {
            nome : "Victor Hugo",
            numero : "",
            email : "",
            idade : 0,
            descricao : 'bla bla bla bla bla'
        }
    }
}
</script>

<style>
#cliente{
    color: rgb(0, 0, 0);
    background-color: rgb(192, 192, 192);
    max-width: 600px;
    height: 230px;
}

#nome{
    color: rgb(150, 251, 251);
}
</style>