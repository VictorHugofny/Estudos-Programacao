import styles from "./../page.module.scss";
import logoImg from "../../../public/logo.svg";
import Image from 'next/image'
import Link from 'next/link'

export default function Signup(){
    return(
        <div  className={styles.containerCenter}>
        <Image src={logoImg} alt = "Logo da Pizzaria"/>

        <section className={styles.login}>
          <h1>Criando sua conta</h1>
          <form>
          <input
              type='text'
              required
              name = 'name'
              placeholder="Digite seu nome"
              className={styles.input}
            />
            <input
              type='email'
              required
              name = 'email'
              placeholder="Digite seu email"
              className={styles.input}
            />
            <input
              type='password'
              required
              name = 'password'
              placeholder="Digite sua senha"
              className={styles.input}
            />
            <button type = 'submit' className={styles.button}>
              Cadastrar
            </button>

            <Link href="/" className="styles.text">
              Ja possui uma conta? Faça o login
            </Link>
           
          </form>
        </section>
    </div>
    )
}