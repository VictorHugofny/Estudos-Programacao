import {Router } from 'express';
import {CreateUserController} from './controllers/user/createuserControler';
import { AuthUserController } from './controllers/user/authUserController';
import {DetailUserController} from './controllers/user/detailUserController';
import {CreateCategoryController} from './controllers/category/CreateCategoryController';
import {ListCategoryController} from './controllers/category/ListCategoryController'

import {isAuntheticated} from './middlewares/isAuntheticated';

const router = Router();

//rotas user
router.post('/users', new CreateUserController().handle)

router.post('/session', new AuthUserController().handle)

router.get('/my', isAuntheticated, new DetailUserController().handle)

//rotas category
router.post('/category', isAuntheticated, new CreateCategoryController().handle)
router.get('/category', isAuntheticated, new ListCategoryController().handle)

//rotas product


export {router};
