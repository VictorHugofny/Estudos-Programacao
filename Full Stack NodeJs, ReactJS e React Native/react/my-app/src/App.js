import Nome from './componentes/nome';
import { useState } from 'react'

function App(){
  const [nome, setNome] = useState('');
  const [email, setEmail] = useState('');
  const [idade, setIdade] = useState('');

  const [user, setUser] = useState({});

  function registrar(e){
    //evitar que atualize
    e.preventDefault();

    alert('Usuario registrado com sucesso')
    setUser({
      nome: nome,
      idade: idade,
      email: email
    })
  }

  return(
   <div>
      <form onSubmit = {registrar}>
        <label>Nome:</label> <br/>
        <input placeholder='digite seu nome' 
        value={nome} onChange = {(e)=> setNome(e.target.value)}/> <br/>

        <label>idade:</label> <br/>
        <input placeholder='digite sua idade' 
        value={idade} onChange = {(e)=> setIdade(e.target.value)}/> <br/>

        <label>email:</label> <br/>
        <input placeholder='digite seu email' 
        value={email} onChange = {(e)=> setEmail(e.target.value)}/> <br/>
        
        <br/>
        <button type="submit">Registrar</button>
      </form>

      <br/><br/>
   
   
    <div>
      <span> Bem vindo: {user.nome} de idade {user.idade} de email {user.email}</span>
    </div>
   </div>

  );
}

export default App;

