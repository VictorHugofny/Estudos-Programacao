import prismaClient from '../../prisma';
import {hash} from 'bcryptjs';
interface UserRequest{
    name: string;
    email: string;
    password: string;
}

class CreateUserService{
    async execute({email, name, password}:UserRequest){
        
        //validações dos dados
        if(!email){
            throw new Error("Email incorreto!");
        }

        //Criptografando a senha
        const passwordHash = await hash(password, 8);

        //validando se existe email ja salvo
        const userAlreadyExist = await prismaClient.user.findFirst({
            where:{
                email: email
            }
        })

        if(userAlreadyExist){
            throw new Error("email ja existe");
        }

        //cadastrando no banco
        const user = await prismaClient.user.create({
            data:{
                name: name,
                email: email,
                password: passwordHash
            },
            select:{
                id: true,
                email: true,
                name: true
            }
        })
        return user;
    }
}

export {CreateUserService}