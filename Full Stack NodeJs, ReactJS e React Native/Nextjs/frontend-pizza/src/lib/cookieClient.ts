import {getCookie} from 'cookies-next'

export async function getCookiClient(){
    const token = getCookie("session");
    return token || null;
}