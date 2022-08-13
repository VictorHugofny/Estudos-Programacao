import Nome from './componentes/nome';
import { useState } from 'react'

function App(){

  const [aluno, setAluno] = useState('Programador');

  function mudarNome(nome){
    setAluno(nome)
  }

  return(
    <div>
      <h1>"teste"</h1>
      <h1>teste </h1>
      <h2>Ola: {aluno} </h2>
      <button onClick= {() => mudarNome('hugo')}> Mudar nome</button>
      <Nome aluno="hugo" idade = "22"/>
    </div>
  );
}

export default App;

