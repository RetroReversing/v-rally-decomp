#include "common.h"

extern void *D_800A11B0;
extern void *func_80022668(s32,s32);
extern s32 func_8004C98C(s32,void *,s16 *,s32,s32,s32,s32,s32,s32);
#define NODE_Q(t) (*(void ***)((u8 *)*(void ***)((u8 *)(t)+0xC)+4))
void func_8004D1A8(s32 arg0,u32 arg1,f32 arg2,s32 arg3,u8 arg4) {
s16 sp28[4]; void *temp_v0; u8 temp_s0; s32 temp_s2;
temp_s0=arg4; temp_s2=arg3;
temp_v0=func_80022668((s32)D_800A11B0,arg1&0xFFFF);
if(temp_v0!=NULL) {
sp28[0]=(s16)(s32)(-(s32)*(u16 *)((u8 *)*NODE_Q(temp_v0)+6)*arg2*0.5f);
sp28[1]=(s16)(s32)(-(s32)*(u16 *)((u8 *)*NODE_Q(temp_v0)+8)*arg2*0.5f);
sp28[2]=(s16)(s32)((f32)*(u16 *)((u8 *)*NODE_Q(temp_v0)+6)*arg2);
sp28[3]=(s16)(s32)((f32)*(u16 *)((u8 *)*NODE_Q(temp_v0)+8)*arg2);
func_8004C98C(arg0,*NODE_Q(temp_v0),sp28,arg3&0xFF,temp_s0,temp_s0,temp_s0,temp_s0,0);
}
}
