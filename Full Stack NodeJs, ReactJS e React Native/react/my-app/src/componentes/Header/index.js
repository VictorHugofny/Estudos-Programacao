import { Link } from 'react-router-dom';
import './style.css';

function Header(){
    
    return(
        <header>
            <Link to='/'><h2>React estudos</h2></Link>
            
            <div class ='navbar'>
                <Link to='/'>Home</Link>
                <Link to="/sobre">Outras</Link>
                <Link to="/contato">Contato</Link>
            </div>
        </header>
)}

export default Header;