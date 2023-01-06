import {Request, Response} from 'express';

import {CreateProductService} from "../../services/product/CreateProductService";

class CreateProductControler{
    async handle(req: Request, res: Response){
        const {name, price, description, category_id} = req.body;

        let banner = "";
        const createProductService = new CreateProductService();

        const product = createProductService.execute({
            name, price, description, category_id, banner
        });

        return res.json(product);
    }
}

export {CreateProductControler}