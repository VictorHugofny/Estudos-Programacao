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
const myform = document.querySelector("#my-form")
const nameInput = document.querySelector("#name")
const emailInput = document.querySelector("#email")
const body = document.querySelector('body')
const items = document.querySelector(".items")

submitButton.addEventListener('click',function(e){
    e.preventDefault(); //impedir comportamento padrao
    console.log(e)
    console.log("clicked")

    const nameValue = nameInput.value
    const emailValue = emailInput.value

    if (nameValue === "" || emailValue === ""){
        return alert("Por favor escreva tudo")
    }

    myform.style.background = "red"

    //modificando valores no html
    items.firstElementChild.textContent = nameValue
    items.children[1].textContent = emailValue

    body.style.background = "blue"
})