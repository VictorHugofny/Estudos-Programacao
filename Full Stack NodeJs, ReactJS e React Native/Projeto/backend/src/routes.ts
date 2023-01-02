import {Router } from 'express';
import {CreateUserController} from './controllers/user/createuserControler'
const router = Router();

//rotas user
router.post('/users', new CreateUserController().handle)

export {router};
