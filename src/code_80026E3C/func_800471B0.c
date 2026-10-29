#include "snapshot29_0433f7af8f6d.h"

extern u8 *D_800C7F84; extern s32 D_800A02C8;
s32 func_800056FC(s32); void *func_80006008(s32);
void func_80006014(); void func_800061FC(s32,s32);
void func_800068C0(s32,s32,s16,s16,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
s32 func_800070CC(s32); void func_800071EC(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
s32 func_80010BFC(s32,void*,void*); s32 func_8001BD1C(void); void func_8002E0B8(void*,s32);
void func_800471B0(void){
u16 x[12];u8 m[64];s32 s0,s1,s2;u32 *p;u8 *o; s32 *e;
s2=func_800056FC(*(s32 *)(D_800C7F84+0x178));
o=*(u8 **)(D_800C7F84+0x24);e=*(s32 **)(o+0x9C);
if(!e[14])return;
x[0]=e[0];
x[1]=(*(s32 * volatile *)(o+0x9C))[1];
x[2]=(*(s32 * volatile *)(o+0x9C))[2];
x[3]=(*(s32 * volatile *)(o+0x9C))[3];
x[4]=(*(s32 * volatile *)(o+0x9C))[4];
x[5]=(*(s32 * volatile *)(o+0x9C))[5];
x[6]=(*(s32 * volatile *)(o+0x9C))[6];
x[7]=(*(s32 * volatile *)(o+0x9C))[7];
x[8]=(*(s32 * volatile *)(o+0x9C))[8];
x[9]=(*(s32 * volatile *)(o+0x9C))[9];
x[10]=(*(s32 * volatile *)(o+0x9C))[10];
x[11]=(*(s32 * volatile *)(o+0x9C))[11];
s1=**(s32 **)(o+0x8C);
p=func_80006008(s2);
{ u32 *g=p; p+=2; g[0]=0x06000000;g[1]=(u32)&D_800A02C8; }
{ u32 *g=p; p+=2; g[0]=0xFA000000;g[1]=0xC8C8C800; }
func_80006014(s2,p);
func_8002E0B8(m,s1+16);s1=func_8001BD1C();
if((func_80010BFC(s1,D_800C7F84+0x38,m)&255)!=1)return;
func_800061FC(s2,s1);s0=func_800070CC(s2)&65535;
func_800068C0(s2,s0,(s16)(x[0]+1),(s16)(x[1]+1),(s16)(x[2]+4000),(s16)(x[3]+1),(s16)(x[4]+60),(s16)(x[5]+4000),(s16)(x[6]+60),(s16)(x[7]+60),(s16)(x[8]+4000),(s16)(x[9]+70),(s16)(x[10]+1),(s16)(x[11]+4000));
func_800071EC(s2,s0,255,0,0,255,0,0,0,0,255,0,0,255);
}
