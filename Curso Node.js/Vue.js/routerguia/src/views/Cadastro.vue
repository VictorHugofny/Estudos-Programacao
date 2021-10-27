<template>
    <div>
        <input type="text" name="email" id="email" placeholder = "email">
        <input type="text" name="nome" id="nome" placeholder="nome">
        <button>Teste</button>
        <h4> {{parametroDaRota}} </h4>
        <router-view/>
    </div>
</template>

<script>
export default {
    created() {
        //console.log(this.$route.params.dado) //pegar o parametro da pagina 
        //this.parametroDaRota = this.$route.params.dado
    },
    data(){
        return{
            parametroDaRota : "Nada"
        }
    }
}
</script>