import {NextRequest, NextResponse} from  'next/server';
import {getCookieServer} from "@/lib/cookieServer";

export async function middleware(req: NextRequest){
    const {pathname} = req.nextUrl;

    if(pathname.startsWith("/_next") || pathname === "/"){
        return NextResponse.next();
    }

    const token = await getCookieServer();
    
    if(pathname.startsWith("/dashboard")){
        if(!token){
            return NextResponse.redirect(new URL("/",req.url))
        }
    }


    
}