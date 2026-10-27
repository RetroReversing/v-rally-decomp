#include "common.h"

s32 func_800308EC(u8 *arg0, s32 arg1) {
s32 n; u32 t4,t5,a1,a2; u8 *new_var; u32 a3; u8 t0,t1; u32 t2,t3,v1; u32 pad[2];
t3=0;t0=0;t1=0;a3=0;
n=*(u16*)(arg0+0x88)-1;
if(n!=0) {
t2=*(u32*)(arg0+0x4C); a1=arg1&0xFFFF; t5=n; t4=t2+2; v1=t2;
do { a2=v1-2;new_var=arg0;
if(a2<t4) { do {
if(a2<v1) { if(((u16*)*(u8**)(arg0+0x70))[a2+a3*(*(u16*)(arg0+0x8A)-1)]==a1) t0++; }
else if(((u16*)*(u8**)(arg0+0x70))[a2+a3*(*(u16*)(arg0+0x8A)-1)]==a1) {do {t1++;}while(0);}
n=*(u32*)(arg0+0x4C); v1=n; a2++;
} while(a2<v1+2);}
a3++;v1=t2;
}while(a3<t5);
}
if(t0>=2||t1>=2) {t3=1;if(!(t1<t0)){t0=(-(t0<t1)&3)|2;t3=t0;}}
return t3;
}
