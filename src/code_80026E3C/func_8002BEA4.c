#include "common.h"

typedef struct { s32 val; s32 pad[3]; } BeEnt;
extern BeEnt D_800B0BE8[]; extern u8 D_800AFB38[];
s32 func_8001FEE8(void *); void func_8002C044(void *); void func_8002FBD4(void *,s32,s32); void func_80097E30(void *,s32,s32);
#define OBJ_IDX(o) (*(s32 *)*(u8 **)((o)+0x48))
void func_8002BEA4(void **arg0){u8 *s0; s32 v,d; u16 cnt; u8 *a1; u32 p;
s0=arg0[0]; if(*(s32*)0x800b6b00==0)func_80097E30(D_800AFB38,0,4); if(!s0)return;
do{func_8002C044(s0); if(OBJ_IDX(s0)<4){v=func_8001FEE8(s0); d=D_800B0BE8[OBJ_IDX(s0)].val; d-=v; if(d<0)d=-d;
d = d < 4; if(!d){p=*(u16 *)(*(u8 **)(s0+0x8c)+0x336); if(p>=4)func_8002FBD4(s0,255,3); else if(p)func_8002FBD4(s0,220,2);}
D_800B0BE8[OBJ_IDX(s0)].val=v; a1=*(u8 **)(s0+0x80); cnt=(~*(u32 *)(a1+0x310))>>31; if(*(s32 *)(a1+0x314)>=0)cnt++; if(*(s32 *)(a1+0x318)>=0)cnt++; if(*(s32 *)(a1+0x31c)>=0)cnt++;
if(cnt>=3)D_800AFB38[OBJ_IDX(s0)]=1; else if(D_800AFB38[OBJ_IDX(s0)]==1){D_800AFB38[OBJ_IDX(s0)]=0;func_8002FBD4(s0,255,2);}} s0=*(u8 **)(s0+4);}while(s0);}
