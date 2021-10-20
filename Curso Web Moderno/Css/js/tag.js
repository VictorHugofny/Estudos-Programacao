const color ={
    p:'#388e3c',
    div:'#1565c0',
    span:'#988e3c',
    section:'#988e3c',
    ul:'#1565c0',
    ol:'#988e3c',
    header:'#1565c0',
    nav:'#988e3c',
    main:'#1565c0',
    footer:'#988e3c',
    form:'#1565c0',
    body:'#988e3c',
    padrao:"616161",
    
    get(tag){
        return this[tag] ? this[tag] : this.padrao
    }
}
// MOSTRA TODAS AS TAGS USADAS DO HTML NA TELA
document.querySelectorAll('.tag').forEach(elemento => {
    const tagName = elemento.tagName.toLowerCase();

    elemento.style.borderColor = color.get(tagName);

    if(!elemento.classList.contains('nolabel')){
        const label = document.createElement('label');
        label.style.backgroundColor = color.get(tagName);
        label.innerHTML=tagName;
        elemento.insertBefore(label, elemento.childNodes[0]);
    }
});
