#include "snapshot29_0433f7af8f6d.h"

typedef struct { s32 a,b; s16 c; s8 d; } S_D800A54A4;
typedef void (*Fn)(void);
extern u8 D_800C02AE[]; extern S_D800A54A4 *D_800A1468; extern S_D800A54A4 D_800A54A4;
extern s32 func_8005A2F4(s32); extern s32 func_8005A474(u8,s32,void*); extern void func_80062B70(void),func_80064E48(void),func_80070A34(void);
s32 func_8005E38C(void){s32 temp_s0; S_D800A54A4 *temp_a2; s32 temp_s1;
temp_s0=D_800C02AE[0x5D56]; func_8005A2F4(0); temp_a2=D_800A1468;temp_s1=3;
*(void **)((u8*)temp_a2+0x1F4)=(u8*)temp_a2+0x204;
if(temp_s0==temp_s1)__builtin_memcpy((S_D800A54A4 *)((u8*)temp_a2+0x204),&D_800A54A4,11);
func_8005A474(temp_s0,0,temp_a2);
if(temp_s0==2)*(Fn *)((u8*)D_800A1468+0x288)=func_80062B70;
else if(temp_s0==1)*(Fn *)((u8*)D_800A1468+0x288)=func_80064E48;
else if(temp_s0==temp_s1)*(Fn *)((u8*)D_800A1468+0x288)=func_80070A34;
return 0;}
