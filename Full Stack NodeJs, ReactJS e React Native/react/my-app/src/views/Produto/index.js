import { useParams } from 'react-router-dom'

function Produto(){
    {/* Pegando o parametro passado na URL */}
    const { id } = useParams();

    return(
        <h1>Meu produto é {id}</h1>
    )
}

export default Produto;