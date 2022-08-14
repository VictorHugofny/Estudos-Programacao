
//https://sujeitoprogramador.com/rn-api/?api=posts

import React, {useEffect, useState} from 'react';
import './style.css'

function App(){

  const [nutri, setNutri] = useState([]);
  
  //receber dados da API
  function loadApi(){
    let url = 'https://sujeitoprogramador.com/rn-api/?api=posts'
    fetch(url)
    //recebendo os dados da api e convertendo em json
    .then((r)=> r.json())
    .then((json)=>{
    //jogando os dados em um array
      setNutri(json);
    })
  }

  //consumindo API
  useEffect(()=>{
    loadApi()
  }, []);

  return(
   <div className='container'>
    <header>
      <strong>React nutri</strong>
    </header>

    {nutri.map((obj)=>{
      return(
        <article key={obj.id} className="post">
          <h1>{obj.categoria}</h1>
          <strong className='titulo'>{obj.titulo}</strong>
          <img src = {obj.capa}></img>
          <p className='subtitulo'>{obj.subtitulo}</p>
          <a className='botao'> acessar </a>
          
        </article>
      )
    })}
   </div>

  );
}

export default App;

