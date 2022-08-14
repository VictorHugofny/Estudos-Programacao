import Nome from './componentes/nome';
import { useState } from 'react'

function App(){
  const [input, setInput] = useState('');
  const [tarefas, settarefas] = useState([]);


  const [user, setUser] = useState({});

  function registrar(e){
    //evitar que atualize
    e.preventDefault();

    alert('Usuario registrado com sucesso')
    settarefas([...tarefas,input])
    setInput('')
  }

  return(
   <div>
      <form onSubmit = {registrar}>
        <label>Nome da tarefa:</label> <br/>
        <input placeholder='digite uma tareff' 
        value={input} onChange = {(e)=> setInput(e.target.value)}/> <br/>

       
        
        <br/>
        <button type="submit">Registrar</button>
      </form>

      <br/><br/>
   
   
    <ul>
      {tarefas.map( obj => (
        <li key={tarefas}> {obj} </li> 
        ))}
    </ul>
   </div>

  );
}

export default App;

