import express, {Request, Response, NextFunction} from 'express';
import 'express-async-errors';
import cors from 'cors';
import {router} from './routes';
import path from 'path'

const app = express();

app.use(express.json());
//Deixando livre para qualquer IP
app.use(cors());
app.use(router);

//rota para retornar imagem do banco de dados
app.use(
    '/files',
    express.static(path.resolve(__dirname, ".." , "tmp"))
)

app.use((err: Error, req: Request, res: Response, next: NextFunction)=>{
    if(err instanceof Error){
        //se for uma instancia do tipo erro
        return res.status(400).json({
            error: err.message
        })
    }
    
    return res.status(500).json({
        status: 'error',
        message: 'Internal server error.'
    })

})

app.listen(3000, ()=> {
    console.log("online")
})