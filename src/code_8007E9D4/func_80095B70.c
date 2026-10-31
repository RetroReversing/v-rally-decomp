#include "snapshot31_verified.h"

typedef struct { s32 unk0; s32 unk4; } R8;
typedef struct { s16 unk0; s16 pad2; s32 pad4; R8 *unk8; s32 unkC; } V;
extern s32 D_80000300; extern u8 D_800A39D0[]; extern s16 D_800A39D2; extern s32 D_800A39D4; extern s16 D_800A3A02; extern s32 D_800A3A04; extern V *D_800A3A08; extern u8 *D_800A3A30; extern V *D_800A3A34; extern u8 D_800A3A40[]; extern u8 D_800A3A90[]; extern u8 D_800A3AE0[]; extern volatile u32 D_A4400000; extern s32 func_800911B0(void); extern void func_80091920(void *, s32);
void func_80095B70() {
 func_80091920(D_800A39D0,0x60); D_800A3A30=D_800A39D0; D_800A3A34=(V*)(D_800A39D0+0x30); D_800A3A02=1; D_800A39D2=1; D_800A3A04=0x80000000; D_800A39D4=0x80000000;
 if(D_80000300==0) D_800A3A08=(V*)D_800A3AE0; else if(D_80000300==2) D_800A3A08=(V*)D_800A3A40; else D_800A3A08=(V*)D_800A3A90;
 D_800A3A34->unk0=0x20; D_800A3A34->unkC=D_800A3A34->unk8->unk4;
 if((u32)*(volatile u32*)0xA4400010>=0xB) do{}while((u32)*(volatile u32*)0xA4400010>=0xB);
 *(volatile u32 *)0xA4400000=0;
 return (void)func_800911B0();
}