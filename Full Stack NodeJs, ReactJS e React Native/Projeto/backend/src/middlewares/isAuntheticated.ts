import {Response, Request, NextFunction} from 'express';
import {verify} from 'jsonwebtoken'

interface Payload{
    sub: string;
}

//intervenção antes da rota
export function isAuntheticated(req: Request, res: Response, next: NextFunction){
    
    //receber o token
    const authToken = req.headers.authorization;

    //não autorizado
    if(!authToken){
        return res.status(401).end();
    }

    const [, token] = authToken.split(" ");
    
    //se receber vai validar
    try{
        //validar se o token existe no banco   .
        const { sub } = verify(
            token,
            process.env.JWT_SECRET
        ) as Payload;
        
        return next(sub);

    }catch(err){
        return res.status(401).end();
    }

    
}