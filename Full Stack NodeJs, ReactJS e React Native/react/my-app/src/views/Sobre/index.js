import { Link} from 'react-router-dom'

function Sobre(){
    return(
        <div>
            <Link to='/'>Home</Link> <br/>
            <Link to="/contato">Contato</Link>
            <h1>Sobre</h1>
        </div>
  
    );
  }
  
  export default Sobre;
  
  