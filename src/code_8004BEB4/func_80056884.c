#include "common.h"

extern u8 D_800AE850[];
void func_80008CB8(void *, u16, u8, u8, s32);
void func_80008DBC(void *, u16, u8, u8);
void func_80008E80(void *, void *, s32, u16 *);
void func_80009164(void *, s32, u8);
void func_800098C4(void *, u16, u16, u16, s32);
void func_80009C90(void *, s32);
typedef struct { u8 w[4]; s16 h; } Elem6;
void func_80056884(void *arg0, u8 *arg1, Elem6 *arg2) {
 u16 out[4]; Elem6 e[4]; u8 *v1;
 *((u32*)((u8*)arg0+0x84))=(*((u32*)((u8*)arg0+0x84))&0xFCFFFFFF)|0x1000000;
 v1=*((u8**)(D_800AE850+0x237C))+*((u16*)(arg1+0x20))*0x14;
 func_80009164(arg0, **((s32**)(*((u8**)(v1+0x10))+4)), v1[0xF]);
 func_80009C90(arg0,0);
 e[0]=arg2[*((u16*)(arg1+0x16))]; e[1]=arg2[*((u16*)(arg1+0x14))];
 e[2]=arg2[*((u16*)(arg1+0x10))]; e[3]=arg2[*((u16*)(arg1+0x12))];
 func_80008E80(arg0,e,4,out);
 func_80008CB8(arg0,out[0],arg1[0xC],arg1[0xD],arg1[0xE]);
 func_80008CB8(arg0,out[1],arg1[8],arg1[9],arg1[0xA]);
 func_80008CB8(arg0,out[2],arg1[0],arg1[1],arg1[2]);
 func_80008CB8(arg0,out[3],arg1[4],arg1[5],arg1[6]);
 func_80008DBC(arg0,out[0],arg1[0x1E],arg1[0x1F]);
 func_80008DBC(arg0,out[1],arg1[0x1C],arg1[0x1D]);
 func_80008DBC(arg0,out[2],arg1[0x18],arg1[0x19]);
 func_80008DBC(arg0,out[3],arg1[0x1A],arg1[0x1B]);
 func_800098C4(arg0,out[3],out[2],out[1],out[0]);
}
