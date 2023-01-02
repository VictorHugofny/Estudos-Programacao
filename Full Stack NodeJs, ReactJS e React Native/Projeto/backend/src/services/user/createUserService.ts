interface UserRequest{
    name: string;
    email: string;
    password: string;
}

class CreateUserService{
    async execute({email, name, password}:UserRequest){
        return {certo: email}
    }
}

export {CreateUserService}