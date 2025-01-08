"use client"
import Image from 'next/image';
import {useState} from 'react';

import '@/components/OwnerRepo/index.css'
interface OwnerRepoProps{
    avatar_url: string;
    name: string;
}

export function OwnerRepo({avatar_url, name}: OwnerRepoProps){

    const [show, setShow] = useState(false);

    return(
        <div>
            <button onClick = {()=> setShow(!show)}>{show ? "Ocultar nome" : "Mostrar nome"}</button>
            {show && (
            
                <div className='Projetos'>
                    <Image src={avatar_url} alt={name} width={34} height={34} />
                    <strong>{name}</strong>
                </div>
                
            )}
        </div>
    )
}