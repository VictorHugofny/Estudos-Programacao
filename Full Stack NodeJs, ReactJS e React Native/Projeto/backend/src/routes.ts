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
import {RemoverOrderController} from './controllers/order/RemoverOrderController';
import {AddItemController} from './controllers/order/AddItemController'
import {RemoveItemController} from './controllers/order/RemoveItemController';
import {SendOrderController} from './controllers/order/SendOrderController';
import {ListOrdersController} from './controllers/order/ListOrdersController';
import {DetailOrderController} from "./controllers/order/DetailOrderController";
import {FinishOrderController} from './controllers/order/FinishOrderController';

//middle de autenticação do usuario logado
import {isAuntheticated} from './middlewares/isAuntheticated';

//configuração da geração de imagens
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
router.delete('/order', isAuntheticated, new RemoverOrderController().handle)
router.post('/order/add', isAuntheticated, new AddItemController().handle)
router.delete('/order/remove', isAuntheticated, new RemoveItemController().handle)

router.put('/order/send', isAuntheticated, new SendOrderController().handle)
router.get('/orders', isAuntheticated, new ListOrdersController().handle)
router.get('/order/detail', isAuntheticated, new DetailOrderController().handle)
router.put('/order/finish', isAuntheticated, new FinishOrderController().handle)

export {router};
