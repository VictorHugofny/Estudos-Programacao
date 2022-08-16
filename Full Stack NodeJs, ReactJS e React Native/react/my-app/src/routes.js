import { BrowserRouter, Routes, route, Route} from 'react-router-dom';

import Home from './views/Home';
import Sobre from './views/Sobre';

function RoutesAPP(){
    return(
        <BrowserRouter>
            <Routes>
                <Route path="/" element= { <Home/>}/>
                <Route path="/sobre" element= { <Sobre/>}/>
            </Routes>
        </BrowserRouter>
    )
}

export default RoutesAPP;