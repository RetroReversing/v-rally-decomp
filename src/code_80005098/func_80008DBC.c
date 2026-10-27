#include "common.h"

void func_80008DBC(char *arg0,u16 arg1,s32 arg2,s32 arg3){
s32 idx; s32 *gfx; u32 w1;
idx=arg1&0xffff;
if(*(u16 *)(*(char **)(arg0+0x70)+idx*16+6)&2){
*(u16 *)(*(char **)(arg0+0x70)+idx*16+6)&=0xfffd;
*(u16 *)(*(char **)(arg0+0x70)+idx*16+8)=(u32)(arg2**(u16 *)(arg0+0x8a))>>2;
*(u16 *)(*(char **)(arg0+0x70)+idx*16+10)=(u32)(arg3**(u16 *)(arg0+0x88))>>2;
return;
}
w1=(arg2**(u16 *)(arg0+0x8a))<<13; w1+=(u32)(arg3**(u16 *)(arg0+0x88))>>3;
gfx=*(s32 **)(arg0+0x14);
*(s32 **)(arg0+0x14)=gfx+2;
gfx[0]=0x02140000|((idx&31)<<1);
gfx[1]=w1;
}
