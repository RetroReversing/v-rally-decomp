#include "common.h"

u8 *func_80098290(u8 *dst,u8 *src) {
 u32 w; u8 c; u8 *d=dst,*s=src; 
 if (((u32)(s-d)&3)!=0) {
   c=*s++; *d++=c;
   if(c) do { c=*s++; *d++=c; } while(c);
   return dst;
 }
 if ((u32)d&3) {
   do { c=*s++; *d++=c; if(!c) return dst; } while((u32)d&3);
 }
 for (;;) {
   w=*(u32*)s; s+=4;
   if (!(w&0xFF000000)) { *d=0; return dst; }
   if (!(w&0x00FF0000)) { *(u16*)d=(u16)(w>>16); return dst; }
   if (!(w&0x0000FF00)) {
      u16 h = w >> 16; *(u16*)d=h; d[2]=0; return dst;
   }
   *(u32*)d=w; d+=4;
   if (!(w&0xFF)) return dst;
 }
}
