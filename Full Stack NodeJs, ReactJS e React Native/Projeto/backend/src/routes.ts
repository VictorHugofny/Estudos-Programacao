import {Router } from 'express';
import {CreateUserController} from './controllers/user/createuserControler';
import { AuthUserController } from './controllers/user/authUserController';
const router = Router();

//rotas user
router.post('/users', new CreateUserController().handle)
router.post('/session', new AuthUserController().handle)
export {router};
