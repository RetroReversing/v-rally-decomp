#include "snapshot29_0433f7af8f6d.h"

extern s32 func_8006786C(s32, s32); extern s32 func_80098180(u8 *, u8 *); extern s32 D_8009D540; extern u8 *D_800A1468; extern u8 *D_800C35A0; extern s16 *D_800C3508; extern s16 D_800C6F12;
s32 func_800676A0(void){u8 *p=D_800A1468+0x280; u8 i; if(*(s8*)p>0){ p[1]++; if((s8)p[1]==0x1a) p[1]=0; } else if(*(s8*)p<0){ p[1]--; if((s8)p[1]<0) p[1]=0x19; }
p[0]=0; (p+p[2])[3]=p[1]+0x41;
if(p[2]==2){ i=0; do{ if(func_80098180(D_800C35A0+(((((i<<2)+i))<<3)+0x44),p+3)==0) break; i++; }while(i<4);
if(i==4){ D_800C3508[1]=0; func_8006786C(0,0);} else D_800C6F12=D_8009D540*2; return 0;}
p[2]++; return 0;}
