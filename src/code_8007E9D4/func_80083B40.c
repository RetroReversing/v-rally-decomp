#include "common.h"

extern u8 D_800AE850, D_800C02AE;
extern s32 func_800839C4(s32 *);
extern s32 func_800821A4(void *, s32, s32);
s32 func_80083B40(void) {
 s32 msg, ret; u32 *p; u32 v, max=0;
 { u32 *q=(u32 *)(&D_800C02AE+0x310A); p=q-5; *q=0; }
 *(u32 *)(&D_800C02AE+0x3112)=0;
 *(u32 *)(&D_800C02AE+0x310E)=0;
 do {
 *p=0;
 ret=func_800839C4(&msg);
 if(ret) return ret;
 v=*p;
 if(max<v) max=v;
 } while(msg==0);
 func_800821A4(&D_800AE850+0x8AE8,*(s32 *)(&D_800C02AE+0x310A),0);
 return 0;
}
