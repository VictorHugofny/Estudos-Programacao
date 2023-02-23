import Head from 'next/head';
import Image from 'next/image'
import logoImg from '../../public/logo.svg';
import styles from '../styles/home.module.scss'

import {Input} from '../components/ui/Input';
import {Button} from '../components/ui/Button';

import Link from 'next/link';

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
          <Input placeholder='Email' type="text"></Input>
          <Input placeholder='Senha' type="password"></Input>
          <Button type="submit" loading={false}> Acessar </Button>
        </form>
      <Link className={styles.text} href='/signup'>
        Não possui uma conta? cadastre-se
      </Link>
      </div>
    </div>
    </>
  )
}
