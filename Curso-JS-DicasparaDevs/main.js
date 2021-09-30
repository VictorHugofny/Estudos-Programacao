//const addusertext = document.querySelector('#add-user') //getElementById
//const myform = document.querySelector('.container #my-form')

//console.log(addusertext)
//console.log(myform)

//addusertext.textContent = "testando" //formas de trocar o conteudo
//addusertext.innerHTML = "Adicionar Usuario" // modificar o conteudo


//selecionar multiplos elementos
//const allitens = document.querySelector(".items")
//console.log(allitens)

//remover elementos
//allitens.remove();
//allitens.firstElementChild.remove()
//allitens.lastElementChild.remove()

//allitens.children[0].textContent = "Item um"
//allitens.lastElementChild.innerHTML = "<h1> Testando </h1>"

//const button1 = document.querySelector('.btn')
//button1.style.background = 'red';
//button1.style.color = "black";

const submitButton = document.querySelector("#submit-button")
const nameInput = document.querySelector("#name")
const emailInput = document.querySelector("#email")

submitButton.addEventListener('click',function(e){
    e.preventDefault(); //impedir comportamento padrao
    console.log(e)
    console.log("clicked")
    console.log(nameInput.value)
})