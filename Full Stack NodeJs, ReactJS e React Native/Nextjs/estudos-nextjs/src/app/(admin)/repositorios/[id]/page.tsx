interface PageDetailProps{
    params:{
        id: string;
    }
}


async function delayFetch(url: string, time: number){
    await new Promise(resolve => setTimeout(resolve, time))
    const response = await fetch(url);
    return response.json();
  }
  
  //Criando uma requisição de API para simular dados
  async function getData(id: string){
    const response = await fetch("https://api.github.com/users/victorhugofny/repos/" + id);
    return response.json();
  }

export default async function RepositorioId({params}: PageDetailProps){
    const data = await getData(params.id);
    return (
        <div>
            <h1>Pagina de detalhes do repositorio {params.id}</h1>
        </div>
    )
}