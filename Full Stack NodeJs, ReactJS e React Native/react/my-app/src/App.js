import Nome from './componentes/nome';
import { useState, useEffect } from 'react'

function App(){
  const [input, setInput] = useState('');
  const [tarefas, settarefas] = useState(['teste']);

  useEffect(()=>{
    const tarefasStorage = localStorage.getItem('@tarefa');

    if(tarefasStorage){
      settarefas(JSON.parse(tarefasStorage))
    }
  },[]);

  //roda toda vez que carrega o componente
  // useEffect(()=>{
  //   //usar local estorage para salvar no navegador
  //   localStorage.setItem('@tarefa', JSON.stringify(tarefas))
  // }, [tarefas])
  //toda vez que tarefas for alterado roda a função


  function registrar(e){
    //evitar que atualize
    e.preventDefault();

    // alert('Usuario registrado com sucesso')
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

