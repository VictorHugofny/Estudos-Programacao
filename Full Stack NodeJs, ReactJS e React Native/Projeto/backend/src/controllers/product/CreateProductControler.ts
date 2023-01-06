import {Request, Response} from 'express';

import {CreateProductService} from "../../services/product/CreateProductService";

class CreateProductControler{
    async handle(req: Request, res: Response){
        const {name, price, description, category_id} = req.body;

        const createProductService = new CreateProductService();

        if(!req.file){
            throw new Error("error upload file");
        }else{
            //renomeando arquivo
            const {filename: banner} = req.file;
    
            const product = await createProductService.execute({
                name, price, description, category_id, banner
            });
    
            return res.json(product);
        }
        
    }
}

export {CreateProductControler}