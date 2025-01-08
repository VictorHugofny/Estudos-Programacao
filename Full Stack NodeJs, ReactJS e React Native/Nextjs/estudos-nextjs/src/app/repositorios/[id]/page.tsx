interface PageDetailProps{
    params:{
        id: string;
    }
}

export default function RepositorioId({params}: PageDetailProps){
    return (
        <div>
            <h1>Pagina de detalhes do repositorio {params.id}</h1>
        </div>
    )
}