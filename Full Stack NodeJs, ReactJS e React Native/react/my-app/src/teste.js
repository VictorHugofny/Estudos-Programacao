import Nome from './componentes/nome';
import { useState, useEffect } from 'react'

//para usar javascript é dentro do {}

function App(){
  const [input, setInput] = useState('');
  const [tarefas, settarefas] = useState([]);

  //roda toda vez que carrega o componente
  useEffect(()=>{
    const tarefasStorage = localStorage.getItem('@tarefa');

    if(tarefasStorage){
      settarefas(JSON.parse(tarefasStorage))
    }
  },[]);

  //update
  //roda toda vez que carrega o componente especifico ou é modificado
  useEffect(()=>{
    //somente adicioanr um valor, se o array não estiver vazio
    if(tarefas.length > 0){
    //usar local estorage para salvar no navegador
    localStorage.setItem('@tarefa', JSON.stringify(tarefas))
  }
  }, [tarefas])
  //toda vez que tarefas for alterado roda a função


  function registrar(e){
    //evitar que atualize
    e.preventDefault();

    // alert('Usuario registrado com sucesso')
    //pega todas as tarefas + o ultimo input escrito
    settarefas([...tarefas,input])
    //limpar o input
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
        <li key={obj}> {obj} </li> 
        ))}
    </ul>
   </div>

  );
}

export default App;

