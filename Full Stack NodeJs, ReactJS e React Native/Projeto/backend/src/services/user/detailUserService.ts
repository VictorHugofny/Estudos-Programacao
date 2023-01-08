import prismaClient from "../../prisma";

class DetaildUserService{
    async execute(user_id: string){
        
        //fazer busca pelo usuario no banco, de acordo com o id
        const user = await prismaClient.user.findFirst({
            where:{
                id: user_id
            },
            //filtrar dados que serão devolvidos
            select:{
                id: true,
                name: true,
                email: true
            }
        })
        
        return user;
    }
}

export {DetaildUserService}