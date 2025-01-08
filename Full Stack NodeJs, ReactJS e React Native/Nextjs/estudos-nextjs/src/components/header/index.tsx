import Link from 'next/link';
import styles from '@/components/header/header.module.css';
export function Header(){
    return(
        <header className={styles.header}>
            <h1>Header 12345</h1>
            <Link href='/'>Home</Link> <br></br>
            <Link href='/contatos'>Contatos</Link><br></br>
            <Link href='/dashboard'>Dashboard</Link>
        </header>
    )
}