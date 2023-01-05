import prismaClient from '../../prisma';
import {compare} from 'bcryptjs';

interface AuthRequest{
    email: string,
    password: string;
}
class AuthUserService{
    async execute({email, password}: AuthRequest){

        //verificar se o email existe
        const user = await prismaClient.user.findFirst({
            where:{
                email: email
            }
        })

        if(!email || !user){
            throw new Error("Email incorreto")
        }

        //comparando a senha criptografada com a inserida
        const passawordMatch = await compare(password, user.password)

        if(!passawordMatch){
            throw new Error("Senha incorreta!")
        }

        return {ok: true}
    }
}

export {AuthUserService};