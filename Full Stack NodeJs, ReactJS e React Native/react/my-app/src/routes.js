import { BrowserRouter, Routes, route, Route} from 'react-router-dom';

import Home from './views/Home';
import Sobre from './views/Sobre';
import Contato from './views/Contato'

function RoutesAPP(){
    return(
        <BrowserRouter>
            <Routes>
                <Route path="/" element= { <Home/>}/>
                <Route path="/sobre" element= { <Sobre/>}/>
                <Route path="/contato" element= { <Contato/>}/>
            </Routes>
        </BrowserRouter>
    )
}

export default RoutesAPP;