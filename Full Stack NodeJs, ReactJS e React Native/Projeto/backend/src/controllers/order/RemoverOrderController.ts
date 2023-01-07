import { Response, Request } from "express";
import {RemoverOrderService} from "../../services/order/RemoverOrderService";

class RemoverOrderController{
    async handle(req: Request, res: Response){
        const order_id = req.query.order_id as string;

        const RemoverOrder = new RemoverOrderService();

        const order = await RemoverOrder.execute({
            order_id
        });

        return res.json(order);

    }
}

export {RemoverOrderController}