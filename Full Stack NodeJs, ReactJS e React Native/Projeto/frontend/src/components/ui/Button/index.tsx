import styles from "./style.module.scss";
import {ReactNode, ButtonHTMLAttributes} from 'react';
import {FaSpinner} from 'react-icons/fa';

//atributos que espero receber do botão
interface ButtonProps extends ButtonHTMLAttributes<HTMLButtonElement>{
    loading?: boolean,
    children: ReactNode
}
export function Button({loading, children, ...rest}:ButtonProps){
    return(
        <button className={styles.button} disabled={loading} {...rest}>
            {loading ? (
                <FaSpinner color="white" size={16}></FaSpinner>
            ): (
                <a className={styles.buttonText}>{children}</a>
            )}
            
        </button>
    )
}