import axios, {AxiosError} from "axios"
import {parseCookies} from 'nookies'

export function setupAPIClient(ctx = undefined){
    let cookies = parseCookies(ctx);

    const api = axios.create({
        baseURL: "http://localhost:3000",
        headers:{
            Autorization: `Bearer ${cookies['@nextauth.token']}`
        }
    })

    api.interceptors.response.use(response =>{
        return response;
    },(error: AxiosError)=>{
        if(error.response.status === 401){
            //qualquer erro 401 não autorizado
            if(typeof window !== undefined){
                //chamar a função para deslogar usuario
            }else{
                return Promise.reject
            }
        }
    })
}