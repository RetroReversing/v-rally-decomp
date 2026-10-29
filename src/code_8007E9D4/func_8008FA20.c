#include "snapshot29_0433f7af8f6d.h"

typedef struct { s16 unk0; u8 unk2,unk3; } S_func_8008FA20_arg1;
extern u8 D_800AE850[],D_800C02AE[];
extern s32 func_80090DC0(); extern s32 osRecvMesg(s32,void*,s32);
s32 func_8008FA20(s32 arg0,S_func_8008FA20_arg1 *arg1) {
u8 buf[8]; u8 *p; s32 i,s0; u8 *s1; s32 *q;
for(i=15,q=(s32*)(D_800AE850+0x869c);i>=0;i--) *q--=0;
q=(s32*)(D_800AE850+0x869c); *q=1;
p=(u8*)q-0x3c; for(i=3;i>=0;i--) *p++=0;
buf[0]=255;buf[1]=1;buf[2]=3;buf[3]=0;buf[4]=255;buf[5]=255;buf[6]=255;buf[7]=255;
__builtin_memcpy(p,buf,8); s1=D_800AE850+0x8660;p[8]=254;
func_80090DC0(1,s1); osRecvMesg(arg0,0,1); D_800C02AE[0x3272]=254;
s0=func_80090DC0(0,s1);osRecvMesg(arg0,0,1);
if(s0==0){p=s1;for(i=3;i>=0;i--)*p++=0;__builtin_memcpy(buf,p,8);
arg1->unk3=(buf[2]&0xc0)>>4;arg1->unk0=buf[4]|(buf[5]<<8);arg1->unk2=buf[6];return arg1->unk3 ? arg1->unk3:0;}
return s0;
}
