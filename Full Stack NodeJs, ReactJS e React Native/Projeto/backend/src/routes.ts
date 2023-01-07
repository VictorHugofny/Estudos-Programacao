import {Router } from 'express';
import multer from 'multer';
import {CreateUserController} from './controllers/user/createuserControler';
import { AuthUserController } from './controllers/user/authUserController';
import {DetailUserController} from './controllers/user/detailUserController';
import {CreateCategoryController} from './controllers/category/CreateCategoryController';
import {ListCategoryController} from './controllers/category/ListCategoryController';
import {CreateProductControler} from './controllers/product/CreateProductControler';
import {ListByCategoryController} from './controllers/product/ListByCategoryController';
import {CreateOrderController} from './controllers/order/CreateOrderController';

import {isAuntheticated} from './middlewares/isAuntheticated';

import uploadConfig from './config/multer';

const router = Router();

//salvar e puxar imagens do banco
const upload = multer(uploadConfig.upload("./tmp"));

//rotas user
router.post('/users', new CreateUserController().handle)

router.post('/session', new AuthUserController().handle)

router.get('/my', isAuntheticated, new DetailUserController().handle)

//rotas category
router.post('/category', isAuntheticated, new CreateCategoryController().handle)
router.get('/category', isAuntheticated, new ListCategoryController().handle)

//rotas product
router.post('/product', isAuntheticated, upload.single('file'), new CreateProductControler().handle)
router.get('/category/product', isAuntheticated, new ListByCategoryController().handle)

//rotas order
router.post('/order', isAuntheticated, new CreateOrderController().handle)

export {router};
