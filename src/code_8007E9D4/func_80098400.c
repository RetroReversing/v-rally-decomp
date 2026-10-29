#include "snapshot29_0433f7af8f6d.h"

s32 func_80098400(u8 *a,u8 *b,u32 n) {
 s32 d; register u32 t; register u32 w,x;
 if(((u32)(a-b)&3)==0) goto aligned;
bytes:
 while(--n != (u32)-1) { w=*a++; d=w-*b++; if((d!=0)|(w==0))return d; }
 return 0;
aligned:
 while((u32)a&3) { if(--n==(u32)-1)return 0; w=*a++;d=w-*b++;if((d!=0)|(w==0))return d; }
 t=n; t>>=2; t-=1;
 if(t!=(u32)-1)do {
 w=*(u32*)a; x=*(u32*)b; a+=4;b+=4;d=w-x;
 if(d) {
 if(!(w&0xff000000))d=0xff000000;
 else if(!(w&0xff0000))d=0xffff0000;
 else if(!(w&0xff00))d=0xffffff00;
 else return d;
 return (w&d)-(x&d);
 }
 if(!(w<<24)||!(w&0xff00)||!(w&0xff0000)||!(w&0xff000000))return d;
 }while(--t!=-1);
 n&=3;goto bytes;
}
