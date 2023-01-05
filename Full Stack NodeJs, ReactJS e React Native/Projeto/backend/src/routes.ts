import {Router } from 'express';
import {CreateUserController} from './controllers/user/createuserControler';
import { AuthUserController } from './controllers/user/authUserController';
import {DetailUserController} from './controllers/user/detailUserController';

import {isAuntheticated} from './middlewares/isAuntheticated';

const router = Router();

//rotas user
router.post('/users', new CreateUserController().handle)
router.post('/session', new AuthUserController().handle)
router.get('/my', isAuntheticated, new DetailUserController().handle)
export {router};
