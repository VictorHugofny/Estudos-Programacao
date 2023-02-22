import Head from 'next/head';
import Image from 'next/image'
import logoImg from '../../public/logo.svg';
import styles from '../styles/home.module.scss'

export default function Home() {
  return (
    <>
    <Head>
      <title>Sujeito Pizza - Login</title>
    </Head>
    <div className={styles.containerCenter}>
      <Image src={logoImg} alt="sujeito pizza"></Image>

      <div className={styles.login}>
        <form>
          <input type={"text"}></input>
        </form>
      </div>
    </div>
    </>
  )
}
