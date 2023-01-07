import { Response, Request } from "express";
import {DetaildOrderService} from "../../services/order/DetailOrderService";

class DetailOrderController{
    async handle(req: Request, res: Response){
        const order_id = req.query.order_id as string;

        const detailOrder = new DetaildOrderService();
        const order = await detailOrder.execute({order_id})

        return res.json(order);
    }
}

export{DetailOrderController}