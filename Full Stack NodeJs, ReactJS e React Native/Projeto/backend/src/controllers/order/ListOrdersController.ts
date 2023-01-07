import { Request, Response } from "express";
import {ListOrdersService} from '../../services/order/ListOrdersService';

class ListOrdersController{
    async handle(req: Request, res: Response){

        const listOrders = new ListOrdersService();
        const order = await listOrders.execute()

        return res.json(order);
    }
}

export{ListOrdersController}