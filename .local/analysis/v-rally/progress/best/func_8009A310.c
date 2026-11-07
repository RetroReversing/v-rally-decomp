u32 func_8009A310(u32 arg0,u32 arg1) {
 u32 v0,v1,a0,a1,a2,a3,t9;
 v1=arg0; a0=arg0>>20; a0&=0x7ff;
 if(a0<0x3ff) return 0;
 a0-=0x3ff; if(a0>=0x40) return 0x80000000;
 a2=v1; a3=arg1; v0=v1&0xfffff; v0|=0x100000;
 if(a0>=0x34) {
   a0-=0x34;
   if(a0==0) goto done;
   v1=a0; a0-=0x20; a0=0-a0; a1=a3; a1>>=a0; a0=v1; v0<<=a0; v0|=a1; a3<<=a0;
 } else {
   a0=0x34-a0; v1=a0; a0-=0x20;
   if(a0<0) { a0=0-a0; a1=v0; a1<<=a0; a0=v1; a3>>=a0; a3|=a1; v0>>=a0; }
   else { a3=v0; v0=0; a3>>=a0; }
 }
 done:
 if(a2&0x80000000) { v1=-1; a3^=v1; v0^=v1; a3++; t9=(a3<1); v0+=t9; }
 return v0;
}
