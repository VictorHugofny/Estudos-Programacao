//poderia pegar os dados assim {aluno, idade}
function Nome(props){
    return(
      <div>
        <h1>"Bem vindo" {props.aluno} idade: {props.idade}</h1>
      </div>
    );
  }

  export default Nome;