var button = document.querySelector('#app button')

button.addEventListener('click',function(){
    var xhr = new XMLHttpRequest()

    xhr.open('GET','https://api.github.com/users')
    xhr.send()

    xhr.onreadystatechange = function () {
        if(xhr.readyState === 4){
        let data = JSON.parse(xhr.responseText)
        console.log(data[0].login)
        }
    }
})
