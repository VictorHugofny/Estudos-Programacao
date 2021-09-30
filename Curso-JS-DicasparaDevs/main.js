const nameInput = document.querySelector('#name')
const emailInput = document.querySelector('#email')
const sutmitbottom = document.querySelector('#submit-button')

const errorMessage = document.querySelector('.msg')

const items = document.querySelector('.items')

sutmitbottom.addEventListener('click',(e) => {
    e.preventDefault()

    const nameValue = nameInput.value
    const emailValue = emailInput.value
    if (nameValue === "" || emailValue === ""){
        errorMessage.textContent = "ERRO !!!"
        errorMessage.classList = 'error' //adicionando uma classe
        
        setTimeout(() => { // dps de 3 segundos
            errorMessage.remove();
        }, 3000);
        
        return
    }

    const li = document.createElement('li') //criando uma tag "li"
    li.classList = "item"
    li.innerHTML = `Nome: ${nameValue} <br/> email: ${emailValue}`

    items.appendChild(li) //adicionar como filho 

    nameInput.value = '';
    emailValue.value = '';
})