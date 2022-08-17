import { Link} from 'react-router-dom'

function Home(){
    return(
    
     <div className='container'>
        <Link to="/sobre">Sobre</Link><br/>
        <Link to="/contato">Contato</Link>
        <h1>pagina home</h1>
     </div>
  
    );
  }
  
  export default Home;
  
  