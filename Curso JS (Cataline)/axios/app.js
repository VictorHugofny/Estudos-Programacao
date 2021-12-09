let button = document.querySelector('#app button')

button.addEventListener('click',function(){
    axios.get('https://api.github.com/users')
    .then(function(response){

        console.log(response.data)
    })
    .catch(function(erro){
        console.log(erro)
    })
    .finally(function(){
        console.log("finalizado")
    })
})




