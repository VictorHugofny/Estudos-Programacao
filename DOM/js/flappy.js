function novoElemento (tagName, classname){ //criar elemento com tag e definir sua classe
    const elem = document.createElement(tagName)
    elem.className = classname;
    return elem
}

function Barreira (reversa = false){ //criar as barreiras
    this.elemento = novoElemento('div','barreira')

    const borda = novoElemento('div','borda')
    const corpo = novoElemento('div','corpo')
    this.elemento.appendChild(reversa ? corpo : borda)
    this.elemento.appendChild(reversa ? borda : corpo)

    this.setAltura = altura => corpo.style.height = `${altura}px`
}

function ParDeBarreiras(altura,abertura,x){
    this.elemento = novoElemento('div','par-de-barreiras')

    this.superior = new Barreira(true)
    this.inferior = new Barreira(false)

    this.elemento.appendChild(this.superior.elemento)
    this.elemento.appendChild(this.inferior.elemento)

    this.sortearAbertura = () => {
        const alturaSuperior = Math.random() * (altura-abertura)
        const alturaInferior = altura - abertura - alturaSuperior
        this.superior.setAltura(alturaSuperior)
        this.inferior.setAltura(alturaInferior)
    }

    this.getX = () => parseInt(this.elemento.style.left.split('px')[0]) // retorna o inteiro
    this.setX = x => this.elemento.style.left = `${x}px`
    this.getLargura = () => this.elemento.clientWidth

    this.sortearAbertura()
    this.setX(x)
}

const b = new ParDeBarreiras(700,200,400)
document.querySelector(`[wm-flappy]`).appendChild(b.elemento)


