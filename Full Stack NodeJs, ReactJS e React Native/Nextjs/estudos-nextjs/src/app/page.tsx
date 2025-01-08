import {OwnerRepo} from '@/components/OwnerRepo'

interface DataProps{
  id: number;
  name: string;
  full_name: string;
  owner: {
    login:string;
    id: number;
    avatar_url:string;
    url: string;
  };
}

async function delayFetch(url: string, time: number){
  await new Promise(resolve => setTimeout(resolve, time))
  const response = await fetch(url);
  return response.json();
}

//Criando uma requisição de API para simular dados
async function getData(){
  // const response = await fetch("https://api.github.com/users/victorhugofny/repos");
  // return response.json();
  const data = await delayFetch("https://api.github.com/users/victorhugofny/repos", 0)
  return data;
}

//Criando um componentew que roda do lado do servidor
//trazendo os dados sem a necessidade de um load do lado do usuario
export default async function Home(){
  const data: DataProps[] = await getData();
  
  return(
    <div>
      <h1> pagina Home </h1>
      <span>Seja bem vindo a pagina home</span>

      <h3>Meus projetos</h3>
      {data.map((item)=>(
          <div key={item.id}>
              <strong>Repositorio: </strong> <a>{item.name}</a>
              <br/>
              <OwnerRepo
              avatar_url = {item.owner.avatar_url}
              name = {item.owner.login}
              />
          </div>

      ))
      }
    </div>

  
  )
}