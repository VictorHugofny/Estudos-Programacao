const inputElement = document.querySelector("input");
const buttonElement = document.querySelector("form button");
const ulElement = document.querySelector('ul')


buttonElement.onclick = e => { // e = evento
    e.preventDefault();

    if(inputElement !== ""){ // não adicionar itens vazios

    const textElement = document.createElement("span")
    textElement.innerHTML = inputElement.value
    
    const buttonElementdentro = document.createElement("button")
    buttonElementdentro.innerHTML = "REMOVER"
    
    const liElement = document.createElement('li') //adicionando elementos na lista
    liElement.appendChild(textElement)
    liElement.appendChild(buttonElementdentro);


    
    ulElement.appendChild(liElement);
    inputElement.value = "";  }
    //console.log(inputElement.value) // pegando valor do input


}

