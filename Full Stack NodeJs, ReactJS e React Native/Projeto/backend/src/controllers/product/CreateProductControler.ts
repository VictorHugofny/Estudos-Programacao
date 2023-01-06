import {Request, Response} from 'express';

import {CreateProductService} from "../../services/product/CreateProductService";

class CreateProductControler{
    async handle(req: Request, res: Response){
        const {name, price, description, category_id} = req.body;

        const createProductService = new CreateProductService();

        if(!req.file){
            throw new Error("error upload file");
        }else{
            const {filename} = req.file;
            console.log(filename)
            const product = await createProductService.execute({
                name, price, description, category_id, banner:"TESTE"
            });
    
            return res.json(product);
        }
        
    }
}

export {CreateProductControler}