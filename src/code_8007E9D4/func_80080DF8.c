#include "snapshot31_verified.h"

extern s32 D_800A19B0;
extern volatile s32 D_800B5B40;
extern s32 D_800C5BB0[], D_800C8090, D_800C80A8;
extern u8 D_800AE850[], D_800C02AE[];
extern s32 D_800C782C;
s32 func_8007EE9C(void *arg0) ;







s32 func_80080DF8(u8 *a) {
 u8 *a1; unsigned int new_var; u8 **link; u8 *v1;
 if(!a[-10]) return (*(s32(**)(u8*))(D_800C02AE+0x7dda))(a);
 a-=0x14; if(!a[10]) return 1;
 v1=*(u8**)a; a[10]=0; a[11]=0; a1=*(u8**)(a+4);
 if(!v1[10]) {v1=*(u8**)v1; *(u8**)a=v1; *(u8**)(v1+4)=a;}
 if(a1 && !a1[10]) {link=(u8**)(v1+4); a=a1; *(u8**)a1=v1; *link=a; a1=*(u8**)(a+4);}
 {s32 result=1; if(a1) return result; v1=(u8*)(s32)*(s8*)(v1+8); if((s32)v1==result) a[-9]=0; return 1;}
}
s32 func_800869B8(s32 arg0) ;








void func_80086A34(s32 arg0) ;
