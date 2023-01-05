import {Response, Request} from "express";
import {DetaildUserService} from '../../services/user/detailUserService';

class DetailUserController{
    async handle(req: Request, res: Response){ 
        const detailUserService = new DetaildUserService();

        const user = await detailUserService.execute();

        return res.json(user);
    }
}

export {DetailUserController}