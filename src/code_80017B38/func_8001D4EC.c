#include "common.h"

s32 func_80098180(void *,void *); extern u8 D_8009D468[],D_8009D474[]; extern u8 D_800AE850[];
#define D_800B7278 (*(void **)((u32)D_800AE850+0x8A28))
void func_8001D4EC(u8 *arg0){s32 s0;u32 s1;s32 s2;u16 *tbl;u8 *new_var,*glob;s32 pad[2];
if(D_800B7278){*(s32*)((u8*)D_800B7278+0xA0)=0;s1=0;if(*(u32*)(arg0+0x44)){new_var=D_8009D468;s2=0x4C;outer:{s0=0;while(func_80098180(arg0+s2,(void*)((s1+s0)*14+(u32)new_var)))s0++;glob=D_800B7278;tbl=(u16*)(D_8009D474+(s1+s0)*14);*(s32*)(glob+0xA0)|=*tbl;s1++;s2+=0x4C;}if(s1<*(u32*)(arg0+0x44))goto outer;}}}
