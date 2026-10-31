void func_800535F4(void *arg0) {
 u8 *p=arg0; u32 *t0,*a3,*a1,*a2,*t3; s32 t1,i; u8 t2; u32 temp[4]; t3=temp+4; p[0x3b]=p[0xb]; t2=0;
 do { t2=0; t1=3; do {
  u32 off=(t1&255)<<4;
  t0=(u32*)(p+off); off-=16; a3=(u32*)(p+off);
  if (*t0 < *a3) {
   t2=1;
   if (((u32)temp < (u32)(a3+4)) & ((u32)a3 < (u32)temp)) { a2=a3+4; a1=temp+4; for(i=4;i!=0;--i){a2--;a1--;*a1=*a2;} }
   else { a2=a3; a1=temp; for(i=4;i!=0;--i){*a1++=*a2++;} }
   a1=t0+4;
   if (((u32)a3 < (u32)a1) & ((u32)t0 < (u32)a3)) { a2=a1; a1=a3+4; for(i=4;i!=0;--i){a2--;a1--;*a1=*a2;} }
   else { a2=t0; a1=a3; for(i=4;i!=0;--i){*a1++=*a2++;} }
   if (((u32)t0 < (u32)t3) & ((u32)temp < (u32)t0)) { a1=t0+4; a2=t3; for(i=4;i!=0;--i){a2--;a1--;*a1=*a2;} }
   else { a2=temp; a1=t0; for(i=4;i!=0;--i){*a1++=*a2++;} }
  }
  t1--;
 } while ((t1&255)!=0); } while ((t2&255)!=0);
}
