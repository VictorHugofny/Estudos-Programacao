import prismaClient from '../../prisma';
import {compare} from 'bcryptjs';
import {sign} from 'jsonwebtoken';

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

        //gerar um token jwt e devolver os dados do usuario com id, name, email
        //se deu tudo certo, gerar token
        const token = sign(
        //payload dados passados para o frontend    
        {
            name: user.name,
            email: user.email
        },
        process.env.JWT_SECRET,
        {
            subject: user.id,
            expiresIn: "30d"
        }
        )
        return {
            id: user.id,
            name: user.name,
            email: user.email,
            token: token
        }
    }
}

export {AuthUserService};