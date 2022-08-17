import { BrowserRouter, Routes, route, Route} from 'react-router-dom';

import Home from './views/Home';
import Sobre from './views/Sobre';
import Contato from './views/Contato';
import Erro from './views/Erro'
import Produto from './views/Produto'

import Header from './componentes/Header';
function RoutesAPP(){
    return(
        <BrowserRouter>
        <Header/>
            <Routes>
                <Route path="/" element= { <Home/>}/>
                <Route path="/sobre" element= { <Sobre/>}/>
                <Route path="/contato" element= { <Contato/>}/>
                <Route path="/produto/:id" element= { <Produto/>}/>
                {/* Criando rota para tela de erro */}
                <Route path = "*" element={<Erro/>}/>
            </Routes>
        </BrowserRouter>
    )
}

export default RoutesAPP;