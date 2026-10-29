#include "snapshot29_0433f7af8f6d.h"

extern s32 func_800937C0(void);
extern void func_8008D6E0(s32);
extern s32 __osSetFpcCsr(s32);
extern s32 func_8008DB50(s32,s32*);
extern s32 func_8008DBE0(s32,s32);
extern void osWritebackDCache(s32,s32);
extern void osInvalICache(s32,s32);
extern void func_8008C4F0(void);
extern void func_8008CFF0(s32,u32*);
extern u64 func_8009A2B0(u64,u64);
extern void func_80091920(void*,s32);
typedef struct {u32 a,b,c,d;} VectorCode;
extern VectorCode func_8008AE70;
extern VectorCode D_80000000;
extern s32 D_80000300,D_8000030C,D_8000031C;
extern u64 D_800A1CC0;
extern s32 D_800A1CC8;
extern u8 D_800C02AE[];
void func_8008BB80(void) {
 s32 sp10; u32 sp14=0;
 *(s32*)(D_800C02AE+0x7cda)=1; func_8008D6E0(func_800937C0()|0x20000000);
 __osSetFpcCsr(0x1000800);
 do {} while(func_8008DB50(0x1fc007fc,&sp10));
 do {} while(func_8008DBE0(0x1fc007fc,sp10|8));
 *(VectorCode*)0x80000000=func_8008AE70;
 *(VectorCode*)0x80000080=func_8008AE70;
 *(VectorCode*)0x80000100=func_8008AE70;
 *(VectorCode*)0x80000180=func_8008AE70;
 osWritebackDCache(0x80000000,0x190); osInvalICache(0x80000000,0x190);
 func_8008C4F0(); func_8008CFF0(4,&sp14);
 sp14 &= 0xfffffff0; if(sp14) D_800A1CC0=sp14; D_800A1CC0=func_8009A2B0(D_800A1CC0*3,4); if(!D_8000030C) func_80091920(&D_8000031C,0x40);
 if(!D_80000300) D_800A1CC8=0x2f5b2d2;
 else if(D_80000300==2) D_800A1CC8=0x2e6025c;
 else D_800A1CC8=0x2e6d354;
}
