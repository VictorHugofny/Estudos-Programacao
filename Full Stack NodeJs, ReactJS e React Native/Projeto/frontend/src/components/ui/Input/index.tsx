import { InputHTMLAttributes, TextareaHTMLAttributes } from "react";
import styles from "./style.module.scss";

interface InputProps extends InputHTMLAttributes<HTMLInputElement> {}
interface TextAreaProps extends TextareaHTMLAttributes<HTMLTextAreaElement> {}

//...rest para receber as propriedades direto da view como o placeholder, focus..
export function Input({ ...rest }: InputProps) {
  return <input className={styles.input} {...rest} />;
}

export function TextArea({ ...rest }: TextAreaProps) {
  return <textarea className={styles.input} {...rest}/>;
}
