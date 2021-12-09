let subtmitButton = document.querySelector('#app form button')
let zipcodeField = document.querySelector('#app form input')
let content = document.querySelector('#app main')

subtmitButton.addEventListener('click', run)

function run (event){
    event.preventDefault()

   let zipcode = zipcodeField.value

   //remover espaços ou pontos do CEP
   zipcode = zipcode.replace(' ','')
   zipcode = zipcode.replace('.','')
   zipcode = zipcode.trim()

   axios.get('https://viacep.com.br/ws/' + zipcode + '/json/')
   .then(function(response){

    if(response.data.erro){
        throw new Error('CEP INVALIDO')  
    }
        content.innerHTML = ''  
        console.log(response.data)
        createLine(response.data.logradouro)
        createLine(response.data.localidade)
        createLine(response.data.ddd + ' ' + response.data.uf)
   })
   .catch(function(erro){
        content.innerHTML = ''
        createLine('Ops algo deu errado')
   })
}

function createLine(parametro){
    let line = document.createElement('p')
    var text = document.createTextNode(parametro)
    line.appendChild(text)
    content.appendChild(line)
}