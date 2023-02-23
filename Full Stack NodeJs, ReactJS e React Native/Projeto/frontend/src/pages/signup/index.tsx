import { useState } from 'react';

import Head from 'next/head';
import Image from 'next/image'
import logoImg from '../../../public/logo.svg';
import styles from '../../styles/home.module.scss'

import {Input} from '../../components/ui/Input';
import {Button} from '../../components/ui/Button';

import Link from 'next/link';

export default function Signup() {
  return (
    <>
    <Head>
      <title>Faça seu cadastro</title>
    </Head>
    <div className={styles.containerCenter}>
      <Image src={logoImg} alt="sujeito pizza"></Image>

      <h1>Criando sua Conta</h1>

      <div className={styles.login}>
        <form>
          <Input placeholder='Nome' type="text"></Input>
          <Input placeholder='Email' type="text"></Input>
          <Input placeholder='Senha' type="password"></Input>
          <Button type="submit" loading={false}> Cadastrar </Button>
        </form>
      <Link className={styles.text} href='/'>
        Já possui uma conta? faça login!
      </Link>
      </div>
    </div>
    </>
  )
}
