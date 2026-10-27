#include "common.h"

extern s32 D_800B7070; extern u32 D_8009D540; extern u8 D_800A54B0[]; extern u8 D_800C02AE[];
extern void *func_800592D0(s32); extern s32 func_80059618(void *,u8,u8,u8,s32); extern s32 func_800596F4(void *,s16,s16,s32 *); extern s32 func_80099DF8(s32 *,u8 *,s32);
void func_8005E6AC(void) {
 s32 sp18; u8 *p; u8 *v1; s32 v0; void *s0; u32 quotient;
 p=*(u8 **)(D_800C02AE+0x325A);
 v1=*(u8 **)(p+0x10)+*(s16 *)(p+2)*20;
 if(D_800B7070>0){v0=D_800B7070-1; D_800B7070=v0; if(v0==0){*(s32 *)(v1+0x10)=1; *(s16 *)(p+4)=0;}}
 else *(s32 *)(v1+0x10)=1;
 quotient=D_800B7070/D_8009D540;

 func_80099DF8(&sp18,D_800A54B0,quotient&0xffff);
 s0=func_800592D0(5);
 func_80059618(s0,*((u8*)s0+0xB),*((u8*)s0+0xC),*((u8*)s0+0xD),*((u8*)s0+0xE));
 func_800596F4(s0,*(s16*)((u8*)s0+6),*(s16*)((u8*)s0+8),&sp18);
}
