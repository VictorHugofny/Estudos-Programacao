import styles from "./page.module.scss";
import logoImg from "../../public/logo.svg";
import Image from 'next/image'
import Link from 'next/link'

export default function Home() {
  return (
    <div  className={styles.containerCenter}>
        <Image src={logoImg} alt = "Logo da Pizzaria"/>

        <section className={styles.login}>
          <form>
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
              Acessar
            </button>

            <Link href="/signup" className="styles.text">
              Não possui um conta? cadastra-se
            </Link>
           
          </form>
        </section>
    </div>

  );
}
