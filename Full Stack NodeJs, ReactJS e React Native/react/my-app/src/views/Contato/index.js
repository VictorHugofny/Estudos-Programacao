import { Link } from 'react-router-dom'

function Contato(){
    return(
    
     <div className='container'>
        <Link to='/'>Home</Link> <br/>
        <Link to="/sobre">Outras</Link>
        <h1>Contato da empresa</h1>
     </div>
  
    );
  }
  
  export default Contato;
  
  